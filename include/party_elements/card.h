#pragma once
#include "tools/texture_manager.h"
#include "application/application.h"
#include <party_elements/conditions.h>

class Card
{
public: 
    Card(const int cost, const int id, Application app) 
        : cost(cost)
        , face(TextureManager::LoadTexture(app.Renderer(), Card::CardName(cost, id).data()))
        , condition(GetCondition(cost, id))
    {}

    Card(Card&& card) : face(card.face), condition(card.condition), cost(card.cost)
    {
        card.face = nullptr;
    }

    void operator=(Card&& card)
    {
        std::swap(face, card.face);
        cost = card.cost;
        condition = card.condition;
    }

    Card(const Card&) = delete;
    void operator=(const Card&) = delete;

    ~Card()
    {
        SDL_DestroyTexture(face);
    }

    SDL_Texture* Face() const
    {
        return face;
    }

    int Cost()
    {
        return cost;
    }

    bool CheckCondition(const std::vector<color>& fieldState) const
    {
        return condition(fieldState);
    }

private:
    static std::string CardName(const int cost, const int id)
    {
        return "assets/Card_" + std::to_string(cost) + "_" + std::to_string(id) + ".png";
    }

    int          cost;
    SDL_Texture* face;
    bool      (* condition)(const std::vector<color>& fieldStatus);
} ;
