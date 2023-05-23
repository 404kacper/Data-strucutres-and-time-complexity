#include <vector>
#include <chrono>

#include "../generator/GraphGenerator.h"
#include "../../algorithms/Prim.h"
#include "../../algorithms/Kruskal.h"
#include "../../algorithms/Dijkstra.h"
#include "../../algorithms/BellmanFord.h"

#define time_unit chrono::microseconds

using namespace std;

class Stopwatch {
public:
    int iterator = 0;
    chrono::duration<double> timePassed = std::chrono::duration<double>::zero();
    vector<int> size = {25,50,70,80,100};
    vector<int> fill = {25, 50, 75, 99};
    int times = 15;
    double timeForEachFill = 0;
    double averageTimeForFillFactor = 0;
    vector<vector<double>> results;

    void start() {
        cout << "Pomiar czasu dla reprezentacji listy algorytmu Prima...\n" << endl;
            for (int j = 0; j < size.size(); ++j) {
                // Pusta tablica dla kazdego wypelnienia
                results.push_back({});
                for (int k = 0; k < fill.size();++k) {
                    for (int i = 0; i < times; ++i) {
                        ListGraph list(false);
                        list = generateGraph(list, size[j], fill[k], false);
                        auto startTime = chrono::high_resolution_clock::now();
                        Prim::findMinimumTreeList(list);
                        auto finishTime = chrono::high_resolution_clock::now();
                        auto time = chrono::duration_cast<time_unit>(finishTime - startTime);
                        timeForEachFill += time.count();
                    }
                    averageTimeForFillFactor += timeForEachFill/times;
                    results[j].push_back(averageTimeForFillFactor);
                    // Pomiar wartosci od nowa
                    timeForEachFill = 0;
                    averageTimeForFillFactor = 0;
                }
            }

        for (int i = 0; i < size.size(); ++i) {
            for (int j = 0; j < fill.size(); ++j) {
                cout << "Czas dla " << size[i] << " wierzcholkow i wypelnienia "<< fill[j] << "% : " << results[i][j] << endl;
            }
            cout << endl;
        }

        results = {};

        cout << "Pomiar czasu dla reprezentacji macierzy algorytmu Prima...\n" << endl;
        for (int j = 0; j < size.size(); ++j) {
            // Pusta tablica dla kazdego wypelnienia
            results.push_back({});
            for (int k = 0; k < fill.size();++k) {
                for (int i = 0; i < times; ++i) {
                    MatrixGraph matrix(false);
                    matrix = generateGraph(matrix, size[j], fill[k], false);
                    auto startTime = chrono::high_resolution_clock::now();
                    Prim::findMinimumTreeMatrix(matrix);
                    auto finishTime = chrono::high_resolution_clock::now();
                    auto time = chrono::duration_cast<time_unit>(finishTime - startTime);
                    timeForEachFill += time.count();
                }
                averageTimeForFillFactor += timeForEachFill/times;
                results[j].push_back(averageTimeForFillFactor);
                // Pomiar wartosci od nowa
                timeForEachFill = 0;
                averageTimeForFillFactor = 0;
            }
        }

        for (int i = 0; i < size.size(); ++i) {
            for (int j = 0; j < fill.size(); ++j) {
                cout << "Czas dla " << size[i] << " wierzcholkow i wypelnienia "<< fill[j] << "% : " << results[i][j] << endl;
            }
            cout << endl;
        }

        results = {};

        cout << "Pomiar czasu dla reprezentacji listy algorytmu Kruskala...\n" << endl;
        for (int j = 0; j < size.size(); ++j) {
            // Pusta tablica dla kazdego wypelnienia
            results.push_back({});
            for (int k = 0; k < fill.size();++k) {
                for (int i = 0; i < times; ++i) {
                    ListGraph list(false);
                    list = generateGraph(list, size[j], fill[k], false);
                    auto startTime = chrono::high_resolution_clock::now();
                    Kruskal::findMinimumTreeList(list);
                    auto finishTime = chrono::high_resolution_clock::now();
                    auto time = chrono::duration_cast<time_unit>(finishTime - startTime);
                    timeForEachFill += time.count();
                }
                averageTimeForFillFactor += timeForEachFill/times;
                results[j].push_back(averageTimeForFillFactor);
                // Pomiar wartosci od nowa
                timeForEachFill = 0;
                averageTimeForFillFactor = 0;
            }
        }

        for (int i = 0; i < size.size(); ++i) {
            for (int j = 0; j < fill.size(); ++j) {
                cout << "Czas dla " << size[i] << " wierzcholkow i wypelnienia "<< fill[j] << "% : " << results[i][j] << endl;
            }
            cout << endl;
        }

        results = {};

        cout << "Pomiar czasu dla reprezentacji macierzy algorytmu Kruskala...\n" << endl;
        for (int j = 0; j < size.size(); ++j) {
            // Pusta tablica dla kazdego wypelnienia
            results.push_back({});
            for (int k = 0; k < fill.size();++k) {
                for (int i = 0; i < times; ++i) {
                    MatrixGraph matrix(false);
                    matrix = generateGraph(matrix, size[j], fill[k], false);
                    auto startTime = chrono::high_resolution_clock::now();
                    Kruskal::findMinimumTreeMatrix(matrix);
                    auto finishTime = chrono::high_resolution_clock::now();
                    auto time = chrono::duration_cast<time_unit>(finishTime - startTime);
                    timeForEachFill += time.count();
                }
                averageTimeForFillFactor += timeForEachFill/times;
                results[j].push_back(averageTimeForFillFactor);
                // Pomiar wartosci od nowa
                timeForEachFill = 0;
                averageTimeForFillFactor = 0;
            }
        }

        for (int i = 0; i < size.size(); ++i) {
            for (int j = 0; j < fill.size(); ++j) {
                cout << "Czas dla " << size[i] << " wierzcholkow i wypelnienia "<< fill[j] << "% : " << results[i][j] << endl;
            }
            cout << endl;
        }

        results = {};

        cout << "Pomiar czasu dla reprezentacji listy algorytmu Dijkstry...\n" << endl;
        for (int j = 0; j < size.size(); ++j) {
            // Pusta tablica dla kazdego wypelnienia
            results.push_back({});
            for (int k = 0; k < fill.size();++k) {
                for (int i = 0; i < times; ++i) {
                    ListGraph list(false);
                    list = generateGraph(list, size[j], fill[k], false);
                    auto startTime = chrono::high_resolution_clock::now();
                    Dijkstra::findShortestPath(list, 0);
                    auto finishTime = chrono::high_resolution_clock::now();
                    auto time = chrono::duration_cast<time_unit>(finishTime - startTime);
                    timeForEachFill += time.count();
                }
                averageTimeForFillFactor += timeForEachFill/times;
                results[j].push_back(averageTimeForFillFactor);
                // Pomiar wartosci od nowa
                timeForEachFill = 0;
                averageTimeForFillFactor = 0;
            }
        }

        for (int i = 0; i < size.size(); ++i) {
            for (int j = 0; j < fill.size(); ++j) {
                cout << "Czas dla " << size[i] << " wierzcholkow i wypelnienia "<< fill[j] << "% : " << results[i][j] << endl;
            }
            cout << endl;
        }

        results = {};

        cout << "Pomiar czasu dla reprezentacji macierzy algorytmu Dijkstry...\n" << endl;
        for (int j = 0; j < size.size(); ++j) {
            // Pusta tablica dla kazdego wypelnienia
            results.push_back({});
            for (int k = 0; k < fill.size();++k) {
                for (int i = 0; i < times; ++i) {
                    MatrixGraph matrix(false);
                    matrix = generateGraph(matrix, size[j], fill[k], false);
                    auto startTime = chrono::high_resolution_clock::now();
                    Kruskal::findMinimumTreeMatrix(matrix);
                    auto finishTime = chrono::high_resolution_clock::now();
                    auto time = chrono::duration_cast<time_unit>(finishTime - startTime);
                    timeForEachFill += time.count();
                }
                averageTimeForFillFactor += timeForEachFill/times;
                results[j].push_back(averageTimeForFillFactor);
                // Pomiar wartosci od nowa
                timeForEachFill = 0;
                averageTimeForFillFactor = 0;
            }
        }

        for (int i = 0; i < size.size(); ++i) {
            for (int j = 0; j < fill.size(); ++j) {
                cout << "Czas dla " << size[i] << " wierzcholkow i wypelnienia "<< fill[j] << "% : " << results[i][j] << endl;
            }
            cout << endl;
        }

        results = {};

        cout << "Pomiar czasu dla reprezentacji listy algorytmu Bellmana-Forda...\n" << endl;
        for (int j = 0; j < size.size(); ++j) {
            // Pusta tablica dla kazdego wypelnienia
            results.push_back({});
            for (int k = 0; k < fill.size();++k) {
                for (int i = 0; i < times; ++i) {
                    ListGraph list(false);
                    list = generateGraph(list, size[j], fill[k], false);
                    auto startTime = chrono::high_resolution_clock::now();
                    BellmanFord::findShortestPath(list, 0);
                    auto finishTime = chrono::high_resolution_clock::now();
                    auto time = chrono::duration_cast<time_unit>(finishTime - startTime);
                    timeForEachFill += time.count();
                }
                averageTimeForFillFactor += timeForEachFill/times;
                results[j].push_back(averageTimeForFillFactor);
                // Pomiar wartosci od nowa
                timeForEachFill = 0;
                averageTimeForFillFactor = 0;
            }
        }

        for (int i = 0; i < size.size(); ++i) {
            for (int j = 0; j < fill.size(); ++j) {
                cout << "Czas dla " << size[i] << " wierzcholkow i wypelnienia "<< fill[j] << "% : " << results[i][j] << endl;
            }
            cout << endl;
        }

        results = {};

        cout << "Pomiar czasu dla reprezentacji macierzy algorytmu Bellmana-Forda...\n" << endl;
        for (int j = 0; j < size.size(); ++j) {
            // Pusta tablica dla kazdego wypelnienia
            results.push_back({});
            for (int k = 0; k < fill.size();++k) {
                for (int i = 0; i < times; ++i) {
                    MatrixGraph matrix(false);
                    matrix = generateGraph(matrix, size[j], fill[k], false);
                    auto startTime = chrono::high_resolution_clock::now();
                    BellmanFord::findShortestPath(matrix,0);
                    auto finishTime = chrono::high_resolution_clock::now();
                    auto time = chrono::duration_cast<time_unit>(finishTime - startTime);
                    timeForEachFill += time.count();
                }
                averageTimeForFillFactor += timeForEachFill/times;
                results[j].push_back(averageTimeForFillFactor);
                // Pomiar wartosci od nowa
                timeForEachFill = 0;
                averageTimeForFillFactor = 0;
            }
        }

        for (int i = 0; i < size.size(); ++i) {
            for (int j = 0; j < fill.size(); ++j) {
                cout << "Czas dla " << size[i] << " wierzcholkow i wypelnienia "<< fill[j] << "% : " << results[i][j] << endl;
            }
            cout << endl;
        }

        results = {};

    }

    template <typename T>
    T generateGraph(T graph, int graphSize, int fillFactor, bool directed) {
        GraphGenerator generator;
        return generator.randomForTime(graph,graphSize,fillFactor, directed);
    }
};