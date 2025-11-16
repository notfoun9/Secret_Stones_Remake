#pragma once
#include "../tools/text.h"
#include <game_objects/static_texture.h>
#include <party_elements/manager.h>

class ActionCounter : public GameObject
{
public:
    ActionCounter(Application app)
        : counter(0)
        , app(app)
        , dest({10.8, 4.5, 3.7, 1})
        , texture(dest, app)
    {
        auto* text = Text{PrintedText(), FontName::JB_Mono, {255, 255, 255, 255}, app}.Texture();
        texture.ResetTexture(text);
        Manager::InitActionCounter(this);
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
        UpdateTexture();
    }

    void Decrease()
    {
        --counter;
        UpdateTexture();
    }

    void Reset()
    {
        counter = 0;
        UpdateTexture();
    }
private:
    std::string PrintedText() const
    {
        return "Actions: " + std::to_string(counter);
    }

    void UpdateTexture()
    {
        auto* text = Text{PrintedText(), FontName::JB_Mono, {0, 0, 0, 255}, app}.Texture();
        SDL_DestroyTexture(texture.ResetTexture(text));
    }

    int counter;
    const SDL_FRect dest;
    Application app;
    StaticTexture texture;
};
