#pragma once
#include "game_objects/game_object.h"
#include <application/application.h>

class Card;
typedef std::unique_ptr<Card> CardPtr;

class Pool : public GameObject
{
public:
    Pool(Application app);
    ~Pool() override = default;

    CardPtr TakeCard(int cost);
    void PutCard(CardPtr card);

    void Draw() override
    {}

    void Update(SDL_Event& event) override
    {}
private:
    void Randomize(int cost);

    Application app;
    size_t size;

    std::vector<std::vector<CardPtr>> cards;
} ;

