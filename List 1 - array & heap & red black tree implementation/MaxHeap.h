#include "iostream"
#include "iomanip"
#include "CustomArray.h"


using namespace std;


class MaxHeap {
    CustomArray arrayObject;
    int* elements;
    int size;
public:

public:
    MaxHeap();

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }

    void insertElement(int element);
    void deleteElement(int index);
    void increaseElement(int index, int valueForIncrease);
    int  removeMax();
    void repairHeap(int index);
    void findItem(int value);

    void printHeap();
    int calculateNumberOfDigits(int number);
    int calculateMaxIndexAtLevel(int index);
    int calculateMaxElementsAtLevel(int maxIndex);
};
