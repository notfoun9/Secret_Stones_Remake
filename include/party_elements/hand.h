#pragma once

#include "application/application.h"
#include "game_objects/game_object.h"
#include <party_elements/card.h>
#include <party_elements/manager.h>
#include <optional>
#include <vector>

#define HAND_SIZE 4
#define DESELECTED_CARD_Y 6.6f
#define SELECTED_CARD_Y 6.4f

class Hand : public GameObject
{
public:
    Hand(Application app);
    ~Hand() override = default;
    
    void Draw() override
    {
        for (int i = 0; i < HAND_SIZE; ++i)
        {
            if (cards[i])
            {
                TextureManager::DrawFull(app.Renderer(), cards[i]->Face(), &dests[i]);
            }
        }
    }

    void Update(SDL_Event& event) override
    {
        SDL_FRect mouseTip{0, 0, 1, 1};
        SDL_GetMouseState(&mouseTip.x, &mouseTip.y);

        for (int i = 0; i < HAND_SIZE; ++i)
        {
            if (SDL_HasRectIntersectionFloat(&dests[i], &mouseTip) && cards[i])
            {
                relatives[i].y = SELECTED_CARD_Y;
                if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
                {
                    TryUseCard(i);
                }
            }
            else
            {
                relatives[i].y = DESELECTED_CARD_Y;
            }
        }
        UpdateDestRect();
    }

    void AddCard(CardPtr card)
    {
        for (int i = 0; i < HAND_SIZE; ++i)
        {
            if (!cards[i])
            {
                cards[i] = std::move(card);
                return;
            }
        }
    }

    int EmptySlots()
    {
        int slots{};
        for (const auto& card : cards)
        {
            if (!card)
            {
                ++slots;
            }
        }
        return slots;
    }

    std::vector<CardPtr>& Cards()
    {
        return cards;
    }

    bool Empty()
    {
        return EmptySlots() == 4;
    }
private:
    void UpdateDestRect()
    {
        int windowWidth{};
        SDL_GetWindowSizeInPixels(app.Window(), &windowWidth, NULL);
        windowWidth /= 16;

        for (int i = 0; i < HAND_SIZE; ++i)
        {
            dests[i] = {
                windowWidth * relatives[i].x,
                windowWidth * relatives[i].y,
                windowWidth * relatives[i].w,
                windowWidth * relatives[i].h
            };
        }
    }

    void TryUseCard(int i)
    {
        if (Manager::CardIsUsable(*cards[i]))
        {
            auto card = std::move(cards[i]);
            cards[i] = {};
            Manager::UseCard(std::move(card));
        }
    }

private:
    Application app;
    std::vector<SDL_FRect> dests;
    std::vector<SDL_FRect> relatives;
    std::vector<CardPtr> cards;
};

inline Hand::Hand(Application app) : app(app)
{
    cards.resize(HAND_SIZE);
    dests.resize(HAND_SIZE);
    relatives.resize(HAND_SIZE);

    for (int i = 0; i < HAND_SIZE; ++i)
    {
        relatives[i] = {3.8f + i * 1.55f, DESELECTED_CARD_Y, 1.5, 2.25};
    }

    UpdateDestRect();
    Manager::InitHand(this);
}


