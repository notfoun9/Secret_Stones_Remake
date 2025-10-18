#pragma once
#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std::chrono_literals;

class FPS_Controller
{
public:
    explicit FPS_Controller(size_t fps)
        : frame(1'000'000'000ns / fps)
        , lastControl(steady_clock::now())
    {}

    void Control() const
    {
        auto now = std::chrono::steady_clock::now();
        if (now - lastControl < frame)
        {
            std::this_thread::sleep_for(frame - duration(now - lastControl));
        }

        lastControl = now;
    }

private:
    using Duration = duration<double>;
    using TimePoint = steady_clock::time_point;

    Duration           frame;
    mutable TimePoint  lastControl;
};
