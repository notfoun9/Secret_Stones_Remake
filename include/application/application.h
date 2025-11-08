#pragma once
#include "fonts.h"
#include "../states/game_states.h"

class ApplicationImpl;

class Application
{
public:
    Application();
    Application(const Application& app);
    Application(Application&& app);

    SDL_Window* Window();
    SDL_Renderer* Renderer();
    GameState& GameState();

    Fonts* Fonts();

    void AdjustWindowSize();

    void ControlFPS();
private:
    std::shared_ptr<ApplicationImpl> impl;
};
