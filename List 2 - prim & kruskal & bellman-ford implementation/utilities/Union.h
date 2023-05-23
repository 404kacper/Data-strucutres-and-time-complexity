#pragma once

#include <climits>
#include "vector"

using namespace std;

class Union {
    struct Node {
        int deputy = INT_MAX;
        int rank = 0;
    };

    vector<Node> container;

public:
    Union(int size);
    // Wyszukuje indeksu wi
    int &findNode(int &node);
    // Laczy dwa wierzcholki
    void unionNodes(int &a, int &b);
};