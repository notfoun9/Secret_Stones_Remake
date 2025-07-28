#pragma once
#include <application/application.h>
#include "game_states.h"
#include "../game_objects/button.h"

class Menu
{
public:
    Menu(Application app);

    ~Menu() = default;

    void Run(GameState& state);

    struct ExitAction : public Button::Action
    {
        ExitAction(GameState& state)
            : state(state)
        {}

        void operator()() override
        {
            state = GameState::Exit;
        }

        GameState& state;
    };

    struct RulesAction : public Button::Action
    {
        RulesAction(GameState& state)
            : state(state)
        {}

        void operator()() override
        {
            state = GameState::Rules;
        }

        GameState& state;
    };

    struct PartyAction : public Button::Action
    {
        PartyAction(GameState& state)
            : state(state)
        {}

        void operator()() override
        {
            state = GameState::Party;
        }

        GameState& state;
    };
private:
    Application                               app;
    GameState                                 nextState;
    std::vector<std::unique_ptr<GameObject>>  gameObjects;
};

inline Menu::Menu(Application app)
    : app(app)
    , nextState(GameState::Menu)
{
    auto partyButton = std::make_unique<Button>(
        "assets/party_default.png",
        "assets/party_selected.png",
        SDL_FRect{6, 2, 4, 1.5},
        app
    );
    partyButton->SetAction(std::make_unique<PartyAction>(nextState));

    auto rulesButton = std::make_unique<Button>(
        "assets/rules_default.png",
        "assets/rules_selected.png",
        SDL_FRect{6, 4, 4, 1.5},
        app
    );
    rulesButton->SetAction(std::make_unique<RulesAction>(nextState));

    auto exitButton = std::make_unique<Button>(
        "assets/exit_default.png",
        "assets/exit_selected.png",
        SDL_FRect{6, 6, 4, 1.5},
        app
    );
    exitButton->SetAction(std::make_unique<ExitAction>(nextState));
    
    gameObjects.push_back(std::move(partyButton));
    gameObjects.push_back(std::move(rulesButton));
    gameObjects.push_back(std::move(exitButton));
}

inline void Menu::Run(GameState& state)
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
                    state = GameState::Exit;
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
        obj->Draw(app.Renderer());
    }

    std::swap(state, nextState);
}
