#include "include/application.h"
#include "include/game_states.h"
#include "include/states/menu.h"
#include "include/states/rules.h"
#include <chrono>
#include <thread>

int main(int argc, char* argv[])
{
    auto app = Application();
    Menu menu{app};
    Rules rules{app};
    // TODO:
    // Party party{app};
    // GameOver gameOver{app};
    
    using namespace std::chrono_literals;
    auto last = std::chrono::steady_clock::now();
    auto now = last;
    auto frame = 1'000'000'000ns / 60;

    GameState state{GameState::Menu};
    while (state != GameState::Exit)
    {
        last = std::chrono::steady_clock::now();

        SDL_RenderClear(app.Renderer());
        switch (state)
        {
            case GameState::Menu:      menu.Run(state);      break;
            case GameState::Rules:     rules.Run(state);     break;
            // TODO:
            // case GameState::Party:     party.Run(state);     break;
            // case GameState::GameOver:  gameOver.Run(state);  break;

            default: state = GameState::Exit;  break;
        }

        SDL_RenderPresent(app.Renderer());
        
        now = std::chrono::steady_clock::now();
        if (now - last < frame)
        {
            std::this_thread::sleep_for(frame - std::chrono::duration(now - last));
        }
        // spdlog::info("{}", 1'000'000'000ns / (std::chrono::steady_clock::now() - last));
    }

    return 0;
}
