#include "CustomArray.h"


CustomArray::CustomArray() {
    size = 0;
    start = nullptr;
}

CustomArray::~CustomArray() {
    free(start);
}

void CustomArray::addFirstElement(int value) {
    if (size == 0) {
        size++;
        start = (int*)malloc(sizeof(int)*size);
        *start = value;
    } else {
        size++;
        // very important !!! realloc copies data only to the old size not the new one
        start = (int*)realloc(start, sizeof(int)*(size));
        // copy old values from the start
        for (int i = size; i > 0; --i) {
            *(start+i) = *(start+i-1);
        }
        *start = value;
    }
}

void CustomArray::addLastElement(int value) {
    if (size == 0) {
        size++;
        start = (int*)malloc(sizeof(int)*size);
        *start = value;
    } else {
        size++;
        start = (int*)realloc(start, sizeof(int)*(size));
        *(start+size-1) = value;
    }
}

void CustomArray::addElementAtIndex(int index, int value) {
    if (size == 0) {
        size++;
        start = (int*)malloc(sizeof(int)*(index+1));
        *(start+index) = value;
    } else {
        if (index >= size) {
            size = index+1;
            start = (int*) realloc(start,sizeof(int)*(index+1));
            *(start+index) = value;
        } else {
            size++;
            start = (int*) realloc(start, sizeof(int)*(size));
            for (int i = size; i > index; --i) {
                *(start+i) = *(start+i-1);
            }
            *(start+index) = value;
        }
    }
}

void CustomArray::removeFirstElement() {
    removeElementAtIndex(0);
}

void CustomArray::removeLastElement() {
    removeElementAtIndex(size);
}

void CustomArray::removeElementAtIndex(int index) {
    if (index > size) {
        cout << "Indeks jest poza zasiegiem tablicy." << endl;
    } else if (size == 1) {
        *(start+index) = 0;
        size--;
    } else if (size == 0 ) {
      cout << "Tablica jest pusta" << endl;
    } else {
        for (int i = index; i < size; ++i) {
            *(start + i) = *(start + i + 1);
        }
        start = (int*) realloc(start, (sizeof(int)*(size-1)));
        size--;
    }
}

void CustomArray::findFirstVal(int value) {
    bool breakCondition;
    int foundValue;
    int index;
    for (int i = 0; i < size; ++i) {
        index = i;
        foundValue = *(start + i);
        breakCondition = (foundValue == value);
        if (breakCondition)
            break;
    }

    if (breakCondition) {
        cout << "Znaleziono wartosc " << foundValue <<  " na indeksie " << index << endl;
    } else {
        cout << "Nie znaleziono wartosci " << value << " w zadeklarowanej tablicy" << endl;
    }
}

void CustomArray::print() {
    for (int i = 0; i < size; ++i) {
        cout << *(start + i) << " ";
    }
    cout << endl;
}

int *CustomArray::getStart() const {
    return start;
}
