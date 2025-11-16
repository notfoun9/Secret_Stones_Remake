#pragma once
#include <application/application.h>
#include <tools/text.h>
#include <game_objects/static_texture.h>
#include "application/fonts.h"
#include "game_states.h"
#include "../game_objects/button.h"
#include "party_elements/manager.h"

class GameOver
{
public:
    GameOver(Application app);

    ~GameOver() = default;

    void Run();

    struct ExitAction : public Button::Action
    {
        ExitAction(GameState& state)
            : state(state)

        {}

        void operator()() override
        {
            state = GameState::Menu;
        }

        GameState& state;
    };

private:
    const char* PrintedText()
    {
        return Manager::IsGameWon() ? "YOU WIN" : "YOU LOSE";
    }

    Application                               app;
    StaticTexture                             resultTexture;
    std::vector<std::unique_ptr<GameObject>>  gameObjects;
};

inline GameOver::GameOver(Application app)
    : app(app)
    , resultTexture({4, 3, 8, 2}, app)
{
    auto exitButton = std::make_unique<Button>(
        "assets/menu_default.png",
        "assets/menu_selected.png",
        SDL_FRect{6, 6.9, 4, 1.5},
        app
    );
    exitButton->SetAction(std::make_unique<ExitAction>(app.GameState()));
    gameObjects.push_back(std::move(exitButton));
}

inline void GameOver::Run()
{
    resultTexture.ResetTexture(Text{PrintedText(), FontName::JB_Mono, {}, app}.Texture());
    auto& state = app.GameState();
    while (state == GameState::GameOver)
    {
        SDL_RenderClear(app.Renderer());

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

        for (auto& obj : gameObjects)
        {
            resultTexture.Draw();
            obj->Draw();
        }

        SDL_RenderPresent(app.Renderer());
        app.ControlFPS();
    }
}


