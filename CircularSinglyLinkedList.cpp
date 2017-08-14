#include <iostream>

#ifndef NODE_INCLUDED
#include "node.cpp"
#endif

#pragma clang diagnostic push

#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

using namespace std;


template <class T>
class CircularSinglyLinkedList: public CommonMethods {
private:
    CircularNode<T> *head = nullptr;
    int size = 0;

    void destroy(CircularNode<T> *node);
public:
    CircularSinglyLinkedList() = default;

    ~CircularSinglyLinkedList() {
        if (head != nullptr) {
            destroy(head);
        }
    }

    inline bool isEmpty() override {
        return size == 0;
    }

    inline int getSize() override {
        return size;
    }

    inline void clear() {
        destroy(head);
        head = nullptr;
        size = 0;
    }

    void print() override;

    void insertFront(T data);
    void insertEnd(T data);
    void insertAt(T data, int pos);

    T deleteFront();
    T deleteEnd();
    T deleteAt(int pos);
};


template <class T>
void CircularSinglyLinkedList<T>::destroy(CircularNode<T> *node) {
    if (node->getNext() != head) {
        return destroy(node->getNext());
    }
    delete node;
}

template <class T>
void CircularSinglyLinkedList<T>::insertFront(T data) {
    auto *new_node = new CircularNode<T>(data);
    if (head == nullptr) {
        head = new_node;
        head->setNext(head);
        size++;
        return;
    }
    new_node->setNext(head);
    CircularNode<T> *temp = head;
    while (temp->getNext() != head) {
        temp = temp->getNext();
    }
    temp->setNext(new_node);
    head = new_node;
    size++;
}

template <class T>
void CircularSinglyLinkedList<T>::insertEnd(T data) {
    auto *new_node = new CircularNode<T>(data);
    if (head == nullptr) {
        head = new_node;
        head->setNext(head);
        size++;
        return;
    }
    CircularNode<T> *temp = head;
    while (temp->getNext() != head) {
        temp = temp->getNext();
    }
    new_node->setNext(head);
    temp->setNext(new_node);
    size++;
}


template <class T>
void CircularSinglyLinkedList<T>::insertAt(T data, int pos) {
    auto *new_node = new CircularNode<T>(data);
    if (pos >= size) {
        cerr << "Illegal Index..." << pos;
        return;
    }
    CircularNode<T> *temp = head;
    for(int i = 0; i < pos - 1; i++) {
        temp = temp->getNext();
    }
    new_node->setNext(temp->getNext());
    temp->setNext(new_node);
    size++;
}

template <class T>
T CircularSinglyLinkedList<T>::deleteFront() {
    if (head == nullptr) {
        cerr << "Underflow..." << endl;
        return 0;
    }
    auto *to_delete = head, *temp = head;
    auto data = to_delete->getData();
    while (temp->getNext() != head) {
        temp = temp->getNext();
    }
    temp->setNext(to_delete->getNext());
    head = to_delete->getNext();
    size--;
    delete to_delete;
    return data;
}

template <class T>
T CircularSinglyLinkedList<T>::deleteEnd() {
    if (head == nullptr) {
        cerr << "Underflow..." << endl;
        return 0;
    }
    CircularNode<T> *temp = head, *prev = temp;
    while (temp->getNext() != head) {
        prev = temp;
        temp = temp->getNext();
    }
    auto data = temp->getData();
    delete temp;
    prev->setNext(head);
    size--;
    return data;
}

template <class T>
T CircularSinglyLinkedList<T>::deleteAt(int pos) {
    if(pos >= size) {
        cerr << "Illegal Index..." << endl;
        return 0;
    }
    if (head == nullptr) {
        cerr << "Underflow..." << endl;
        return 0;
    }
    auto *temp = head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->getNext();
    }
    auto to_delete = temp->getNext();
    temp->setNext(to_delete->getNext());
    auto data = to_delete->getData();
    size--;
    delete to_delete;
    return data;
}

template <class T>
void CircularSinglyLinkedList<T>::print() {
    if (size == 0) {
        cout << "Empty" << endl;
        return;
    }
    auto temp = head;
    cout << "[ ";
    while (true) {
        cout << temp->getData() << ", ";
        temp = temp->getNext();
        if (temp == head) {
            break;
        }
    }
    cout << " ]" << endl;
}

#pragma clang diagnostic pop
#pragma clang diagnostic pop
#pragma clang diagnostic pop