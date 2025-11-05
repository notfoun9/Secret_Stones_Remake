#pragma once
#include <application/application.h>
#include "game_states.h"
#include "../tools/text.h"
#include "../game_objects/button.h"
#include "../game_objects/static_texture.h"

class Rules
{
public:
    Rules(Application app);

    ~Rules() = default;

    void Run(GameState& state);

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

private:
    Application                               app;
    bool                                      exited;
    std::vector<std::unique_ptr<GameObject>>  gameObjects;
};

inline Rules::Rules(Application app)
    : app(app)
    , exited(false)
{
    auto exitButton = std::make_unique<Button>(
        "assets/menu_default.png",
        "assets/menu_selected.png",
        SDL_FRect{6, 6.9, 4, 1.5},
        app
    );
    exitButton->SetAction(std::make_unique<ExitAction>(exited));
    gameObjects.push_back(std::move(exitButton));

    extern const std::string rulesText;
    gameObjects.emplace_back(std::make_unique<StaticTexture>(
        Text{rulesText.data(), FontName::JB_Mono, {0,0,0,0}, app}.Texture(),
        SDL_FRect{0.2, 0.2, 15.6, 6.6},
        app
    ));
}

inline void Rules::Run(GameState& state)
{
    while (state == GameState::Rules)
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

inline const std::string rulesText = {
R"(   The game consists of a 3 by 3 tile board, a hand of 4 cards, a discard pile, and a deck.
The goal is to achieve conditions of all cards from the deck.
   Each card has a pattern that must be present on the field so the card
can be completed and removed from the game.
During each turn, you must achieve the condition of at least one card, otherwise you
will get a penalty. When you receive the 4th penalty, you lose the game.

   Clicking the "Drop" switch turns you into discard mode, where clicking on a card will
move it to the discard pile and give you action points for the rest of the turn.
   Action points can be spent on flipping a tile (2 clicks)
or swapping places from an adjacent tile: alternately click on the first and the second tile.
To switch back to card achieving mode, you need to click the "Drop" switch again.
On the left side of the screen there is a reminder of what is on the back of each tile type.

   By clicking on the "End turn" button, you draw cards from the deck up to 4.
If the deck runs out, the discard pile shuffles and refills the deck.
    )"};
