#include "Prim.h"

ListGraph Prim::findMinimumTreeList(ListGraph &graph)
{
    int numOfVertices = graph.getVertexCount();

    ListGraph minimumTree(false);
    // less przeladowany operator dla klasy edge
    priority_queue<Edge, vector<Edge>, less<>> minPriorityQueue;

    if (numOfVertices == 0)
        return minimumTree;

    vector<bool> visited(numOfVertices);
    int curVertex;

    // Zacznij od zera
    visited[0] = true;
    curVertex = 0;

    // Dodawanie krawedzi do kolejki dla poczatkowego wierzcholka
    pushAdjEdgesList(graph, minPriorityQueue, visited, curVertex);

    // Iterowanie do minimalnej ilosci krawedzi w grafie spojnym
    for (int i = 0; i < numOfVertices - 1; ) {

        // Zdejmowanie krawedzi o najmniejszej wadze z kolejki
        Edge lowestEdgeByWeight = minPriorityQueue.top();
        minPriorityQueue.pop();

        // Jezeli nie byl odwiedzony to oznaczamy jako odwiedzony
        if (!visited[lowestEdgeByWeight.to]) {
            curVertex = lowestEdgeByWeight.to;
            visited[curVertex] = true;
            minimumTree.addEdge(lowestEdgeByWeight.from, lowestEdgeByWeight.to, lowestEdgeByWeight.weight);

            // Dodawanie krawedzi do kolejki dla kolejnych wierzcholkow
            pushAdjEdgesList(graph, minPriorityQueue, visited, curVertex);
            i++;
        }
    }

    return minimumTree;
}

MatrixGraph Prim::findMinimumTreeMatrix(MatrixGraph &graph)
{
    int numOfVertices = graph.getVertexCount();

    MatrixGraph minimumTree(false);

    if (numOfVertices == 0)
        return minimumTree;

    // less przeladowany operator dla klasy edge
    priority_queue<Edge, vector<Edge>, less<>> minPriorityQueue;
    vector<bool> visited(numOfVertices);
    int curVertex;

    // Zacznij od zera
    visited[0] = true;
    curVertex = 0;

    // Dodawanie krawedzi do kolejki dla poczatkowego wierzcholka
    pushAdjEdgesMatrix(graph,minPriorityQueue,visited,numOfVertices,curVertex);

    // Dalej analogicznie jak dla listy
    for (int i = 0; i < numOfVertices - 1; ) {
        Edge lowestEdgeByWeight = minPriorityQueue.top();
        minPriorityQueue.pop();

        if (!visited[lowestEdgeByWeight.to]) {
            curVertex = lowestEdgeByWeight.to;
            visited[curVertex] = true;
            minimumTree.addEdge(lowestEdgeByWeight.from, lowestEdgeByWeight.to, lowestEdgeByWeight.weight);

            pushAdjEdgesMatrix(graph,minPriorityQueue,visited,numOfVertices,curVertex);
            i++;
        }
    }

    return minimumTree;
}

void Prim::pushAdjEdgesList(ListGraph& graph, priority_queue<Edge, vector<struct Edge>, less<>>& minPriorityQueue, vector<bool> &visited, int vertex) {
    auto adjacent = graph.getAdjacentVertices(vertex);
    for (auto & i : adjacent) {
        if (!visited[i.edgeKey]){
            minPriorityQueue.push(Edge(vertex, i.edgeKey, i.weight));
        }
    }
}

void Prim::pushAdjEdgesMatrix(MatrixGraph &graph, priority_queue<Edge, vector<struct Edge>, less<>> &minPriorityQueue, vector<bool> &visited, int numOfVertices, int vertex) {
    int numOfEdges = graph.getEdgesCount();
    auto matrix = graph.getMatrix();

    for (int i = 0; i < numOfEdges; i++) {
            // Znajdz pierwsza nie zerowa liczbe w rzedzie
            if (matrix[vertex][i] != 0) {
                // Znajdz druga nie zerowa liczbe w kolumnie
                for (int j = 0; j < numOfVertices; j++) {
                    // Albo drugi wierzcholek albo cykl
                    if (matrix[j][i] != 0 || j == vertex) {
                        // Sprawdz czy odwiedzony, jezeli nie to dodaj do kolejki
                        if (visited[j]) {
                            continue;
                        } else {
                            minPriorityQueue.push(Edge(vertex, j, matrix[j][i]));
                        }
                    }
                }
            }
    }
}



