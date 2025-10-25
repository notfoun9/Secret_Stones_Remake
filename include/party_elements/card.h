#pragma once
#include "tools/texture_manager.h"
#include "application/application.h"
#include <party_elements/conditions.h>


class Card
{
public: 
    Card(const int cost, const int id, Application app) 
        : face(TextureManager::LoadTexture(app.Renderer(), Card::CardName(cost, id).data()))
        , condition(GetCondition(cost, id))
    {}

    ~Card()
    {
        SDL_DestroyTexture(face);
    }

    const SDL_Texture* const Face() const
    {
        return face;
    }

    bool CheckCondition(const std::vector<int>& fieldState) const
    {
        return condition(fieldState);
    }

private:
    static std::string CardName(const int cost, const int id)
    {
        return "assets/Card_" + std::to_string(cost) + "_" + std::to_string(id) + ".png";
    }

    SDL_Texture* face;
    bool      (* condition)(const std::vector<int>& fieldStatus);
} ;
