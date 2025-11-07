#pragma once
#include <spdlog/spdlog.h>
#include <string_view>

extern const char* SDL_GetError();

namespace Log {
    inline void CriticalSDLError(fmt::format_string<const char*> text)
    {
        spdlog::critical(text, SDL_GetError());
    }

    inline void Warning(std::string_view text)
    {
        spdlog::warn(text);
    }
};
