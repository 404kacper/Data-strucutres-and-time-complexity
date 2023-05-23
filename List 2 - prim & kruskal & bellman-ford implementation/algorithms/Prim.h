#pragma once

#include "vector"
#include <queue>

#include "../utilities/MatrixGraph.h"
#include "../utilities/ListGraph.h"
#include "../utilities/Edge.h"


class Prim {
public:
    // ! obydwa wyszukiwania wyglądają identycznie, jedyne co je rozroznia to sposob dodawania do kolejki
    // wyszukiwanie dla listy
    static ListGraph findMinimumTreeList(ListGraph &graph);
    // wyszukiwanie dla macierzy
    static MatrixGraph findMinimumTreeMatrix(MatrixGraph &graph);
    // dodwanie krawedzi do kolejki
    static void pushAdjEdgesList (ListGraph& graph, priority_queue<Edge, vector<struct Edge>, less<>>& minPriorityQueue, vector<bool> &visited, int vertex);
    static void pushAdjEdgesMatrix (MatrixGraph& graph, priority_queue<Edge, vector<struct Edge>, less<>>& minPriorityQueue, vector<bool> &visited,int numOfVertices, int vertex);

};