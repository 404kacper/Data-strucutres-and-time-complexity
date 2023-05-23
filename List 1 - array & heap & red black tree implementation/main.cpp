#include "main.h"

int main() {
    openInterface();
    string wait;
    cout << "Wprowadz dowolny znak aby wyjsc z programu" << endl;
    cin >> wait;
    return 0;
}

void openInterface() {
    int choiceO;
    int choice1;
    cout << "Wybierz operacje: 1 - generuj wyniki, 2 - testuj struktury" << endl;
    cin >> choiceO;

    if (choiceO == 1) {
        choice1 = chooseStructure();
        proceedAuto(choice1);
    } else if(choiceO == 2) {
        choice1 = chooseStructure();
        proceedManual(choice1);
    }

}

int chooseStructure() {
    int choice;
    cout << "Wybierz strukture: 1 - tablica, 2 - lista, 3 - kopiec, 4 - drzewo R&B" << endl;
    cin >> choice;
    return choice;
}

int doArray(CustomArray& array) {
    int operation;
    int operation2;
    cout << "Podaj operacje: \n 1 - dodaj pierwszy element \n 2 - dodaj ostatni \n 3 - dodaj okreslony \n 4 - usun pierwszy \n 5 - usun ostatni \n 6 - usun okreslony \n 7 - wyswietl tablice \n 8 - znajdz element \n 9 - wczytaj z pliku \n10 - wyjdz" << endl;
    cin >> operation;
    switch (operation) {
        case 1: {
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            array.addFirstElement(operation2);
            break;
        }
        case 2: {
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            array.addLastElement(operation2);
            break;
        }
        case 3: {
            int operation3;
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            cout << "Podaj indeks: " << endl;
            cin >> operation3;
            array.addElementAtIndex(operation3, operation2);
            break;
        }
        case 4: {
            array.removeFirstElement();
            break;
        }
        case 5: {
            array.removeLastElement();
            break;
        }
        case 6: {
            cout << "Podaj indeks: " << endl;
            cin >> operation2;
            array.removeElementAtIndex(operation2);
            break;
        }
        case 7: {
            array.print();
            break;
        }
        case 8: {
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            array.findFirstVal(operation2);
            break;
        }
        case 9: {
            readInputData();
            extractInputData(fileContents[0], numbers);
            for (int i = 0; i < numbers.size(); ++i) {
                array.addLastElement(numbers[i]);
            }
        }

    }
    return operation;
}

int doList(CustomList& list) {
    int operation;
    int operation2;
    cout << "Podaj operacje: \n 1 - dodaj pierwszy element \n 2 - dodaj ostatni \n 3 - dodaj okreslony \n 4 - usun pierwszy \n 5 - usun ostatni \n 6 - usun okreslony \n 7 - wyswietl liste \n 8 - znajdz element \n 9 - wczytaj z pliku \n 10 - wyjdz" << endl;
    cin >> operation;
    switch (operation) {
        case 1: {
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            list.insertFirst(operation2);
            break;
        }
        case 2: {
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            list.insertLast(operation2);
            break;
        }
        case 3: {
            int operation3;
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            cout << "Podaj indeks: " << endl;
            cin >> operation3;
            list.insertAtIndex(operation3, operation2);
            break;
        }
        case 4: {
            list.deleteFirst();
            break;
        }
        case 5: {
            list.deleteLast();
            break;
        }
        case 6: {
            cout << "Podaj indeks: " << endl;
            cin >> operation2;
            list.deleteAtIndex(operation2);
            break;
        }
        case 7: {
            list.displayList();
            break;
        }
        case 8: {
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            list.findFirst(operation2);
            break;
        }
        case 9: {
            readInputData();
            extractInputData(fileContents[1], numbers);
            for (int i = 0; i < numbers.size(); ++i) {
                list.insertLast(numbers[i]);
            }
        }
    }
    return operation;
}

int doHeap(MaxHeap& heap) {
    int operation;
    int operation2;
    cout << "Podaj operacje: \n 1 - dodaj element \n 2 - usun element \n 3 - usun korzen \n 4 - wyswietl stos \n 5 - znajdz element \n 6 - wczytaj z pliku \n 7 - wyjdz" << endl;
    cin >> operation;
    switch (operation) {
        case 1: {
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            heap.insertElement(operation2);
            break;
        }
        case 2: {
            cout << "Podaj indeks: " << endl;
            cin >> operation2;
            heap.deleteElement(operation2);
            break;
        }
        case 3: {
            heap.removeMax();
            break;
        }
        case 4: {
            heap.printHeap();
            break;
        }
        case 5: {
            cout << "Podaj wyszukiwana wartosc: " << endl;
            cin >> operation2;
            heap.findItem(operation2);
            break;
        }
        case 6: {
            readInputData();
            extractInputData(fileContents[2], numbers);
            for (int i = 0; i < numbers.size(); ++i) {
                heap.insertElement(numbers[i]);
            }
        }
    }
    return operation;
}

int doTree(RedBlackTree& tree) {
    int operation;
    int operation2;
    cout << "Podaj operacje: \n 1 - dodaj element \n 2 - wyswietl drzewo - preorder \n 3 - znajdz wezel \n 4 - wczytaj z pliku \n 5 - wyjdz" << endl;
    cin >> operation;
    switch (operation) {
        case 1: {
            cout << "Podaj wartosc: " << endl;
            cin >> operation2;
            tree.insertNode(operation2);
            break;
        }
        case 2: {
            tree.printTree();
            break;
        }
        case 3: {
            cout << "Podaj wyszukiwana wartosc: " << endl;
            cin >> operation2;
            tree.printFound(operation2);
        }
        case 4: {
            readInputData();
            extractInputData(fileContents[3], numbers);
            for (int i = 0; i < numbers.size(); ++i) {
                tree.insertNode(numbers[i]);
            }
        }
    }
    return operation;
}

/// krótki opis pliku (inputData) - wczytuje stringa co jedną linie : każda linia odpowiada kolejnym strukturom
/// linia 0 - tablica | 1 - lista | 2 - kopiec | 3 - drzewo
void proceedManual(int structChoice) {
    int arraySize;
    int heapSize;
    switch (structChoice) {
        case 1: {
            CustomArray userArray;
            while (doArray(userArray) != 10);
            break;
        }
        case 2: {
            CustomList userList;
            while (doList(userList) != 10);
            break;
        }
        case 3: {
            MaxHeap userHeap;
            while (doHeap(userHeap) != 7);
            break;
        }
        case 4: {
            RedBlackTree tree;
            while (doTree(tree) != 5);
            break;
        }
    }
}

/// krótki opis pliku (inputTime) - co dwie linie : pierwsza linia pliku to rozmiar struktury a druga to ilość generowaynch elementów
/// line 0 - tablica | linia 1 - lista | linie 2 kopiec | linia 3 drzewo czerwono czarne
void proceedAuto(int structChoice) {
    readInputTime();
    default_random_engine defEngine(time(0));

    int sampleCount = 200;
    double total_time_nano = 0;
    double average_time_nano;

    for (int i = 0; i < sampleCount; ++i) {
        switch (structChoice) {
            // wybrana przez uzytkownika struktura 1 - tablica
            case 1: {
                // wczytywanie ilosci danych z pliku zewnetrznego
                int numOfArrayElements = stoi(fileContents[0]);

                // tworzenie pojedynczego obiektu
                CustomArray array;
                // tworzenie zbioru danych do wstawiania w tabeli - rozklad normalny
                uniform_int_distribution<int> intDistro(INT_MIN,INT_MAX);

                for (int j = 0; j < numOfArrayElements; ++j) {
                    int randomDistro = intDistro(defEngine);
                    array.addLastElement(randomDistro);
                }

                int randomDistro = intDistro(defEngine);
                auto start = high_resolution_clock::now();
                array.findFirstVal(randomDistro);
                auto stop = high_resolution_clock::now();
                auto time = duration_cast<nanoseconds>(stop - start);
                total_time_nano += time.count();
                break;
            }
            case 2: {
                int numOfListElements = stoi(fileContents[1]);

                CustomList list;
                uniform_int_distribution<int> intDistro(INT_MIN,INT_MAX);

                for (int j = 0; j < numOfListElements; ++j) {
                    int randomDistro = intDistro(defEngine);
                    list.insertFirst(randomDistro);
                }

                int randomDistro = intDistro(defEngine);
                auto start = high_resolution_clock::now();
                list.findFirst(randomDistro);
                auto stop = high_resolution_clock::now();
                auto time = duration_cast<nanoseconds>(stop - start);
                total_time_nano += time.count();
                break;
            }
            case 3: {
                int numOfHeapElements = stoi(fileContents[2]);

                MaxHeap heap;
                uniform_int_distribution<int> intDistro(INT_MIN,INT_MAX);

                for (int j = 0; j < numOfHeapElements; ++j) {
                    int randomDistro = intDistro(defEngine);
                    heap.insertElement(randomDistro);
                }

                int randomDistro = intDistro(defEngine);
                auto start = high_resolution_clock::now();
                heap.deleteElement(numOfHeapElements/2);
                auto stop = high_resolution_clock::now();
                auto time = duration_cast<nanoseconds>(stop - start);
                total_time_nano += time.count();
                break;
            }
            case 4: {
                int numOfTreeElements = stoi(fileContents[3]);

                RedBlackTree tree;
                uniform_int_distribution<int> intDistro(INT_MIN,INT_MAX);

                for (int j = 0; j < numOfTreeElements; ++j) {
                    int randomDistro = intDistro(defEngine);
                    tree.insertNode(randomDistro);
                }

                int randomDistro = intDistro(defEngine);
                auto start = high_resolution_clock::now();
                tree.findItem(tree.root, randomDistro);
                auto stop = high_resolution_clock::now();
                auto time = duration_cast<nanoseconds>(stop - start);
                total_time_nano += time.count();
                break;
            }
        }
    }

    average_time_nano = total_time_nano / sampleCount;
    cout << "Sredni czas operacji (w nano): " << average_time_nano << endl;

}

void readInputTime() {
    ifstream ofile("inputTime.txt");
    if (ofile) {
        string inputString;
        while(ofile >> inputString) {
            fileContents.push_back(inputString);
        }
    } else {
        cout << "Plik nie istnieje" << endl;
    }
}

void readInputData() {
    ifstream ofile("inputData.txt");
    if (ofile) {
        string inputString;
        while(ofile >> inputString) {
            fileContents.push_back(inputString);
        }
    } else {
        cout << "Plik nie istnieje" << endl;
    }
}

void extractInputData(string &contentString, vector<int> &delimiterArray) {
    string delimiter = ";";
    int pos;
    string token;
    while ((pos = contentString.find(delimiter)) != string::npos) {
        token = contentString.substr(0, pos);
        delimiterArray.push_back(stoi(token));
        contentString.erase(0, pos+delimiter.length());
    }
}