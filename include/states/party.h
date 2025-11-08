#pragma once
#include <application/application.h>
#include <game_objects/game_object.h>
#include <party_elements/manager.h>
#include <party_elements/hand.h>

class Party
{
public:
    Party(Application app);

    ~Party() = default;

    void Run();

    using Objects = std::vector<std::unique_ptr<GameObject>>;
private:
    void HandleEvents();
    void InitGameObjects();

private:
    Application  app;
    Objects      gameObjects;
};

