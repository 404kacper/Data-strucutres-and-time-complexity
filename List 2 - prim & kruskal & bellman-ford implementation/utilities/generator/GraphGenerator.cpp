#include "GraphGenerator.h"

default_random_engine defEngine(time(0));

template <typename GraphType>
GraphType GraphGenerator::randomForTime(GraphType &graph, int vertexCount, double fillFraction, bool isDirected)
{
    double maxEdges;
    double minEdgesForConnectedGraph;

    // ze wzorow: dla skierowanego e = v * (v-1) | dla nieskierowanego e = (v * (v-1))/2
    maxEdges = vertexCount * (vertexCount - 1);
    if (!isDirected)
        maxEdges /= 2;

    // 0.01 bo fill fraction to int
    maxEdges *= 0.01 * fillFraction;
    minEdgesForConnectedGraph = vertexCount - 1;

    // Sprawdzenie czy wprowadzone zapelnienie pozwala na utworzenie grafu spojnego
    if (minEdgesForConnectedGraph > maxEdges) {
        throw runtime_error("Wygenerowane zapelnienie grafu jest zbyt male zeby utworzyc graf pelny!\nSprawdz GraphGenerator.cpp!");
    }

    // W pierwszej kolejnosci generowanie grafu spojnego
    for (int i = 0; i < minEdgesForConnectedGraph; ++i) {
        uniform_int_distribution<int> weightsDistro(1, 99);
        int weight = weightsDistro(defEngine);
        graph.addEdge(i,i+1, weight);
        maxEdges--;
    }

    // Potem losowe dodwanie krawedzi do grafu pelnego spojnego
    for (int i = 0; i < maxEdges; i++) {
        uniform_int_distribution<int> verticesDistro(0, vertexCount);
        uniform_int_distribution<int> weightsDistro(1, INT_MAX);

        int from = verticesDistro(defEngine);
        int to = verticesDistro(defEngine);
        int weight = weightsDistro(defEngine);

        graph.addEdge(from, to, weight);
    }
    return graph;
}
template ListGraph GraphGenerator::randomForTime(ListGraph &graph,int vertexCount,double fillFraction,bool isDirected);
template MatrixGraph GraphGenerator::randomForTime(MatrixGraph &graph,int vertexCount,double fillFraction,bool isDirected);

int GraphGenerator::randomForMenu(ListGraph &list, MatrixGraph &matrix, int vertexCount, int fillFraction, bool isDirected)
{
    double maxEdges;
    double minEdgesForConnectedGraph;

    // ze wzorow: dla skierowanego e = v * (v-1) | dla nieskierowanego e = (v * (v-1))/2
    maxEdges = vertexCount * (vertexCount - 1);
    if (!isDirected)
        maxEdges /= 2;

    maxEdges *= 0.01 * fillFraction;
    minEdgesForConnectedGraph = vertexCount - 1;

    // Sprawdzenie czy wprowadzone zapelnienie pozwala na utworzenie grafu spojnego
    if (minEdgesForConnectedGraph > maxEdges) {
        return 1;
    }

    // W pierwszej kolejnosci generowanie grafu spojnego
    for (int i = 0; i < minEdgesForConnectedGraph; ++i) {
        uniform_int_distribution<int> weightsDistro(1, 99);
        int weight = weightsDistro(defEngine);
        list.addEdge(i,i+1, weight);
        matrix.addEdge(i, i+1, weight);
        maxEdges--;
    }

    // Potem losowe dodwanie do grafu pelnego spojnego
    for (int i = 0; i < maxEdges; i++) {
        uniform_int_distribution<int> verticesDistro(0, vertexCount-1);
        uniform_int_distribution<int> weightsDistro(1, 99);

        int from = verticesDistro(defEngine);
        int to = verticesDistro(defEngine);
        int weight = weightsDistro(defEngine);

        list.addEdge(from, to, weight);
        matrix.addEdge(from, to, weight);
    }
    return 0;
}
