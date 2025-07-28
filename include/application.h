#pragma once

#include "fonts.h"
#include <memory>

class ApplicationImpl;

class Application
{
public:
    Application();
    Application(const Application& app);
    Application(Application&& app);

    SDL_Window* Window();

    SDL_Renderer* Renderer();

    Fonts* Fonts();

    void AdjustWindowSize();
private:
    std::shared_ptr<ApplicationImpl> impl;
};
