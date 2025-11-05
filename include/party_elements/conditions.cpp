#include <party_elements/conditions.h>
#include <party_elements/colors.h>

extern const std::vector<std::vector<Cond>> cardConditions;

Cond GetCondition(int cost, int id)
{
    return cardConditions[cost - 1][id];
}

template<int cost, int id>
bool CardCondition(const std::vector<color>& field) = delete;

template<>
bool CardCondition<1, 0>(const std::vector<color>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == GREEN && field[i + 3] == PURPLE) {
            return 1;
        }
    }
    return 0;
};

template<>
bool CardCondition<1, 1>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == GREEN && field[i + 3] == RED) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 2>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == WHITE && field[i + 1] == GREEN) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 3>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == BLUE && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 4>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == BLUE && field[i + 3] == WHITE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 5>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == WHITE && field[i + 3] == WHITE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 6>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == PURPLE && field[i + 3] == BLUE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 7>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == BLUE && field[i + 3] == ORANGE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 8>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == ORANGE && field[i + 3] == PURPLE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 9>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4}) {
        if (field[i] == GREEN && field[i + 4] == PURPLE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 10>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == GREEN && field[i + 3] == WHITE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 11>(const std::vector<color>& field)
{
    return field[4] == ORANGE;
}

template<>
bool CardCondition<1, 12>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == PURPLE && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 13>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == WHITE && field[i + 1] == ORANGE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 14>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == WHITE && field[i + 1] == BLUE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 15>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == BLUE && field[i + 1] == RED) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 16>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == ORANGE && field[i + 1] == GREEN) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 17>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == WHITE && field[i + 3] == GREEN) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 18>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == GREEN && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 19>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == PURPLE && field[i + 1] == BLUE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 20>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == BLUE && field[i + 3] == BLUE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 21>(const std::vector<color>& field)
{
    return field[4] == RED;
}

template<>
bool CardCondition<1, 22>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == GREEN && field[i + 1] == GREEN) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 23>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == RED && field[i + 3] == WHITE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 24>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == RED && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 25>(const std::vector<color>& field)
{
    for (int i : {1,2,4,5}) {
        if (field[i] == WHITE && field[i + 2] == BLUE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 26>(const std::vector<color>& field)
{
    for (int i = 0; i < 6; ++i) {
        if (field[i] == BLUE && field[i + 3] == PURPLE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<1, 27>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == GREEN && field[i + 1] == WHITE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<2, 0>(const std::vector<color>& field)
{
    return field[8] == BLACK;
}

template<>
bool CardCondition<2, 1>(const std::vector<color>& field)
{
    for (int i : {6,7,8}) {
        if (field[i] == BLACK) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 2>(const std::vector<color>& field)
{
    return (field[0] == GREEN && field[8] == ORANGE);
}

template<>
bool CardCondition<2, 3>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == YELLOW && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<2, 4>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == GREEN && field[i + 2] == WHITE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 5>(const std::vector<color>& field)
{
    for (int i : {0,1,2}) {
        if (field[i] == WHITE && field[i + 6] == RED) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 6>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == ORANGE && field[i + 1] == ORANGE) {
            return 1;
        }
    }
    return 0;
}

template<>
bool CardCondition<2, 7>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4}) {
        if (field[i + 1] == GREEN && field[i + 3] == RED) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 8>(const std::vector<color>& field)
{
    return field[0] == YELLOW;
}

template<>
bool CardCondition<2, 9>(const std::vector<color>& field)
{
    return (field[0] == PURPLE && field[8] == PURPLE);
}

template<>
bool CardCondition<2, 10>(const std::vector<color>& field)
{
    return (field[2] == WHITE && field[6] == WHITE);
}

template<>
bool CardCondition<2, 11>(const std::vector<color>& field)
{
    return (field[2] == RED && field[6] == BLUE);
}

template<>
bool CardCondition<2, 12>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == PURPLE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 13>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == BLUE && field[i + 2] == BLUE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 14>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == PURPLE && field[i + 2] == PURPLE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 15>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i + 2] == YELLOW) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 16>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i + 1] == PURPLE && field[i + 2] == RED) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 17>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == WHITE && field[i + 2] == GREEN) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 18>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == ORANGE && field[i + 1] == BLUE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<2, 19>(const std::vector<color>& field)
{
    for (int i : {0,1,2}) {
        if (field[i] == YELLOW) return 1;
    }
    return 0;
}


template<>
bool CardCondition<3, 0>(const std::vector<color>& field)
{
    return (field[1] == WHITE && field[6] == WHITE && field[8] == WHITE);
}

template<>
bool CardCondition<3, 1>(const std::vector<color>& field)
{
    for (int i : {0,1,2}) {
        if (field[i] == ORANGE && field[i + 3] == GREEN && field[i + 6] == PURPLE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<3, 2>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == PURPLE && field[i + 1] == RED && field[i + 2] == WHITE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<3, 3>(const std::vector<color>& field)
{
    for (int i : {0,1,2}) {
        if (field[i] == BLUE && field[i + 3] == BLUE && field[i + 6] == BLUE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<3, 4>(const std::vector<color>& field)
{
    for (int i : {0,1,2}) {
        if (field[i] == ORANGE && field[i + 6] == ORANGE) return 1;
    }
    return 0;    
}

template<>
bool CardCondition<3, 5>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4}) {
        if (field[i + 1] == BLUE && field[i + 3] == BLUE && field[i + 4] == BLACK) return 1;
    }
    return 0;
}

template<>
bool CardCondition<3, 6>(const std::vector<color>& field)
{
    for (int i : {0,1,2}) {
        if (field[i] == PURPLE && field[i + 3] == PURPLE && field[i + 6] == PURPLE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<3, 7>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == RED && field[i + 2] == RED) return 1;
    }
    return 0;
}

template<>
bool CardCondition<3, 8>(const std::vector<color>& field)
{
    return (field[0] == BLUE && field[2] == BLUE && field[7] == BLUE);
}

template<>
bool CardCondition<3, 9>(const std::vector<color>& field)
{
    for (int i : {0,1,3,4}) {
        if (field[i] == GREEN && field[i + 3] == YELLOW && field[i + 4] == GREEN) return 1;
    }
    return 0;
}

template<>
bool CardCondition<3, 10>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == WHITE && field[i + 1] == WHITE && field[i + 2] == WHITE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<3, 11>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == GREEN && field[i + 1] == GREEN && field[i + 2] == GREEN) return 1;
    }
    return 0;
}

template<>
bool CardCondition<3, 12>(const std::vector<color>& field)
{
    for (int i : {0,3,6}) {
        if (field[i] == GREEN && field[i + 1] == ORANGE && field[i + 2] == BLUE) return 1;
    }
    return 0;
}

template<>
bool CardCondition<5, 0>(const std::vector<color>& field)
{
    return (field[1] == GREEN && field[3] == ORANGE && field[5] == ORANGE && field[7] == BLUE);
}

template<>
bool CardCondition<5, 1>(const std::vector<color>& field)
{
    return (field[1] == YELLOW && field[6] == RED && field[8] == RED);
}

template<>
bool CardCondition<5, 2>(const std::vector<color>& field)
{
    return (field[1] == WHITE && field[3] == PURPLE && field[5] == PURPLE && field[7] == BLACK);
}

template<>
bool CardCondition<5, 3>(const std::vector<color>& field)
{
    return (field[0] == PURPLE && field[2] == GREEN && field[6] == WHITE && field[8] == BLUE);
}

template<>
bool CardCondition<5, 4>(const std::vector<color>& field)
{
    return (field[0] == BLACK && field[4] == ORANGE && field[8] == ORANGE);
}

const std::vector<bool(*)(const std::vector<color>&)> cardConditions1
{
    CardCondition<1, 0>,  CardCondition<1, 1>,  CardCondition<1, 2>,  CardCondition<1, 3>,
    CardCondition<1, 4>,  CardCondition<1, 5>,  CardCondition<1, 6>,  CardCondition<1, 7>,
    CardCondition<1, 8>,  CardCondition<1, 9>,  CardCondition<1, 10>, CardCondition<1, 11>,
    CardCondition<1, 12>, CardCondition<1, 13>, CardCondition<1, 14>, CardCondition<1, 15>,
    CardCondition<1, 16>, CardCondition<1, 17>, CardCondition<1, 18>, CardCondition<1, 19>,
    CardCondition<1, 20>, CardCondition<1, 21>, CardCondition<1, 22>, CardCondition<1, 23>,
    CardCondition<1, 24>, CardCondition<1, 25>, CardCondition<1, 26>, CardCondition<1, 27>
};

const std::vector<bool(*)(const std::vector<color>&)> cardConditions2
{
    CardCondition<2, 0>,  CardCondition<2, 1>,  CardCondition<2, 2>,  CardCondition<2, 3>,
    CardCondition<2, 4>,  CardCondition<2, 5>,  CardCondition<2, 6>,  CardCondition<2, 7>,
    CardCondition<2, 8>,  CardCondition<2, 9>,  CardCondition<2, 10>, CardCondition<2, 11>,
    CardCondition<2, 12>, CardCondition<2, 13>, CardCondition<2, 14>, CardCondition<2, 15>,
    CardCondition<2, 16>, CardCondition<2, 17>, CardCondition<2, 18>, CardCondition<2, 19>
};

const std::vector<bool(*)(const std::vector<color>&)> cardConditions3
{
    CardCondition<3, 0>,  CardCondition<3, 1>,  CardCondition<3, 2>,  CardCondition<3, 3>,
    CardCondition<3, 4>,  CardCondition<3, 5>,  CardCondition<3, 6>,  CardCondition<3, 7>,
    CardCondition<3, 8>,  CardCondition<3, 9>,  CardCondition<3, 10>, CardCondition<3, 11>,
    CardCondition<3, 12>
};

const std::vector<bool(*)(const std::vector<color>&)> cardConditions5
{
    CardCondition<5, 0>,  CardCondition<5, 1>,  CardCondition<5, 2>,  CardCondition<5, 3>,
    CardCondition<5 , 4>
};

const std::vector<std::vector<Cond>> cardConditions
{
    cardConditions1,
    cardConditions2,
    cardConditions3,
    {},
    cardConditions5
};

