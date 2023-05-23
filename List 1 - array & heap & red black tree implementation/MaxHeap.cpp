#include "MaxHeap.h"

void swapArrayElements(int* x, int* y);

MaxHeap::MaxHeap() {
    size = 0;
    arrayObject = CustomArray();
    elements = arrayObject.getStart();
}

void MaxHeap::insertElement(int element) {
    /// Inserts element at the end of the heap
    size++;
    int index = size - 1;
    arrayObject.addLastElement(element);
    elements = arrayObject.getStart();

    /// Swap elements accordingly to the heap rules
    while (index != 0 && elements[parent(index)] < elements[index]) {
        swapArrayElements(&elements[index], &elements[parent(index)]);
        index = parent(index);
    }
}

void MaxHeap::deleteElement(int index) {
    if (index > size-1) {
        cout << "Index jest poza zasiegiem kopca!" << endl;
    } else {
        increaseElement(index, INT_MAX);
        removeMax();
    }
}

void MaxHeap::increaseElement(int index, int valueForIncrease) {
    /// valueForIncrease is assumed to be bigger than elements[i]
    elements[index] = valueForIncrease;
    while (index != 0 && elements[parent(index)] < elements[index]) {
        swapArrayElements(&elements[index], &elements[parent(index)]);
        index = parent(index);
    }
}

int MaxHeap::removeMax() {
    if (size <= 0 ) {
        return INT_MAX;
    }
    if (size == 1) {
        size--;
        arrayObject.removeLastElement();
        elements = arrayObject.getStart();
        return elements[0];
    }

    int root = elements[0];
    elements[0] = elements[size-1];
    arrayObject.removeLastElement();
    elements = arrayObject.getStart();
    size--;
    repairHeap(0);

    return root;
}

///  This is the recursive method that's responsible for entire heap structure
void MaxHeap::repairHeap(int index) {
    int l = left(index);
    int r = right(index);
    int largest = index;

    if (l < size && elements[l] > elements[index]) {
        largest = l;
    }
    if (r < size && elements[r] > elements[largest]) {
        largest = r;
    }
    if (largest != index) {
        swapArrayElements(&elements[index], &elements[largest]);
        repairHeap(largest);
    }
}

void MaxHeap::printHeap() {
    cout << "Elementy stosu" << endl;
    for (int i = 0; i < size; ++i) {
        cout << setw(4) << elements[i];
    }
    cout << endl;
    cout << "Indeksy elementow w tablicy" << endl;
    for (int i = 0; i < size; ++i) {
        cout << setw(4) << i ;
    }
    cout << endl;

    if (size != 0) {
        int numOfElements = 1;
        int index = 0;
        int currentDepth = 0;
        while (index != size) {
            currentDepth++;
            for (int i = 1; i <= numOfElements; ++i) {
                int numOfDigits = calculateNumberOfDigits(elements[index]);
                int width = numOfDigits+1;
                if (i == 1) {
                    cout << "Glebokosc: " << currentDepth << endl << elements[index];
                } else {
                    cout << setw(width) << elements[index];
                }
                index++;
                if (index == size) break;
            }
            cout << endl;
            numOfElements *= 2;
        }
    } else {
        cout << "Kopiec jest pusty!" << endl;
    }
}

int MaxHeap::calculateNumberOfDigits(int number) {
    int digitsCounter = 0;

    while (number != 0) {
        digitsCounter++;
        number /= 10;
    }

    return digitsCounter;
}

int MaxHeap::calculateMaxIndexAtLevel(int index) {
    int start = 2;
    int difference = 4;

    if (index == 0) {
        return 0;
    } else {
        while (index > start) {
            start += difference;
            difference*=2;
        }
        return start;
    }
}

/// INDEX IS THE MAXIMUM INDEX AT GIVEN LEVEL
int MaxHeap::calculateMaxElementsAtLevel(int maxIndex) {
    return maxIndex- parent(maxIndex);
}

void MaxHeap::findItem(int value) {
    int foundValue;
    int found = 0;
    for (int i = 0; i < size; ++i) {
        foundValue = elements[i];
        if (value == foundValue) {
            found = 1;
            cout << "Znaleziono wartosc: " << elements[i] << " na indeksie: " <<  i << endl;
            break;
        }
    }

    if (!found) {
        cout << "Nie znaleziono szukanej wartosci." << endl;
    }
}

void swapArrayElements(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
