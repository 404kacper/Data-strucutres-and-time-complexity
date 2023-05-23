#pragma once

#include "vector"
#include <queue>

#include "../utilities/ListGraph.h"
#include "../utilities/MatrixGraph.h"
#include "../utilities/Edge.h"
#include "../utilities/Union.h"

class Kruskal {
public:
    // Podobnie jak w primie jedyna roznica jest w dodawaniu krawedzi do kolejki
    static ListGraph findMinimumTreeList(ListGraph &graph);
    static MatrixGraph findMinimumTreeMatrix(MatrixGraph &graph);
};