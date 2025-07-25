#include "application.h"

namespace {
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
    static constexpr int   windowHeight = 600;
    static constexpr int   windowWidth  = 800;
};

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
