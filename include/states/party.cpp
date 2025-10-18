#include <memory>
#include <states/party.h>
#include <party_elements/field.h>
#include "../game_objects/button.h"
#include "../game_objects/switch.h"
#include "../game_objects/static_texture.h"

struct ExitAction : public Button::Action
{
    ExitAction(bool& exited)
        : exited(exited)
    {}

    void operator()() override
    {
        exited = true;
    }

    bool& exited;
};

Party::Party(Application app)
    : app(app)
    , exited(false)
{
    InitGameObjects();
}


void Party::HandleEvents(GameState& state)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_EVENT_QUIT:
            {
                state = GameState::Exit;
                return;
            };
            case SDL_EVENT_KEY_DOWN:
            {
                if (event.key.key == SDLK_ESCAPE)
                {
                    state = GameState::Menu;
                    return;
                }
            };
            case SDL_EVENT_WINDOW_RESIZED:
            {
                app.AdjustWindowSize();
            };
            default: break;
        }

        for (auto& obj : gameObjects)
        {
            obj->Update(event);
        }
    }
}

void Party::Run(GameState& state)
{
    while (state == GameState::Party)
    {
        SDL_RenderClear(app.Renderer());

        HandleEvents(state);

        for (auto& obj : gameObjects)
        {
            obj->Draw();
        }

        SDL_RenderPresent(app.Renderer());

        if (exited)
        {
            state = GameState::Menu;
            exited = false;
        }

        app.ControlFPS();
    }
}

void Party::InitGameObjects()
{
    auto field = std::make_unique<Field>(app);

    auto menuButton = std::make_unique<Button>(
        "assets/menu_default.png",
        "assets/menu_selected.png",
        SDL_FRect{0.4, 0.15, 3, 1.125},
        app
    );
    menuButton->SetAction(std::make_unique<ExitAction>(exited));

    auto tip = std::make_unique<StaticTexture>(
        "assets/tip.png",
        SDL_FRect{0.4, 1.425, 3, 4.875},
        app
    );

    auto skipButton = std::make_unique<Button>(
        "assets/skip_default.png",
        "assets/skip_selected.png",
        SDL_FRect{0.4, 6.45, 3, 1.125},
        app
    );

    auto dropSwitch = std::make_unique<Switch>(
        "assets/drop_default.png",
        "assets/drop_selected.png",
        SDL_FRect{0.4, 7.725, 3, 1.125},
        app
    );

    auto card1 = std::make_unique<StaticTexture>(
        "assets/Card_5_1.png",
        SDL_FRect{3.8, 6.6, 1.5, 2.25},
        app
    );
    auto card2 = std::make_unique<StaticTexture>(
        "assets/Card_5_2.png",
        SDL_FRect{5.35, 6.6, 1.5, 2.25},
        app
    );
    auto card3 = std::make_unique<StaticTexture>(
        "assets/Card_5_3.png",
        SDL_FRect{6.9, 6.6, 1.5, 2.25},
        app
    );
    auto card4 = std::make_unique<StaticTexture>(
        "assets/Card_5_0.png",
        SDL_FRect{8.45, 6.6, 1.5, 2.25},
        app
    );

    gameObjects.push_back(std::move(card1));
    gameObjects.push_back(std::move(card2));
    gameObjects.push_back(std::move(card3));
    gameObjects.push_back(std::move(card4));
    gameObjects.push_back(std::move(menuButton));
    gameObjects.push_back(std::move(skipButton));
    gameObjects.push_back(std::move(dropSwitch));
    gameObjects.push_back(std::move(tip));
    gameObjects.push_back(std::move(field));
}
