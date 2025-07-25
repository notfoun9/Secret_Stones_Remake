#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <spdlog/spdlog.h>
#include <memory>
#include "log.h"

namespace {
    class Font_details
    {
    public:
        Font_details(const char* name, float size)
            : font(TTF_OpenFont(name, size))
        {
            if (!font)
            {
                Log::CriticalSDLError("TTF_OpenFont failed: {}");
            }
        }
        ~Font_details()
        {
            TTF_CloseFont(font);
        }

        TTF_Font* Get()
        {
            return font;
        }

    private:
        TTF_Font* font{nullptr};
    };
};

enum FontName : char
{
    Arial50 = 0,
};

class Fonts
{
public:
    Fonts()
    {
        fonts[Arial50] = std::make_unique<Font_details>("assets/aerial.ttf", 50);
    }

    inline TTF_Font* Get(FontName name)
    {
        return fonts[name]->Get();
    }
private:
    std::unordered_map<FontName, std::unique_ptr<Font_details>> fonts;
};

