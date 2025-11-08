#include <optional>
#include <party_elements/card.h>
#include <party_elements/deck.h>
#include <party_elements/discard_pile.h>
#include <party_elements/field.h>
#include <party_elements/hand.h>
#include <party_elements/manager.h>
#include <party_elements/pool.h>

namespace Manager {

static DiscardPile*  m_discardPile = nullptr;
static Deck*  m_deck = nullptr;
static Field* m_field = nullptr;
static Hand*  m_hand = nullptr;
static Pool*  m_pool = nullptr;

static int    m_moves = 999;
static Tile*  m_selectedTile = nullptr;

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

void InitDiscardPile(DiscardPile *discardPile)
{
    static int singleUseGuard{0};
    assert(0 == singleUseGuard++);

    m_discardPile = discardPile;
}

bool CardIsUsable(const Card &card)
{
    return (mode == Drop) || card.CheckCondition(m_field->GetState());
}

void UseCard(CardPtr card)
{
    if (mode == Drop)
    {
        m_discardPile->PutCard(std::move(card));
    }
    else
    {
        m_pool->PutCard(std::move(card));
    }
}

CardPtr TakeCardFromPool(int cost)
{
    return std::move(m_pool->TakeCard(cost));
}

void FillHand()
{
    while (!m_deck->Empty() && m_hand->EmptySlots())
    {
        m_hand->AddCard(std::move(m_deck->TakeCard()));
    }
}

void RefillDeck()
{
    auto& discardedCards = m_discardPile->Cards();
    for (auto& card : discardedCards)
    {
        m_deck->PutCard(std::move(card));
    }
    discardedCards.resize(0);
}

void SkipAction()
{
    if (m_deck->Size() < m_hand->EmptySlots())
    {
        RefillDeck();
    }
    FillHand();
}

void StartParty()
{
    m_field->GetState();
    m_field->ConstructRandomField();
    m_deck->Refill();
    FillHand();
}

void TileAction(Tile* tile)
{
    if (!m_moves)
    {
        return;
    }

    if (!m_selectedTile)
    {
        m_selectedTile = tile;
        tile->Click();
        return;
    }
    
    if (m_selectedTile == tile)
    {
        m_selectedTile = nullptr;
        tile->Click();
        tile->Flip();
        --m_moves;
        return;
    }

    int pos1 = m_selectedTile->GetPosition();
    int pos2 = tile->GetPosition();
    int diff = std::abs(pos1 - pos2);

    m_selectedTile->Click();
    if (diff == 1  && pos1 / 3 == pos2 / 3 || diff == 3)
    {
        m_field->SwapTiles(tile->GetPosition(), m_selectedTile->GetPosition());
        --m_moves;
    }
    m_selectedTile = nullptr;
}

void EndParty()
{
    auto& handCards = m_hand->Cards();
    for (auto& card : handCards)
    {
        if (card)
        {
            UseCard(std::move(card));
            card.reset();
        }
    }

    while (!m_deck->Empty())
    {
        m_pool->PutCard(m_deck->TakeCard());
    }

    auto& discardedCards = m_discardPile->Cards();
    for (auto& card : discardedCards)
    {
        m_pool->PutCard(std::move(card));
    }
    discardedCards.resize(0);
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
