#pragma once
#include "game_objects/game_object.h"
#include <application/application.h>

class Card;

class Pool : public GameObject
{
public:
    Pool(Application app);
    ~Pool() override = default;

    Card TakeCard(int cost);
    void PutCard(Card&& card);

    void Draw() override
    {}

    void Update(SDL_Event& event) override
    {}
private:
    void Randomize(int cost);

    Application app;
    size_t size;

    std::vector<std::vector<Card>> cards;
} ;

