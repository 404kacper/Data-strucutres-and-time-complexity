#include "Kruskal.h"

ListGraph Kruskal::findMinimumTreeList(ListGraph &graph)
{
    ListGraph minimumTree(false);
    priority_queue<Edge, vector<Edge>, less<>> minPriorityQueue;

    int numOfVertices = graph.getVertexCount();
    Union forest(numOfVertices);


    if (numOfVertices == 0)
        return minimumTree;

    // Wszystkie krawedzie na stos
    for (int i = 0; i < numOfVertices; i++) {
        auto adjacent = graph.getAdjacentVertices(i);
        for (auto adj : adjacent) {
            // Nie dodawaj tego samego wierzcholka
            if (adj.edgeKey > i) {
                minPriorityQueue.push(Edge(i, adj.edgeKey, adj.weight));
            }
        }
    }

    // Podobnie jak w primie - laczenie krawedzi do warunku drzewa pelnego
    for (int i = 0; i < numOfVertices - 1; ) {
        // Jezeli kolejka bedzie pusta przed koncem petli to znaczy ze drzewo minimalne nie istnieje
        if (minPriorityQueue.empty()) {
            minimumTree = ListGraph(false);
            break;
        }

        // Wydobywanie krawedzi z kolejki i wyszukiwanie jej odpowiednikow
        auto node = minPriorityQueue.top();
        int aDeputy = forest.findNode(node.from);
        int bDeputy = forest.findNode(node.to);

        // Nie lacz cykli
        if (aDeputy != bDeputy) {
            // Laczenie wierzcholkow
            forest.unionNodes(node.from, node.to);
            // Dodawanie krawedzi do drzewa
            minimumTree.addEdge(node.from, node.to, node.weight);
            i++;
        }
        minPriorityQueue.pop();
    }

    return minimumTree;
}

MatrixGraph Kruskal::findMinimumTreeMatrix(MatrixGraph &graph)
{
    MatrixGraph minimumTree(false);
    priority_queue<Edge, vector<Edge>, less<>> minPriorityQueue;

    // Ilosc rzedow
    int numOfVertices = graph.getVertexCount();
    Union forest(numOfVertices);

    // Ilosc kolumn
    int edges = graph.getEdgesCount();

    auto matrix = graph.getMatrix();

    if (numOfVertices == 0)
        return minimumTree;

    // Przeszukaj kolumny
    for (int i = 0; i < edges; i++) {
        int j = 0;
        int vertex;

        // Znajdz pierwsza wage
        for (j; j < numOfVertices; j++) {
            if (matrix[j][i] > 0) {
                vertex = j++;
                break;
            }
        }

        // Znajdz druga wage - jezeli nie ma to oznacza cykl - nie dodawaj cyklu do kolejki
        for (j; j < numOfVertices; j++) {
            if (matrix[j][i] > 0) {
                minPriorityQueue.push(Edge(vertex, j, matrix[j][i]));
                break;
            }
        }
    }

    // Podobnie jak w primie - laczenie krawedzi do warunku drzewa pelnego
    for (int i = 0; i < numOfVertices - 1; ) {
        // Jezeli kolejka bedzie pusta przed koncem petli to znaczy ze drzewo minimalne nie istnieje
        if (minPriorityQueue.empty()) {
            minimumTree = MatrixGraph(false);
            break;
        }

        // Wydobywanie krawedzi z kolejki i wyszukiwanie jej odpowiednikow
        auto node = minPriorityQueue.top();
        int aDeputy = forest.findNode(node.from);
        int bDeputy = forest.findNode(node.to);

        // Nie lacz cykli
        if (aDeputy != bDeputy) {
            // Laczenie wierzcholkow
            forest.unionNodes(node.from, node.to);
            // Dodawanie krawedzi do drzewa
            minimumTree.addEdge(node.from, node.to, node.weight);
            i++;
        }
        minPriorityQueue.pop();
    }

    return minimumTree;
}

