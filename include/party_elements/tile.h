#include "application/application.h"
#include <party_elements/colors.h>

class Tile
{
public:
    Tile(const char* front, const char* back, color frontColor, color backColor, Application app, int pos);
    ~Tile();

    void Click();
    void Swap(Tile& tile);
    void Flip();

    void Update(SDL_Event& event);
    void Draw(SDL_Renderer* renderer);

    color GetActiveColor() const
    {
        return activeColor;
    }

    int GetPosition()
    {
        return position;
    }

    const SDL_Texture* GetActiveSide() const
    {
        return currentTex;
    }

private:
    SDL_Texture* frontTex;
    SDL_Texture* backTex;
    SDL_Texture* currentTex;
    int position;

    color frontColor;
    color backColor;
    color activeColor;

    Application app;

    bool selected;
    SDL_FRect relativeRect{};
    SDL_FRect destRect{};

    void UpdateDestRect();

    void SetRelativeRect(int position);
};

