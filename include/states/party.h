#pragma once
#include <application/application.h>
#include "game_states.h"
#include <game_objects/game_object.h>
#include <party_elements/manager.h>
#include <party_elements/hand.h>

class Party
{
public:
    Party(Application app);

    ~Party() = default;

    void Run(GameState& state);

    using Objects = std::vector<std::unique_ptr<GameObject>>;
private:
    void HandleEvents(GameState& state);
    void InitGameObjects();

private:
    Application  app;
    Objects      gameObjects;
    bool         exited;
};

