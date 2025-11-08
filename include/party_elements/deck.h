#pragma once
#include <application/application.h>
#include "game_objects/game_object.h"
#include "game_objects/static_texture.h"

class Card;
typedef std::unique_ptr<Card> CardPtr;

class Deck : public GameObject
{
public:
    Deck(Application app);
    ~Deck() override = default;

    void Draw() override;

    void Update(SDL_Event& event) override;

    void Refill();

    void Randomize();

    void PutCard(CardPtr card);

    CardPtr TakeCard();

    int Size();
    bool Empty();
private:
    StaticTexture        texture;
    std::vector<CardPtr> cards;
};

