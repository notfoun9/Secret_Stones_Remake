#pragma once
#include <vector>
#include <party_elements/tile.h>
#include <party_elements/colors.h>
#include "game_objects/game_object.h"
#include "game_objects/static_texture.h"

class Field : public GameObject
{
public:
    Field(Application app);
    ~Field() override;

    void Update(SDL_Event& event) override;
    void Draw() override;

    enum Tiles {GR_WH_1, GR_WH_2, GR_WH_3, BLU_PUR_1, BLU_PUR_2, BLU_PUR_3, RED_OR_1, RED_OR_2, BLA_YEL_1};

    // TODO:
    // void constructRandomField();
    // void swapTiles(int i, int j);
private:
    Application app;
    StaticTexture fieldBack;
    std::vector<Tile> tiles;
} ;

inline Field::Field(Application app)
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

inline Field::~Field() = default;

inline void Field::Draw()
{
    fieldBack.Draw();
    for (auto& tile : tiles)
    {
        tile.Draw(app.Renderer());
    }
}

inline void Field::Update(SDL_Event &event)
{
    for (auto& tile : tiles)
    {
        tile.Update(event);
    }
}
