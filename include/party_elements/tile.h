#include "application/application.h"
#include <party_elements/colors.h>

class Tile
{
public:
    Tile(const char* front, const char* back, color frontColor, color backColor, Application app, int pos);
    ~Tile();

    void Update(SDL_Event& event);
    void Draw(SDL_Renderer* renderer);

    color GetActiveColor() const
    {
        return activeColor;
    }

    const SDL_Texture* GetActiveSide() const
    {
        return currentTex;
    }

    void Flip()
    {
        currentTex = (currentTex == backTex ? frontTex : backTex);
    }
private:
    SDL_Texture* frontTex{};
    SDL_Texture* backTex{};
    SDL_Texture* currentTex{};

    color frontColor{};
    color backColor{};
    color activeColor{};

    Application app;

    int position{};
    bool selected{};
    SDL_FRect relativeRect{};
    SDL_FRect destRect{};

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

    void UpdateRelativeRect()
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
};

