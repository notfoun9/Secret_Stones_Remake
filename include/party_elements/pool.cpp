#include <party_elements/pool.h>
#include <party_elements/card.h>
#include "../tools/randomizer.h"
#include <party_elements/manager.h>

Pool::Pool(Application app)
    : app(app)
{
    cards.reserve(6);
    cards[1].reserve(COST_1_CARDS);
    cards[2].reserve(COST_2_CARDS);
    cards[3].reserve(COST_3_CARDS);
    cards[5].reserve(COST_5_CARDS);

    for (int i = 0; i < COST_1_CARDS; ++i)
    {
        cards[1].emplace_back(1, i, app);
    }

    for (int i = 0; i < COST_2_CARDS; ++i)
    {
        cards[2].emplace_back(2, i, app);
    }

    for (int i = 0; i < COST_3_CARDS; ++i)
    {
        cards[3].emplace_back(3, i, app);
    }

    for (int i = 0; i < COST_5_CARDS; ++i)
    {
        cards[5].emplace_back(5, i, app);
    }

    Manager::InitPool(this);
}

Card Pool::TakeCard(int cost)
{
    Card card{std::move(cards[cost].back())};
    cards.pop_back();

    return card;
}

void Pool::PutCard(Card&& card)
{
    cards[card.Cost()].emplace_back(std::move(card));
}

void Pool::Randomize(int cost)
{
    auto size = cards[cost].size();
    auto id = Random::Generate(0, size - 1);
    std::swap(cards[id], cards.back());
}
