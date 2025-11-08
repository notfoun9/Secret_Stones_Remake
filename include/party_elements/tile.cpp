#include <party_elements/tile.h>
#include "party_elements/manager.h"
#include "tools/texture_manager.h"

Tile::Tile(const char* front, const char* back, color frontColor, color backColor, Application app, int pos)
    : frontTex(TextureManager::LoadTexture(app.Renderer(), front))
    , backTex(TextureManager::LoadTexture(app.Renderer(), back))
    , currentTex(frontTex)
    , position(pos)
    , frontColor(frontColor)
    , backColor(backColor)
    , activeColor(frontColor)
    , app(app)
    , selected(false)
{
    SetRelativeRect(pos);
    UpdateDestRect();
}

Tile::~Tile()
{
    SDL_DestroyTexture(frontTex);
    SDL_DestroyTexture(backTex);
}

void Tile::Swap(Tile& tile)
{
    std::swap(frontTex, tile.frontTex);
    std::swap(backTex, tile.backTex);
    std::swap(currentTex, tile.currentTex);
    std::swap(frontColor, tile.frontColor);
    std::swap(backColor, tile.backColor);
    std::swap(activeColor, tile.activeColor);
    std::swap(selected, tile.selected);
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
        Manager::TileAction(this);
    }
}

void Tile::Click()
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

void Tile::Flip()
{
    currentTex = (currentTex == backTex ? frontTex : backTex);
    activeColor = (activeColor == backColor ? frontColor : backColor); 
}

void Tile::UpdateDestRect()
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

void Tile::SetRelativeRect(int position)
{
    int x = position % 3;
    int y = position / 3;
    relativeRect = SDL_FRect{
        3.8f + 0.1125f + x * (1.9f + 0.1125f), 
        0.15f + 0.1125f + y * (1.9f + 0.1125f),
        1.9,
        1.9
    };
}
