#pragma once

#include <iostream>
#include <fstream>
#include <vector>

// utils
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "generator/GraphGenerator.h"
#include "stopwatch/Stopwatch.h"

// algos
#include "../algorithms/Prim.h"
#include "../algorithms/Kruskal.h"
#include "../algorithms/Dijkstra.h"
#include "../algorithms/BellmanFord.h"

using namespace std;


int getInputFromUser()
{
    int val;
    cin >> val;

    return val;
}


void readFile(ListGraph &list, MatrixGraph &matrix)
{
    ifstream file("input.txt");
    if (!file.is_open())
        throw runtime_error("Plik nie istnieje");

    int edges, vertices;
    file >> edges >> vertices;

    for (int i = edges; i > 0; i--) {
        int from, to, weight;
        file >> from >> to >> weight;

        list.addEdge(from, to, weight);
        matrix.addEdge(from, to, weight);
    }
}

void treeMenu() {
    int input;
    ListGraph listGraph(false);
    MatrixGraph matrixGraph(false);
    GraphGenerator generator;

    while (true) {

        cout << "1 - Odczyt z pliku\n"
             << "2 - Losowe zapelnienie grafu\n"
             << "3 - Algorytm Prima\n"
             << "4 - Algorytm Kruskala\n"
             << "5 - Wyswietlenie grafu\n"
             << "6 - Wyjscie\n";
        input = getInputFromUser();

        switch (input) {
            case 1:
                listGraph.clear();
                matrixGraph.clear();
                readFile(listGraph, matrixGraph);
                break;
            case 2: {
                listGraph.clear();
                matrixGraph.clear();
                cout << "Liczba wierzcholkow: \n";
                auto count = getInputFromUser();
                cout << "Zapelnienie grafu (liczba calkowita): \n";
                auto fill = getInputFromUser();
                int errorCode = generator.randomForMenu(listGraph, matrixGraph, count, fill, false);
                if (errorCode != 0) {
                    cout << "Zadeklarowane zapelnienie grafu jest zbyt male zeby utworzyc graf spojny!" << endl;
                }
                break;
            }
            case 3: {
                auto resultList = Prim::findMinimumTreeList(listGraph);
                auto resultMatrix = Prim::findMinimumTreeMatrix(matrixGraph);
                resultList.print();
                resultMatrix.print();
                break;
            }
            case 4: {
                auto resultList = Kruskal::findMinimumTreeList(listGraph);
                auto resultMatrix = Kruskal::findMinimumTreeMatrix(matrixGraph);
                resultList.print();
                resultMatrix.print();
                break;
            }
            case 5:
                listGraph.print();
                matrixGraph.print();
                break;
            case 6:
                return;
                break;
        }
    }

}

void pathMenu()
{
    ListGraph listGraph(true);
    MatrixGraph matrixGraph(true);
    GraphGenerator generator;
    int input;

    while (true) {
        cout << "1 - Odczyt z pliku\n"
             << "2 - Losowe zapelnienie grafu\n"
             << "3 - Algorytm Dijkstry\n"
             << "4 - Algorytm Bellmana-Forda\n"
             << "5 - Wyswietlenie grafu\n"
             << "6 - Wyjscie\n";
        input = getInputFromUser();

        switch (input) {
            case 1:
                listGraph.clear();
                matrixGraph.clear();
                readFile(listGraph, matrixGraph);
                break;
            case 2: {
                listGraph.clear();
                matrixGraph.clear();
                cout << "Liczba wierzcholkow: \n";
                int count = getInputFromUser();
                cout << "Zapelnienie grafu (liczba calkowita): \n";
                int fill = getInputFromUser();
                int errorCode = generator.randomForMenu(listGraph, matrixGraph, count, fill, true);
                if (errorCode != 0) {
                    cout << "Zadeklarowane zapelnienie grafu jest zbyt male zeby utworzyc graf spojny!" << endl;
                }
                break;
            }
            case 3: {
                cout << "Wierzcholek poczatkowy: \n";
                int from = getInputFromUser();
                cout << "Wierzcholek koncowy: \n";
                int to = getInputFromUser();

                auto list = Dijkstra::fromToGraph(listGraph, from, to);
                auto matrix = Dijkstra::fromToGraph(matrixGraph, from, to);
                list.print();
                matrix.print();
                break;
            }
            case 4: {
                cout << "Wierzcholek poczatkowy: \n";
                auto from = getInputFromUser();
                cout << "Wierzcholek koncowy: \n";
                auto to = getInputFromUser();

                auto List = BellmanFord::fromToGraph(listGraph, from, to);
                auto Matrix = BellmanFord::fromToGraph(matrixGraph, from, to);
                List.print();
                Matrix.print();
                break;
            }
            case 5:
                listGraph.print();
                matrixGraph.print();
                break;
            case 6:
                return;
                break;
        }
    }
}

int menu()
{
    int input;
    cout << "1 - test automatyczny\n" << "2 - test manualny\n";
    input = getInputFromUser();

    if (input == 1) {
        Stopwatch st;
        st.start();
        cout << "Wprowadz znak zeby zakonczyc program" << endl;
        string finish;
        cin >> finish;
        return 0;
    }

    cout << "Wybierz problem:\n" << "1 - Minimalne drzewo rozpinajace\n" << "2 - Najkrotsza sciezka\n";
    input = getInputFromUser();

    switch (input) {
        case 1:
            treeMenu();
            break;
        case 2:
            pathMenu();
            break;
    }

    cout << "Wprowadz znak zeby zakonczyc program" << endl;
    string finish;
    cin >> finish;

    return 0;
}