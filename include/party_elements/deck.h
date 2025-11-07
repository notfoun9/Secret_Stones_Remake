#pragma once

#include <application/application.h>
#include "game_objects/game_object.h"
#include "game_objects/static_texture.h"
#include <stack>

class Card;

class Deck : public GameObject
{
public:
    Deck(Application app);
    ~Deck() override = default;

    void Draw() override;

    void Update(SDL_Event& event) override;

    void Refill();

    void Randomize();

    void PutCard(Card&& card);

    Card TakeCard();

    bool Empty();
private:
    std::vector<Card> cards;
    StaticTexture     texture;
};

