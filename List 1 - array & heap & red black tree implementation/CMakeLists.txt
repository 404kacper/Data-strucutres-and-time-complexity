cmake_minimum_required(VERSION 3.21)
project(Lista1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SOURCE_FILES main.cpp main.h ../Lista2/dynamicStructs/CustomList.cpp ../Lista2/dynamicStructs/CustomList.h MaxHeap.cpp MaxHeap.h CustomArray.cpp CustomArray.h ../Lista2/dynamicStructs/CustomList.cpp ../Lista2/dynamicStructs/CustomList.h RedBlackTree.cpp RedBlackTree.h)
add_executable(Lista1 ${SOURCE_FILES})
