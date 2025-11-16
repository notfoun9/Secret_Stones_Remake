#pragma once
#include <memory>

class ActionCounter;
class Card;
class Deck;
class DiscardPile;
class Field;
class Hand;
class Pool;
class Tile;
class StrikeCounter;

typedef std::unique_ptr<Card> CardPtr;
enum struct TileAction;

namespace Manager
{
    struct Elements;

    bool CardIsUsable(const Card& card);
    void UseCard(CardPtr card);
    CardPtr TakeCardFromPool(int cost);
    void SkipAction();
    void SwitchMode();
    void TileAction(Tile* tile);

    void StartParty();
    void EndParty();

    void InitActionCounter(ActionCounter* counter);
    void InitDeck(Deck* deck);
    void InitDiscardPile(DiscardPile* pile);
    void InitField(Field* field);
    void InitHand(Hand* hand);
    void InitPool(Pool* pool);
    void InitStrikeCounter(StrikeCounter* counter);
};
