#pragma once
#include <application/application.h>
#include <string_view>

class Text {
public:
    Text(std::string_view text, const FontName& font, const SDL_Color& color, Application app)
        : app(app)
        , texture(TextureFromText(text, font, color))
    {}

    ~Text()
    {
        SDL_DestroyTexture(texture);
    }

    SDL_Texture*& Texture() &
    {
        return texture;
    }
    
    SDL_Texture* Texture() &&
    {
        auto tmp = texture;
        texture = nullptr;
        return std::move(tmp);
    }

    void ResetText(std::string_view newText, const FontName& font, const SDL_Color& color)
    {
        SDL_DestroyTexture(texture);
        texture = TextureFromText(newText, font, color);
    }
private:
    Application  app;
    SDL_Texture* texture;
private:
    SDL_Texture* TextureFromText(std::string_view text, const FontName& font, const SDL_Color& color)
    {
        auto surface = TTF_RenderText_Solid_Wrapped(
            app.Fonts()->Get(font),
            text.data(),
            0,
            color,
            0
        );

        if (!surface)
        {
            Log::CriticalSDLError("TTF_RenderText_Solid failed: {}");
        }

        auto texture = SDL_CreateTextureFromSurface(app.Renderer(), surface);
        SDL_DestroySurface(surface);
        if (!texture)
        {
            Log::CriticalSDLError("SDL_CreateTextureFromSurface failed: {}");
        }
        return texture;
    }
};

