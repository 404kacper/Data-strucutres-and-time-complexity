#include <cstdlib>
#include <iostream>

#pragma once

using namespace std;


class CustomArray {

private:
    int* start;
public:
    int *getStart() const;

private:
    int size;

public:
    CustomArray();
    ~CustomArray();

    void addLastElement(int value);

    void removeLastElement();

    void removeFirstElement();

    void addFirstElement(int value);

    void removeElementAtIndex(int index);

    void addElementAtIndex(int index, int value);

    void findFirstVal(int value);

    void print();
};
