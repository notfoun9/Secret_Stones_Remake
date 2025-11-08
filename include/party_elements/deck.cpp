#include "party_elements/manager.h"
#include <party_elements/deck.h>
#include <party_elements/card.h>
#include "../tools/randomizer.h"

#define MEDIUM_DIFFICULTY std::vector{0, 28, 19, 12, 0, 5}

Deck::Deck(Application app)
    : texture("assets/deck.png", SDL_FRect{10.8,6.6,1.5,2.25}, app)
{
    Manager::InitDeck(this);
}

void Deck::Draw()
{
    texture.Draw();
}

void Deck::Update(SDL_Event& event)
{
}

void Deck::Refill()
{
    for (int i = 0; i < MEDIUM_DIFFICULTY[1]; ++i)
    {
        cards.emplace_back(Manager::TakeCardFromPool(1));
    }

    for (int i = 0; i < MEDIUM_DIFFICULTY[2]; ++i)
    {
        cards.emplace_back(Manager::TakeCardFromPool(2));
    }

    for (int i = 0; i < MEDIUM_DIFFICULTY[3]; ++i)
    {
        cards.emplace_back(Manager::TakeCardFromPool(3));
    }

    for (int i = 0; i < MEDIUM_DIFFICULTY[5]; ++i)
    {
        cards.emplace_back(Manager::TakeCardFromPool(5));
    }
}

void Deck::Randomize()
{
    auto size = cards.size();
    auto id = Random::Generate(0, size - 1);
    std::swap(cards[id], cards.back());
}

void Deck::PutCard(CardPtr card)
{
    texture.SetVisible(true);
    cards.emplace_back(std::move(card));
}

CardPtr Deck::TakeCard()
{
    Randomize();
    auto card = std::move(cards.back());
    cards.pop_back();
    if (cards.empty())
    {
        texture.SetVisible(false);
    }

    return card;
}

int Deck::Size()
{
    return cards.size();
}

bool Deck::Empty()
{
    return cards.empty();
}
