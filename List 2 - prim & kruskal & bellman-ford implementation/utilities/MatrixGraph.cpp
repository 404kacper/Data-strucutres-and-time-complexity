#include "MatrixGraph.h"

void MatrixGraph::addEdge(int from, int to, int weight)
{
    // Dodawanie nowego rzedu
    int newMaxSize = max(from, to) + 1;
    int oldMaxSize = matrix.size();
    if (newMaxSize > oldMaxSize) {
        matrix.resize(newMaxSize);

        int edgesCount = matrix[0].size();
        // Rezerwowanie miejsca w kolumnach
        for (int i = oldMaxSize; i < newMaxSize; i++) {
            matrix[i].resize(edgesCount);
        }
    }

    // Dodawanie krawedzi
    // Dla skierowanych cykl bedzie mial pozytywna wage
    for (int i = 0; i < matrix.size(); i++) {
        if (i == to)
            matrix[i].push_back(weight);
        else if (i == from)
            matrix[i].push_back(isDirected ? -weight : weight);
        else
            matrix[i].push_back(0);
    }
}

int MatrixGraph::getVertexCount(){
    return matrix.size();
}

int MatrixGraph::getEdgesCount(){
    return matrix[0].size();
}

vector<vector<int>>& MatrixGraph::getMatrix(){
    return matrix;
}

void MatrixGraph::print()
{
    cout << "Reprezentacja macierzowa: " << endl;
    if (matrix.empty()) {
        cout <<"Graf jest pusty!" << endl;
        cout << endl;
        return;
    }

    int count = getEdgesCount();
    int vertices = getVertexCount();
    int singleDigitWidth = 5;
    int doubleDigitWidth = 6;

    cout << " ";
    for (int j = 0; j < count; j++) {
        cout << setw(singleDigitWidth) <<"_"<<j;
    }
    cout << endl;

    for (int i = 0; i < vertices; i++) {
        cout << i << "|";

        for (int j = 0; j < count; j++) {
            if(j >= 10) {
                cout << setw(doubleDigitWidth)<<matrix[i][j] <<" ";
            }else {
                cout << setw(singleDigitWidth)<<matrix[i][j] <<" ";
            }
        }
        cout << endl;
    }

    cout << endl;
}

void MatrixGraph::clear()
{
    matrix = vector<vector<int>>{};
}
