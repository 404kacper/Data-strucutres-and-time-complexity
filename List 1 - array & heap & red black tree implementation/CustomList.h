#include <iostream>

using namespace std;

class CustomList {
private:
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
    };

public:
    CustomList() {
        head = nullptr;
        temp = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~CustomList() {
        /// dealokacja struktur
        temp = head;
        Node* toDelete;
        for (int i = 0; i < size; ++i) {
            toDelete = temp;
            temp = temp -> next;
            delete toDelete;
        }
        delete temp;
    }

    Node* head;
    Node* temp;
    Node* tail;
    int size;

    void insertFirst(int data);

    void insertLast(int data);

    void insertAtIndex(int index, int data);

    void deleteFirst();

    void deleteLast();

    void deleteAtIndex(int index);

    void findFirst(int item);

    void displayList();


};
