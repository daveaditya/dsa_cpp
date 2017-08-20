#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#ifndef DATA_STRUCTURES_DOUBLYLINKEDLIST_H
#define DATA_STRUCTURES_DOUBLYLINKEDLIST_H

#include "node.h"

template<class T>
class DoublyLinkedList : CommonMethods {
private:
    DoublyNode<T> *head = nullptr;
    int size = 0;

public:
    DoublyLinkedList() = default;

    explicit DoublyLinkedList(T data);

    inline bool isEmpty() override;

    inline int getSize() override;

    void print() override;

    void insertFront(T data);

    void insertEnd(T data);

    void insertAt(T data, int pos);

    T deleteFront();

    T deleteEnd();

    T deleteAt(int pos);
};

#include "doubly_linked_list.tpp"

#endif //DATA_STRUCTURES_DOUBLYLINKEDLIST_H

#pragma clang diagnostic pop