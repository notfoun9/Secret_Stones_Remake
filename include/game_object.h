#include <memory>
#pragma one
#include <SDL3/SDL.h>
#include "application.h"
#include "texture_manager.h"

struct GameObject
{
    virtual ~GameObject() = default;
    virtual void Draw(SDL_Renderer* renderer) = 0;

    virtual void Update(SDL_Event& event) = 0;
};

class Button : public GameObject
{
public:
    Button(const char* defaultTexPath, const char* selectedTexPath, SDL_FRect dest, Application app)
        : defaultTex(TextureManager::LoadTexture(app.Renderer(), defaultTexPath))
        , selectedTex(TextureManager::LoadTexture(app.Renderer(), selectedTexPath))
        , destRect(dest)
        , currentTex(defaultTex)
        , app(app)
        , action(nullptr)
    {}

    ~Button()
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

    void Draw(SDL_Renderer* renderer) override
    {
        TextureManager::DrawFull(app.Renderer(), currentTex, &destRect);
    }

    void Update(SDL_Event& event) override
    {
        SDL_FRect mouseTip{0, 0, 1, 1};
        SDL_GetMouseState(&mouseTip.x, &mouseTip.y);

        if (SDL_HasRectIntersectionFloat(&destRect, &mouseTip))
        {
            currentTex = selectedTex;
            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN && action)
            {
                action->operator()();
            }
        }
        else
        {
            currentTex = defaultTex;
        }
    }

private:
    Application  app;
    SDL_FRect    destRect;
    SDL_Texture* defaultTex;
    SDL_Texture* selectedTex;
    SDL_Texture* currentTex;

    std::unique_ptr<Action> action;
};


