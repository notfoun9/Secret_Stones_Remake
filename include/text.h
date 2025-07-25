#pragma once
#include "fonts.h"
#include "application.h"

class Text {
public:
    Text(const char* text, const FontName& font, const SDL_Color& color, Application app)
    {
        auto surface = TTF_RenderText_Solid(
            app.Fonts()->Get(font),
            text,
            0,
            color
        );

        if (!surface)
        {
            Log::CriticalSDLError("TTF_RenderText_Solid failed: {}");
            return;
        }

        texture = SDL_CreateTextureFromSurface(app.Renderer(), surface);
        SDL_DestroySurface(surface);
        if (!texture)
        {
            Log::CriticalSDLError("SDL_CreateTextureFromSurface failed: {}");
        }
    }

    ~Text()
    {
        SDL_DestroyTexture(texture);
    }

    SDL_Texture* Texture()
    {
        return texture;
    }
    
private:
    SDL_Texture* texture;
};

