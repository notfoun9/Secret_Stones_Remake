#include <party_elements/field.h>

Field::Field(Application app)
    : app(app)
    , fieldBack("assets/back.png", SDL_FRect{3.8, 0.15, 6.15, 6.15}, app)
{
    tiles.reserve(9);
    tiles.emplace_back("assets/green.png", "assets/white.png",  GREEN, WHITE,  app, 0);
    tiles.emplace_back("assets/green.png", "assets/white.png",  GREEN, WHITE,  app, 1);
    tiles.emplace_back("assets/green.png", "assets/white.png",  GREEN, WHITE,  app, 2);
    tiles.emplace_back("assets/blue.png",  "assets/purple.png", BLUE,  PURPLE, app, 3);
    tiles.emplace_back("assets/blue.png",  "assets/purple.png", BLUE,  PURPLE, app, 4);
    tiles.emplace_back("assets/blue.png",  "assets/purple.png", BLUE,  PURPLE, app, 5);
    tiles.emplace_back("assets/red.png",   "assets/orange.png", RED,   ORANGE, app, 6);
    tiles.emplace_back("assets/red.png",   "assets/orange.png", RED,   ORANGE, app, 7);
    tiles.emplace_back("assets/black.png", "assets/yellow.png", BLACK, YELLOW, app, 8);
}

Field::~Field() = default;

void Field::Draw()
{
    fieldBack.Draw();
    for (auto& tile : tiles)
    {
        tile.Draw(app.Renderer());
    }
}

void Field::Update(SDL_Event &event)
{
    for (auto& tile : tiles)
    {
        tile.Update(event);
    }
}

