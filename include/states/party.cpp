#include <memory>
#include <states/party.h>
#include <party_elements/field.h>
#include <party_elements/hand.h>
#include <party_elements/deck.h>
#include <party_elements/pool.h>
#include "../game_objects/button.h"
#include "../game_objects/switch.h"
#include "../game_objects/static_texture.h"
#include "party_elements/manager.h"

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

struct SkipAction : public Button::Action
{
    void operator()() override
    {
        Manager::FillHand();
    }
};

struct DropSwitch : public Switch::Action
{
    void operator()() override
    {
        Manager::SwitchMode();
    }
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
                    exited = true;
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
    Manager::StartParty();
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
            Manager::EndParty();
            state = GameState::Menu;
            exited = false;
        }

        app.ControlFPS();
    }
}

void Party::InitGameObjects()
{
    auto menuButton = std::make_unique<Button>(
        "assets/menu_default.png",
        "assets/menu_selected.png",
        SDL_FRect{0.4, 0.15, 3, 1.125},
        app
    );
    menuButton->SetAction(std::make_unique<ExitAction>(exited));
    gameObjects.emplace_back(std::move(menuButton));

    auto skipButton = std::make_unique<Button>(
        "assets/skip_default.png",
        "assets/skip_selected.png",
        SDL_FRect{0.4, 6.45, 3, 1.125},
        app
    );
    skipButton->SetAction(std::make_unique<SkipAction>());
    gameObjects.emplace_back(std::move(skipButton));

    auto dropSwitch = std::make_unique<Switch>(
        "assets/drop_default.png",
        "assets/drop_selected.png",
        SDL_FRect{0.4, 7.725, 3, 1.125},
        app
    );
    dropSwitch->SetAction(std::make_unique<DropSwitch>());
    gameObjects.emplace_back(std::move(dropSwitch));

    gameObjects.emplace_back(std::make_unique<StaticTexture>(
        "assets/tip.png",
        SDL_FRect{0.4, 1.425, 3, 4.875},
        app
    ));

    gameObjects.emplace_back(std::make_unique<Field>(app));
    gameObjects.emplace_back(std::make_unique<Pool>(app));
    gameObjects.emplace_back(std::make_unique<Deck>(app));
    gameObjects.emplace_back(std::make_unique<Hand>(app));
}
