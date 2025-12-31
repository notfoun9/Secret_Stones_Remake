#include <application/fonts.h>
#include "../tools/log.h"

Fonts::FontDetails::FontDetails(const char* name, float size)
    : font(TTF_OpenFont(name, size))
{
    if (!font)
    {
        Log::CriticalSDLError("TTF_OpenFont failed: {}");
    }
}

Fonts::FontDetails::~FontDetails()
{
    TTF_CloseFont(font);
}

TTF_Font* Fonts::FontDetails::Get()
{
    return font;
}


Fonts::Fonts()
{
    fonts[JB_Mono] = std::make_unique<FontDetails>("assets/jb_mono.ttf", 50);
}

TTF_Font* Fonts::Get(FontName name)
{
    return fonts[name]->Get();
}
