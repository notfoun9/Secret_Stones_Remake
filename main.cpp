#include "include/application.h"
#include "include/game_states.h"
#include <chrono>
#include <thread>

int main(int argc, char* argv[])
{
    auto app = Application();
    // TODO:
    // auto menu = Menu{app};
    // auto party = Party{app};
    // auto rules = Rules{app};
    

    using namespace std::chrono_literals;
    auto last = std::chrono::steady_clock::now();
    auto now = last;
    auto frame = 1'000'000'000ns / 5;


    GameState state{GameState::Menu};
    SDL_Event event;
    while (state != GameState::Exit)
    {
        last = std::chrono::steady_clock::now();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                state = GameState::Exit;
            }
        }

        SDL_SetRenderDrawColor(app.Renderer(), 0, 0, 0, 255); // Black background
        SDL_RenderClear(app.Renderer());

        switch (state)
        {
            // TODO:
            // case GameState::Menu:     menu->Run(state);   break;
            // case GameState::Party:    party->Run(state);  break;
            // case GameState::Rules:    rules->Run(state);  break;

            default: break;
        }

        SDL_RenderPresent(app.Renderer());

        now = std::chrono::steady_clock::now();
        if (now - last < frame)
        {
            std::this_thread::sleep_for(frame - std::chrono::duration(now - last));
        }
    }

    return 0;
}
