#pragma once

#include <iostream>
#include "vector"


using namespace std;

class ListGraph {
public:
    struct AdjacentEdge {
        int edgeKey;
        int weight;

        AdjacentEdge(int edge, int weight) : edgeKey(edge), weight(weight) { }
    };
public:
    ListGraph(bool isDirected) {
        this->isDirected = isDirected;
    }
    void addEdge(int from, int to, int weight);
    void print() const;
    void clear();
    // zwracan typ ten sam co dla edges
    vector<AdjacentEdge> getAdjacentVertices(int vertex);
    int getEdgesCount();
    int getVertexCount();
public:
    vector<vector<AdjacentEdge>> edges;
    int edgesCount = 0;
    bool isDirected;
};