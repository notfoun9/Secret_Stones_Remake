#pragma once
#include "../tools/text.h"
#include <game_objects/static_texture.h>
#include <party_elements/manager.h>

class StrikeCounter : public GameObject
{
public:
    StrikeCounter(Application app)
        : counter(0)
        , app(app)
        , dest({10.8, 5.5, 3.7, 1})
        , texture(dest, app)
    {
        auto* text = Text{PrintedText(), FontName::JB_Mono, Color(), app}.Texture();
        texture.ResetTexture(text);
        Manager::InitStrikeCounter(this);
    }

    void Update(SDL_Event& event) override
    {}

    void Draw() override
    {
        texture.Draw();
    }

    int Value() const
    {
        return counter;
    }

    void Increase()
    {
        ++counter;
        auto* text = Text{PrintedText(), FontName::JB_Mono, Color(), app}.Texture();
        SDL_DestroyTexture(texture.ResetTexture(text));
    }

    void Reset()
    {
        counter = 0;
        auto* text = Text{PrintedText(), FontName::JB_Mono, Color(), app}.Texture();
        SDL_DestroyTexture(texture.ResetTexture(text));
    }
private:
    std::string PrintedText() const
    {
        return "Strikes: " + std::to_string(counter);
    }

    SDL_Color Color()
    {
        switch (counter)
        {
            case 0: return {50, 250, 80, 255};
            case 1: return {250, 250, 50, 255};
            case 2: return {250, 125, 50, 255};
            case 3: return {250, 60, 60, 255};
            default: return {};
        };
    }

    int counter;
    const SDL_FRect dest;
    Application app;
    StaticTexture texture;
};
