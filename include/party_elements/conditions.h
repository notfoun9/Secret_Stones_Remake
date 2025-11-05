#pragma once
#include <vector>
#include <party_elements/colors.h>

typedef const std::vector<color> FieldState;
typedef bool (*Cond)(FieldState& field);

Cond GetCondition(int cost, int id);

