#pragma once
#include <application/application.h>
#include <party_elements/card.h>
#include <party_elements/manager.h>
#include "game_objects/game_object.h"
#include "game_objects/static_texture.h"

class DiscardPile : public GameObject
{
public:
    DiscardPile(Application app)
        : app(app)
        , texture({13, 6.6, 1.5, 2.25}, app)
    {
        Manager::InitDiscardPile(this);
    }

    void Draw() override
    {
        if (!cards.empty())
        {
            texture.Draw();
        }
    }

    void Update(SDL_Event&) override
    {}

    void PutCard(CardPtr card)
    {
        cards.emplace_back(std::move(card));
        texture.ResetTexture(cards.back()->Face());
    }

    std::vector<CardPtr>& Cards()
    {
        return cards;
    }

private:
    Application app;
    StaticTexture texture;
    std::vector<CardPtr> cards;
};
