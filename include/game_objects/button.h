#pragma once
#include <application/application.h>
#include "game_object.h"
#include "../tools/texture_manager.h"

class Button : public GameObject
{
public:
    Button(const char* defaultTexPath, const char* selectedTexPath, SDL_FRect rect, Application app)
        : defaultTex(TextureManager::LoadTexture(app.Renderer(), defaultTexPath))
        , selectedTex(TextureManager::LoadTexture(app.Renderer(), selectedTexPath))
        , relativeRect(rect)
        , currentTex(defaultTex)
        , app(app)
        , action(nullptr)
    {
        UpdateDestRect();
    }

    ~Button() override
    {
        SDL_DestroyTexture(defaultTex);
        SDL_DestroyTexture(selectedTex);
    }

    struct Action
    {
        virtual ~Action() = default;
        virtual void operator()() = 0;
    };

    void SetAction(std::unique_ptr<Action>&& newAction)
    {
        action = std::move(newAction);
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

    void Draw(SDL_Renderer* renderer) override
    {
        TextureManager::DrawFull(app.Renderer(), currentTex, &destRect);
    }

    void Update(SDL_Event& event) override
    {
        if (event.type == SDL_EVENT_WINDOW_RESIZED)
        {
            UpdateDestRect();
        }

        SDL_FRect mouseTip{0, 0, 1, 1};
        SDL_GetMouseState(&mouseTip.x, &mouseTip.y);

        if (SDL_HasRectIntersectionFloat(&destRect, &mouseTip))
        {
            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
            {
                action->operator()();
                currentTex = defaultTex;
            }
            else
            {
                currentTex = selectedTex;
            }
        }
        else
        {
            currentTex = defaultTex;
        }
    }

private:
    Application  app;
    SDL_FRect    relativeRect;
    SDL_FRect    destRect;
    SDL_Texture* defaultTex;
    SDL_Texture* selectedTex;
    SDL_Texture* currentTex;

    std::unique_ptr<Action> action;
};


