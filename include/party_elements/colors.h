#pragma once
#include <ostream>
enum color
{
    WHITE = 0,
    RED = 1,
    ORANGE = 2,
    YELLOW = 3,
    GREEN = 4,
    BLUE = 5,
    PURPLE = 6,
    BLACK = 7
};

inline std::ostream& operator<<(std::ostream& os, color c)
{
    switch (c)
    {
        case WHITE: os << "WHITE"; break;
        case RED: os << "RED"; break;
        case ORANGE: os << "ORANGE"; break;
        case YELLOW: os << "YELLOW"; break;
        case GREEN: os << "GREEN"; break;
        case BLUE: os << "BLUE"; break;
        case PURPLE: os << "PURPLE"; break;
        case BLACK: os << "BLACK"; break;
        default: break;
    }
    return os;
}
