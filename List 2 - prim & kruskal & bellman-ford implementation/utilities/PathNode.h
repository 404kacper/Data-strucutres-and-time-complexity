#pragma once

#include <cstdlib>
#include "../utilities/MatrixGraph.h"
#include "../utilities/ListGraph.h"

struct PathNode {
    int weight = INT_MAX;
    int prev = INT_MAX;

    PathNode(int weight, int &prev) : weight(weight), prev(prev) { }
    PathNode() {};

public:
    bool operator==(PathNode& other) {
        return weight == other.weight && prev == other.prev;
    }
};