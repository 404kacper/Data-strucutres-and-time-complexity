#include "CustomList.h"

void CustomList::insertFirst(int data) {
    temp = new Node;
    temp -> data = data;
    temp -> next = head;
    temp -> prev = nullptr;

    /// only for the 1st element
    if (head == nullptr) {
        tail = temp;
    } else {
        /// link first here
        /// only if head isn't null to avoid reading non existent data
        head -> prev = temp;
    }
    head = temp;
    /// increment total maxSize of the list
    size++;
}

void CustomList::insertLast(int data) {
    temp = new Node;
    temp -> data = data;
    temp -> next = nullptr;
    temp -> prev = tail;
    /// only for the 1st element
    if (head == nullptr) {
        head = temp;
    } else {
        /// link last here
        tail -> next = temp;
    }
    /// new tail
    tail = temp;
    /// increment total maxSize of the list
    size++;
}

void CustomList::insertAtIndex(int index, int data) {
    if (index == 0) {
        insertFirst(data);
    } else if (index >= size) {
        for (int i = size; i <= index; ++i) {
            insertLast(0);
        }
        tail -> data = data;
    } else {
            temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp -> next;
            }
            Node* newNext = temp;
            Node* oldPrev = temp -> prev;

            Node* insertedNode = new Node;

            insertedNode -> next = newNext;
            insertedNode -> prev = oldPrev;
            insertedNode -> data = data;

            oldPrev -> next = insertedNode;
            newNext -> prev = insertedNode;

            size++;
    }
}

void CustomList::findFirst(int item) {
    int i = 0;
    bool found = false;
    for (temp = head; temp != nullptr; temp=temp->next) {
        if (temp->data == item) {
            found = true;
            cout << "Element "<< item <<" znaleziony na indeksie " << i << endl;
            /// break to don't waste resources
            break;
        }
        i++;
    }
    if (!found) {
        cout << "Wyszukiwany element nie nalezy do tej listy" << endl;
    }
}

void CustomList::displayList() {
    temp = head;
    if (head == nullptr) {
        cout << "Lista jest pusta" << endl;
    } else {
        cout << temp -> data << " ";
        while (temp -> next != nullptr) {
            temp = temp -> next;
            cout << temp -> data << " ";
        }
        cout << endl;
    }
}

void CustomList::deleteFirst() {
    if (size != 0) {
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            temp = head -> next;
            temp -> prev = nullptr;
            delete head;
            head = temp;
        }
        size--;
    } else {
        cout << "Tablica jest pusta!" << endl;
    }
}

void CustomList::deleteLast() {
    if (tail != nullptr) {
        Node* toBeDeleted = tail;
        // set tail to the previous value and change it's next to NULL since the last element is being removed
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = toBeDeleted -> prev;
            tail -> next = nullptr;
        }
        delete toBeDeleted;
        size--;
    } else {
        cout << "Ogon ma wartosc NULL !" << endl;
    }
}

void CustomList::deleteAtIndex(int index) {
    if (index >= size) {
//        cout << "Indeks poza zasiegiem listy" << endl;
    } else {
        if (index == 0) {
            deleteFirst();
        } else if (size == index+1){
            deleteLast();
        } else {
            temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            Node* next = temp -> next;
            Node* prev = temp -> prev;

            next->prev=prev;
            prev->next=next;
            delete temp;
            size--;
        }
    }
}

