#pragma once
#include "fonts.h"
#include <memory>
#include <spdlog/spdlog.h>

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
private:
    std::shared_ptr<ApplicationImpl> impl;
};
