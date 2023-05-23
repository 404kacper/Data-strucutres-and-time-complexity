cmake_minimum_required(VERSION 3.21)
project(Lista2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")


add_executable(Lista_2 main.cpp
        utilities/Menu.h
        utilities/MatrixGraph.h
        utilities/generator/GraphGenerator.h
        utilities/ListGraph.h
        utilities/Edge.h
        utilities/Union.h
        utilities/PathNode.h
        algorithms/Prim.h
        algorithms/Kruskal.h
        algorithms/Dijkstra.h
        algorithms/BellmanFord.h
        utilities/MatrixGraph.cpp
        utilities/ListGraph.cpp
        utilities/generator/GraphGenerator.cpp
        utilities/Union.cpp
        algorithms/Prim.cpp
        algorithms/Kruskal.cpp
        algorithms/Dijkstra.cpp
        algorithms/BellmanFord.cpp
        utilities/stopwatch/Stopwatch.h)
