#pragma once
#include <vector>
#include <party_elements/tile.h>
#include "game_objects/game_object.h"
#include "game_objects/static_texture.h"

class Field : public GameObject
{
public:
    Field(Application app);
    ~Field() override;

    void Update(SDL_Event& event) override;
    void Draw() override;

    // bool SwapCards(int i, int j);
    enum Tiles {GR_WH_1, GR_WH_2, GR_WH_3, BLU_PUR_1, BLU_PUR_2, BLU_PUR_3, RED_OR_1, RED_OR_2, BLA_YEL_1};
    enum colors {WHITE, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, BLACK};

    // void constructRandomField();
private:
    Application app;
    StaticTexture fieldBack;
    std::vector<Tile> tiles;
} ;

