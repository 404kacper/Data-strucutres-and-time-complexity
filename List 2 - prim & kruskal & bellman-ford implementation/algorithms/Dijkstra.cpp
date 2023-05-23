#include "Dijkstra.h"

vector<PathNode> Dijkstra::findShortestPath(ListGraph &graph, int from)
{
    auto vertexCount = graph.getVertexCount();

    priority_queue<QueueNode, vector<QueueNode>, less<>> queue;
    vector<PathNode> weightsVector(vertexCount);

    if (vertexCount == 0)
        return weightsVector;

    // Inicializacja algorytmu
    queue.push(QueueNode(from, 0));
    weightsVector[from].weight = 0;
    weightsVector[from].prev = INT_MAX;

    while (!queue.empty()) {
        auto node = queue.top();
        auto curVertex = node.vertex;
        queue.pop();

        if (node.distance != weightsVector[curVertex].weight)
            continue;

        auto adjacent = graph.getAdjacentVertices(curVertex);

        // Przeszukiwanie sasiadow
        for (int i = 0; i < adjacent.size(); i++) {
            auto newVertex = adjacent[i].edgeKey;
            // Wyszukiwanie krotszej drogi
            if (weightsVector[newVertex].weight > weightsVector[curVertex].weight + adjacent[i].weight) {
                // Aktualizacja wagi
                weightsVector[newVertex].weight = weightsVector[curVertex].weight + adjacent[i].weight;
                // Polacz wierzcholek z droga
                weightsVector[newVertex].prev = curVertex;
                // Aktualizacja drogi dla nowego wierzcholka
                queue.push(QueueNode(newVertex, weightsVector[newVertex].weight));
            }
        }
    }

    return weightsVector;
}

vector<PathNode> Dijkstra::findShortestPath(MatrixGraph &graph, int from)
{
    auto matrix = graph.getMatrix();
    auto edgesCount = graph.getEdgesCount();
    auto vertexCount = graph.getVertexCount();

    priority_queue<QueueNode, vector<QueueNode>, less<>> queue;
    vector<PathNode> weightsVector(vertexCount);

    if (vertexCount == 0)
        return weightsVector;

    // Inicializacja algorytmu
    queue.push(QueueNode(from, 0));
    weightsVector[from].weight = 0;

    while (!queue.empty()) {
        auto node = queue.top();
        auto curVertex = node.vertex;
        queue.pop();

        if (node.distance != weightsVector[curVertex].weight)
            continue;

        // Dodawaj do kolejki kolejne wierzcholki
        for (int i = 0; i < edgesCount; i++) {
            // Znajdz wierzcholek przychodzacy
            if (matrix[curVertex][i] >= 0)
                continue;

            for (int j = 0; j < vertexCount; j++) {
                // Znajdz wierzcholek wychodzacy
                if (matrix[j][i] <= 0)
                    continue;

                // Wyszukiwanie krotszej drogi
                if (weightsVector[j].weight > weightsVector[curVertex].weight + matrix[j][i]) {
                    // Aktualizacja wagi
                    weightsVector[j].weight = weightsVector[curVertex].weight + matrix[j][i];
                    // Polacz wierzcholek z droga
                    weightsVector[j].prev = curVertex;
                    // Aktualizacja drogi dla nowego wierzcholka
                    queue.push(QueueNode(j, weightsVector[j].weight));
                }
            }
        }
    }

    return weightsVector;
}

template<typename T>
T Dijkstra::fromToGraph(T &graph, int from, int to) {
    T result(true);

    // Jeden z wierzcholkow poza zasiegiem
    if (graph.getVertexCount() < max(from, to) + 1)
        return result;

    // Brak wierzcholkow
    if (graph.getVertexCount() == 0)
        return result;

    // Obliczona sciezka
    auto pathWeights = findShortestPath(graph, from);

    // Brak sciezki
    if (pathWeights[to].weight == SIZE_MAX)
        return result;

    auto current = to;

    // Tablica do odwrocenia
    vector<vector<int>> reversedResult;

    while (current != from) {
        int prev = pathWeights[current].prev;
        // Dodawanie kolejnych krawedzi do wektora
        reversedResult.push_back({prev, (int)current, (int)(pathWeights[current].weight - pathWeights[prev].weight)});
        // Przejscie do kolejnego wierzcholka
        current = prev;
    }

    // Dodawanie krawedzi w poprawnej kolejnosci
    for (int i = reversedResult.size()-1; i >= 0; --i) {
        result.addEdge(reversedResult[i][0],reversedResult[i][1], reversedResult[i][2]);
    }

    return result;
}

template MatrixGraph Dijkstra::fromToGraph(MatrixGraph &graph, int from, int to);
template ListGraph Dijkstra::fromToGraph(ListGraph &graph, int from, int to);