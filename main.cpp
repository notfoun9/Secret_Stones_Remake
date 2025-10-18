#include <application/application.h>
#include <states/game_states.h>
#include <states/menu.h>
#include <states/rules.h>
#include <states/party.h>

int main(int argc, char* argv[])
{
    auto app = Application();
    Menu menu{app};
    Rules rules{app};
    Party party{app};
    // TODO:
    // GameOver gameOver{app};
    
    GameState state{GameState::Menu};
    while (state != GameState::Exit)
    {
        switch (state)
        {
            case GameState::Menu:      menu.Run(state);      break;
            case GameState::Rules:     rules.Run(state);     break;
            case GameState::Party:     party.Run(state);     break;
            // TODO:
            // case GameState::GameOver:  gameOver.Run(state);  break;

            default: state = GameState::Exit;  break;
        }
    }

    return 0;
}
