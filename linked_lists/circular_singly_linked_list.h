#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#ifndef DATA_STRUCTURES_CIRCULARSINGLYLINKEDLIST_H
#define DATA_STRUCTURES_CIRCULARSINGLYLINKEDLIST_H

#include "node.h"

namespace linked_list {

    using namespace nodes;

    template<class T>
    class CircularSinglyLinkedList : public CommonMethods {
    private:
        CircularNode<T> *head = nullptr;
        int size = 0;

        void destroy(CircularNode<T> *node);

    public:
        CircularSinglyLinkedList() = default;

        explicit inline CircularSinglyLinkedList(T data);

        ~CircularSinglyLinkedList();

        inline bool isEmpty() override;

        inline int getSize() override;

        void clear();

        void print() override;

        void insertFront(T data);

        void insertEnd(T data);

        void insertAt(T data, int pos);

        T deleteFront();

        T deleteEnd();

        T deleteAt(int pos);
    };

}

#include "circular_singly_linked_list.tpp"

#endif //DATA_STRUCTURES_CIRCULARSINGLYLINKEDLIST_H

#pragma clang diagnostic pop