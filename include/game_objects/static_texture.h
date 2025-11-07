#pragma once
#include <application/application.h>
#include "game_object.h"
#include "../tools/texture_manager.h"

class StaticTexture : public GameObject
{
public:
    StaticTexture(const char* texPath, SDL_FRect rect, Application app)
        : tex(TextureManager::LoadTexture(app.Renderer(), texPath))
        , relativeRect(rect)
        , app(app)
        , visible(true)
    {
        UpdateDestRect();
    }

    StaticTexture(SDL_Texture*&& texture, SDL_FRect rect, Application app)
        : tex(texture)
        , relativeRect(rect)
        , app(app)
        , visible(true)
    {
        UpdateDestRect();
    }

    ~StaticTexture()
    {
        SDL_DestroyTexture(tex);
    }

    void Draw() override
    {
        if (visible)
        {
            TextureManager::DrawFull(app.Renderer(), tex, &destRect);
        }
    }

    void Update(SDL_Event& event) override
    {
        if (event.type == SDL_EVENT_WINDOW_RESIZED)
        {
            UpdateDestRect();
        }
    }

    void UpdateDestRect()
    {
        int windowWidth{};
        SDL_GetWindowSizeInPixels(app.Window(), &windowWidth, NULL);
        windowWidth /= 16;

        destRect = {
            windowWidth * relativeRect.x,
            windowWidth * relativeRect.y,
            windowWidth * relativeRect.w,
            windowWidth * relativeRect.h
        };
    }

    void SetVisible(bool isVisible)
    {
        visible = isVisible;
    }
private:
    Application   app;
    SDL_Texture*  tex;
    SDL_FRect     destRect;
    SDL_FRect     relativeRect;
    bool          visible;
};
