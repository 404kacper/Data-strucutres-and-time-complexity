#pragma once
#include "vector"
#include "../utilities/ListGraph.h"
#include "../utilities/MatrixGraph.h"
#include "../utilities/PathNode.h"

class BellmanFord {

public:
    static vector<PathNode> findShortestPath(ListGraph &graph, int from);

    static vector<PathNode> findShortestPath(MatrixGraph &graph, int from);

    // Identyczna jak dla dijkstry
    template<typename T>
    static T fromToGraph(T &graph,int from,int to);
};