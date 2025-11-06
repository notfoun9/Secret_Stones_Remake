#pragma once
#include <application/application.h>

#define COST_1_CARDS 28
#define COST_2_CARDS 19
#define COST_3_CARDS 13
#define COST_5_CARDS 5

class Card;

class Pool{
public:
    Pool(Application app);
    ~Pool() = default;

    Card TakeCard(int cost);
    void PutCard(Card&& card);
private:
    void Randomize(int cost);

    Application app;
    size_t size;

    std::vector<std::vector<Card>> cards;
} ;

