#pragma once

#include <iostream>
#include <vector>
#include "iomanip"
;
using namespace std;

class MatrixGraph {
    vector<vector<int>> matrix;
    bool isDirected;

public:
    MatrixGraph(bool isDirected) {
        this->isDirected = isDirected;
    }

    // - krawed wychodzaca / + krawedz wchodzaca
    void addEdge(int from, int to, int weight); // funkcja dodajaca krawedz do macierzy - od wierzcholka do wierzcholka o okreslonej wadze
    int getVertexCount(); // funkcja get zwracajaca rozmiar pierwszego wektora - wierszy macierzy
    int getEdgesCount(); // funkcja get zliczająca ilosc krawedzi - kolumn w macierzy
    vector<vector<int>>& getMatrix(); // funkcja get zwracajaca adres macierzy
    void print(); // wyswietlanie macierzy
    void clear(); // przypisanie nowo utworzonego pustego wektora do zmiennej matrix
};