#pragma once
#include <SDL3/SDL.h>

struct GameObject
{
    virtual ~GameObject() = default;
    virtual void Draw() = 0;

    virtual void Update(SDL_Event& event) = 0;
};

