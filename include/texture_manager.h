#include <SDL3_image/SDL_image.h>
#include "include/log.h"

namespace TextureManager {

[[nodiscard]] inline SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* texture)
{
    SDL_Surface* tmpSurface = IMG_Load(texture);
    if (!tmpSurface) {
        spdlog::critical("Texture {} is not created", texture);
        Log::CriticalSDLError("Surface is not loaded. {}\n");
        return nullptr;
    }

    SDL_Texture* textureFromSurface = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    if (!textureFromSurface) {
        spdlog::critical("Texture {} is not created", texture);
        Log::CriticalSDLError("{}\n");
    }

    SDL_DestroySurface(tmpSurface);

    SDL_SetTextureScaleMode(textureFromSurface, SDL_SCALEMODE_NEAREST);
    return textureFromSurface;
}

inline void DrawFull(
        SDL_Renderer* renderer,
        SDL_Texture* texture,
        const SDL_FRect *dest)
{
    SDL_RenderTextureRotated(renderer, texture, NULL, dest, 0.0, NULL, SDL_FLIP_NONE);
}

inline void DrawWithBoarders(
        SDL_Renderer* renderer,
        SDL_Texture* texture,
        const SDL_FRect* src,
        const SDL_FRect *dest)
{
    SDL_RenderTextureRotated(renderer, texture, src, dest, 0.0, NULL, SDL_FLIP_NONE);
}

inline void DrawFlipped(
        SDL_Renderer* renderer,
        SDL_Texture* texture,
        const SDL_FRect* src,
        const SDL_FRect *dest,
        SDL_FlipMode flip)
{
    SDL_RenderTextureRotated(renderer, texture, src, dest, 0.0, NULL, flip);
}

inline void DrawRotated(
        SDL_Renderer* renderer,
        SDL_Texture* texture,
        const SDL_FRect* src,
        const SDL_FRect* dest,
        double angle,
        SDL_FPoint* center,
        SDL_FlipMode flip)
{
    SDL_RenderTextureRotated(renderer, texture, src, dest, angle, center, flip);
}

};
