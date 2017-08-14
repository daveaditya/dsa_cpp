#include <iostream>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#ifndef NODE_INCLUDED
#include "node.cpp"
#endif

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"

using namespace std;

template <class T>
class DoublyLinkedList: CommonMethods {
private:
    DoublyNode<T> *head = nullptr;
    int size = 0;

public:
    DoublyLinkedList<T>() = default;

    explicit DoublyLinkedList<T>(T data) {
        head = new DoublyNode<T>(data);
        size = 0;
    }

    inline bool isEmpty() override {
        return size == 0;
    }

    inline int getSize() override {
        return size;
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
void DoublyLinkedList<T>::insertFront(T data) {

}

template <class T>
void DoublyLinkedList<T>::insertEnd(T data) {

}

template <class T>
void DoublyLinkedList<T>::insertAt(T data, int pos) {

}

template <class T>
T DoublyLinkedList<T>::deleteFront() {
    return nullptr;
}

template <class T>
T DoublyLinkedList<T>::deleteEnd() {
    return nullptr;
}

template <class T>
T DoublyLinkedList<T>::deleteAt(int pos) {
    return nullptr;
}

template <class T>
void DoublyLinkedList<T>::print() {
    if (size == 0) {
        cout << "Empty" << endl;
        return;
    }
    auto *temp = head;
    cout << "[ ";
    while (temp->getNext() != nullptr) {
        cout << temp->getData() << ", ";
        temp = temp->getNext();
    }
    cout << " ]" << endl;
}

#pragma clang diagnostic pop
#pragma clang diagnostic pop