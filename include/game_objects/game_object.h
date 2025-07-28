#pragma once
#include <SDL3/SDL.h>
#include "../texture_manager.h"

struct GameObject
{
    virtual ~GameObject() = default;
    virtual void Draw(SDL_Renderer* renderer) = 0;

    virtual void Update(SDL_Event& event) = 0;
};

