#pragma once

#include <random>

#include "../MatrixGraph.h"
#include "../ListGraph.h"

using namespace std;

class GraphGenerator {
public:
    // funkcja przyjmujaca i liste i macierz - uzyta w menu
    // generuje graf nieskierowany
    int randomForMenu(ListGraph &list, MatrixGraph &matrix, int vertexCount, int fillFraction, bool isDirected);
    // funkcja szablonowa przyjmujaca albo liste albo macierz - uzyta w pomiarze czasu
    template <typename GraphType>
    GraphType randomForTime(GraphType &graph, int vertexCount, double fillFraction, bool isDirected);

};
