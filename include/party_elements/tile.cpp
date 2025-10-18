#include <party_elements/tile.h>
#include "tools/texture_manager.h"

Tile::Tile(const char* front, const char* back, int frontColor, int backColor, Application app, int pos)
    : frontTex(TextureManager::LoadTexture(app.Renderer(), front))
    , backTex(TextureManager::LoadTexture(app.Renderer(), back))
    , frontColor(frontColor)
    , backColor(backColor)
    , app(app)
    , position(pos)
    , currentTex(frontTex)
    , activeColor(frontColor)
    , selected(false)
{
    UpdateRelativeRect();
    UpdateDestRect();
}

Tile::~Tile()
{
    SDL_DestroyTexture(frontTex);
    SDL_DestroyTexture(backTex);
}

void Tile::Draw(SDL_Renderer *renderer)
{
    TextureManager::DrawFull(
        renderer,
        currentTex,
        &destRect
    );
}

void Tile::Update(SDL_Event &event)
{
    if (event.type == SDL_EVENT_WINDOW_RESIZED)
    {
        UpdateDestRect();
    }

    SDL_FRect mouseTip{0, 0, 1, 1};
    SDL_GetMouseState(&mouseTip.x, &mouseTip.y);

    if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN &&
        SDL_HasRectIntersectionFloat(&destRect, &mouseTip))
    {
        selected = !selected;
        if (selected)
        {
            relativeRect.x -= 0.05;
            relativeRect.y -= 0.05;
            relativeRect.w += 0.1;
            relativeRect.h += 0.1;
        }
        else
        {
            relativeRect.x += 0.05;
            relativeRect.y += 0.05;
            relativeRect.w -= 0.1;
            relativeRect.h -= 0.1;
        }
        UpdateDestRect();
    }
}
