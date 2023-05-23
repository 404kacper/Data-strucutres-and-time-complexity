#include "BellmanFord.h"

vector<PathNode> BellmanFord::findShortestPath(ListGraph &graph, int from)
{
    auto vertexCount = graph.getVertexCount();

    vector<PathNode> weightsVector(vertexCount);

    if (vertexCount == 0)
        return weightsVector;

    weightsVector[from].weight = 0;
    bool changed;

    for (int i = 0; i < vertexCount - 1; i++) {
        changed = false;

        for (int j = 0; j < vertexCount; j++) {
            // Nie bierz pod uwage nieodwiedzonych
            if (weightsVector[j].weight == INT_MAX)
                continue;

            auto adjacent = graph.getAdjacentVertices(j);
            for (int k = 0; k < adjacent.size(); k++) {
                int to = adjacent[k].edgeKey;
                int weight = adjacent[k].weight;

                // Sprawdz krotsza droge
                if (weightsVector[to].weight >
                    weightsVector[j].weight + weight) {
                    // Zaktualizuj nowa droge
                    weightsVector[to].weight = weightsVector[j].weight + weight;
                    // Zapisz poprzedni wierzcholek
                    weightsVector[to].prev = j;
                    changed = true;
                }
            }
        }
        if (!changed)
            break;
    }

    return weightsVector;
}

vector<PathNode> BellmanFord::findShortestPath(MatrixGraph &graph, int from)
{
    auto matrix = graph.getMatrix();
    int edgesCount = graph.getEdgesCount();
    int vertexCount = graph.getVertexCount();

    vector<PathNode> weightsVector(vertexCount);

    if (vertexCount == 0)
        return weightsVector;

    weightsVector[from].weight = 0;
    bool changed;

    for (int i = 0; i < vertexCount - 1; i++) {
        changed = false;

        for (int j = 0; j < vertexCount; j++) {
            // Nie bierz pod uwage nieodwiedzonych
            if (weightsVector[j].weight == SIZE_MAX)
                continue;

            for (int k = 0; k < edgesCount; k++) {
                int fromEdge, toEdge, weight;

                if (matrix[j][k] >= 0)
                    continue;

                if (matrix[j][k] < 0) {
                    fromEdge = j;
                    for (int x = 0; x < vertexCount; x++) {
                        if (matrix[x][k] > 0)
                            toEdge = x;
                    }
                    weight = matrix[toEdge][k];
                }

                // Sprawdz krotsza droge
                if (weightsVector[toEdge].weight > weightsVector[fromEdge].weight + weight) {
                    // Zaktualizuj nowa droge
                    weightsVector[toEdge].weight = weightsVector[fromEdge].weight + weight;
                    // Zapisz poprzedni wierzcholek
                    weightsVector[toEdge].prev = fromEdge;
                    changed = true;
                }
            }
        }
        if (!changed)
            break;
    }

    return weightsVector;
}

template<typename T>
T BellmanFord::fromToGraph(T &graph, int from, int to)
{
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

template MatrixGraph BellmanFord::fromToGraph(MatrixGraph &graph,int from,int to);
template ListGraph BellmanFord::fromToGraph(ListGraph &graph,int from,int to);