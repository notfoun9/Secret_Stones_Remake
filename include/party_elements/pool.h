#pragma once
#include <application/application.h>

class Card;

class Pool{
public:
    Pool(Application app);
    ~Pool() = default;
private:
    Application app;
    size_t size;

    std::vector<Card> cardsCost1;
    std::vector<Card> cardsCost2;
    std::vector<Card> cardsCost3;
    std::vector<Card> cardsCost5;
} ;

