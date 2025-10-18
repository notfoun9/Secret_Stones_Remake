#include <spdlog/spdlog.h>
#include "application.h"
#include "../tools/fps_controller.h"

struct ApplicationBackend
{
    ApplicationBackend()
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            Log::CriticalSDLError("SDL_Init failed: {}");
            return;
        }

        if (!TTF_Init())
        {
            Log::CriticalSDLError("TTF_Init failed: {}");
            return;
        }

        window = SDL_CreateWindow(
            windowTitle,
            windowWidth,
            windowHeight,
            SDL_WINDOW_RESIZABLE
        );
        if (!window) {
            Log::CriticalSDLError("SDL_CreateWindow failed: {}");
            return;
        }

        renderer = SDL_CreateRenderer(window, NULL);
        if (!renderer) {
            Log::CriticalSDLError("SDL_CreateRenderer failed: {}");
            return;
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        created = true;
    }

    ~ApplicationBackend()
    {
        TTF_Quit();
        SDL_Quit();
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    }

    bool           created{false};
    SDL_Window*    window;
    SDL_Renderer*  renderer;

    const char*            windowTitle  = "Secret Stones";
    static constexpr int   windowWidth  = 1600;
    static constexpr int   windowHeight = 900;

    FPS_Controller         fps{60};
};

class ApplicationImpl
{
public:
    static std::shared_ptr<ApplicationImpl> MakeApplicationImpl()
    {
        auto app = std::make_shared<ApplicationImpl>();
        if (app->impl.created == false)
        {
            app.reset();
            spdlog::error("Could not finish ApplicationImpl creation");
        }

        return app;
    }

    SDL_Window* Window()
    {
        return impl.window;
    }

    SDL_Renderer* Renderer()
    {
        return impl.renderer;
    }

    Fonts* Fonts()
    {
        return &fonts;
    }

    void AdjustWindowSize()
    {
        int width{};
        int height{};

        SDL_GetWindowSizeInPixels(Window(), &width, &height);
        width /= 16;
        height /= 9;
        if (width > height)
        {
            SDL_SetWindowSize(Window(), width * 16, width * 9);
        }
        else
        {
            SDL_SetWindowSize(Window(), height * 16, height * 9);
        }
    }

    void ControlFPS()
    {
        impl.fps.Control();
    }

private:
    ApplicationBackend  impl;
    class Fonts         fonts;
};


Application::Application()
    : impl(ApplicationImpl::MakeApplicationImpl())
{}

Application::Application(const Application& app)
    : impl(app.impl)
{}

Application::Application(Application&& app)
    : Application(app)
{}

SDL_Window* Application::Window()
{
    return impl->Window();
}

SDL_Renderer* Application::Renderer()
{
    return impl->Renderer();
}

Fonts* Application::Fonts()
{
    return impl->Fonts();
}

void Application::AdjustWindowSize()
{
    return impl->AdjustWindowSize();
}

void Application::ControlFPS()
{
    return impl->ControlFPS();
}

