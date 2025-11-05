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

    bool TryUseCard(const Card& card);

    void InitField(Field* field);
};
