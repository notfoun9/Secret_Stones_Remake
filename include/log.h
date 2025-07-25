#pragma once
#include <spdlog/spdlog.h>

extern const char* SDL_GetError();

namespace Log {
    inline void CriticalSDLError(fmt::format_string<const char*> text)
    {
        spdlog::critical(text, SDL_GetError());
    }
};
