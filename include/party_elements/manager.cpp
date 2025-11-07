#include <party_elements/field.h>
#include <party_elements/deck.h>
#include <party_elements/hand.h>
#include <party_elements/manager.h>
#include <party_elements/card.h>
#include <party_elements/pool.h>
#include <iostream>

namespace Manager {

static Deck*  m_deck = nullptr;
static Field* m_field = nullptr;
static Pool*  m_pool = nullptr;
static Hand*  m_hand = nullptr;

enum Mode : bool
{
    Drop,
    Select
} mode = Select;


void InitDeck(Deck* deck)
{
    
    static int singleUseGuard{0};
    assert(0 == singleUseGuard++);

    m_deck = deck;
}

void InitField(Field* field)
{
    static int singleUseGuard{0};
    assert(0 == singleUseGuard++);

    m_field = field;
}

void InitPool(Pool* pool)
{
    static int singleUseGuard{0};
    assert(0 == singleUseGuard++);

    m_pool = pool;
}

void InitHand(Hand* hand)
{
    static int singleUseGuard{0};
    assert(0 == singleUseGuard++);

    m_hand = hand;
}

bool CardIsUsable(const Card &card)
{
    return (mode == Drop) || card.CheckCondition(m_field->GetState());
}

void UseCard(Card&& card)
{
    m_pool->PutCard(std::move(card));
}

Card TakeCardFromPool(int cost)
{
    return m_pool->TakeCard(cost);
}

void FillHand()
{
    while (!m_deck->Empty() && m_hand->EmptySlots())
    {
        m_hand->AddCard(std::move(m_deck->TakeCard()));
    }
}

void StartParty()
{
    m_deck->Refill();
    FillHand();
}

void EndParty()
{
    auto& handCards = m_hand->Cards();
    for (auto& card : handCards)
    {
        if (card.has_value())
        {
            UseCard(std::move(card.value()));
            card.reset();
        }
    }

    while (!m_deck->Empty())
    {
        m_pool->PutCard(m_deck->TakeCard());
    }
}

void SwitchMode()
{
    if (mode == Drop)
    {
        mode = Select;
    }
    else
    {
        mode = Drop;
    }
}

};
