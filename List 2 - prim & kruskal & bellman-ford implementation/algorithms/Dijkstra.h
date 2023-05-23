#pragma once

#include <cstdlib>
#include "queue"
#include "../utilities/MatrixGraph.h"
#include "../utilities/ListGraph.h"
#include "../utilities/PathNode.h"

class Dijkstra {
    struct QueueNode {
        int distance;
        int vertex;

        bool operator<(QueueNode &other) {
            return distance < other.distance;
        }
        QueueNode(int vertex, int distance) : distance(distance), vertex(vertex) {}
    };

public:
    static vector<PathNode> findShortestPath(ListGraph &graph, int from);

    static vector<PathNode> findShortestPath(MatrixGraph &graph, int from);

    template<typename T>
    static T fromToGraph(T &graph, int from, int to);
};