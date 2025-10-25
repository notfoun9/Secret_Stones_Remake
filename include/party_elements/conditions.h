#pragma once
#include <vector>

typedef bool (*Cond)(const std::vector<int>& field);

Cond GetCondition(int cost, int id);

