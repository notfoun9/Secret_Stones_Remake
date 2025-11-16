#include <application/application.h>
#include <states/game_states.h>
#include <states/menu.h>
#include <states/rules.h>
#include <states/party.h>
#include <states/game_over.h>

int main(int argc, char* argv[])
{
    auto app = Application{};
    Menu menu{app};
    Rules rules{app};
    Party party{app};
    GameOver gameOver{app};
    
    auto& state = app.GameState();
    while (state != GameState::Exit)
    {
        switch (state)
        {
            case GameState::Menu:     menu.Run();     break;
            case GameState::Rules:    rules.Run();    break;
            case GameState::Party:    party.Run();    break;
            case GameState::GameOver: gameOver.Run(); break;

            default: state = GameState::Exit;  break;
        }
    }

    return 0;
}
