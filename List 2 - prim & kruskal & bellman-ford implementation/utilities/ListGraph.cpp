#include "ListGraph.h"

void ListGraph::addEdge(int from, int to, int weight)
{
    // Dodanie wierzcholkow do listy
    int maxSize = max(from, to) + 1;
    if (maxSize > edges.size()) {
        edges.resize(maxSize);
    }

    // Indeks w liscie to indeks wierzcholka
    edges[from].push_back(AdjacentEdge(to, weight));

    // Nie dodawaj do przychodzacego wierzcholka jezeli jest cyklem lub graf jest nieskierowany
    if (!isDirected && from != to)
        edges[to].push_back(AdjacentEdge(from, weight));

    edgesCount++;
}

void ListGraph::print() const
{
    cout << "Reprezentacja listowa: " << endl;
    if (edges.empty()) {
        cout << "Graf jest pusty!" << std::endl;
        return;
    }

    for (int i = 0; i < edges.size(); i++) {
        cout << i << ": ";

        for (int j = 0; j < edges[i].size(); j++) {
            cout << "[" << edges[i][j].edgeKey << ", " << edges[i][j].weight << "]";
            if (j != edges[i].size()-1)
                cout << " -> ";
            else
                cout << " -> NULL";
        }

        cout << endl;
    }

    cout << endl;
}

void ListGraph::clear()
{
    edgesCount = 0;
    edges = vector<vector<AdjacentEdge>>();
}

int ListGraph::getEdgesCount()
{
    return edgesCount;
}

int ListGraph::getVertexCount()
{
    return edges.size();
}

vector<ListGraph::AdjacentEdge> ListGraph::getAdjacentVertices(int vertex)
{
    return edges[vertex];
}
