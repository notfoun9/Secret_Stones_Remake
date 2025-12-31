#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <spdlog/spdlog.h>


enum FontName : char
{
    JB_Mono = 0,
};

class Fonts
{
public:
    Fonts();

    TTF_Font* Get(FontName name);
private:
    class FontDetails;
    std::unordered_map<FontName, std::unique_ptr<FontDetails>> fonts;

    class FontDetails
    {
    public:
        FontDetails(const char* name, float size);

        ~FontDetails();

        TTF_Font* Get();

    private:
        TTF_Font* font{nullptr};
    };
};

