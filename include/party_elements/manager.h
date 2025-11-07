#pragma once

class Deck;
// class DiscardPile;
class Field;
class Hand;
class Pool;
class Card;
// class Strikes;

namespace Manager
{
    struct Elements;

    bool CardIsUsable(const Card& card);
    void UseCard(Card&& card);
    Card TakeCardFromPool(int cost);
    void FillHand();

    void StartParty();
    void EndParty();

    void SwitchMode();

    void InitDeck(Deck* deck);
    void InitField(Field* field);
    void InitHand(Hand* hand);
    void InitPool(Pool* pool);
};
