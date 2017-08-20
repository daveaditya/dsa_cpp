#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"

#ifndef DATA_STRUCTURES_SINGLYLINKEDLIST_H_H
#define DATA_STRUCTURES_SINGLYLINKEDLIST_H_H

#include "node.h"

namespace linked_list {

    using namespace nodes;

    template<class T>
    class SinglyLinkedList : public CommonMethods {
    private:
        SinglyNode<T> *head = nullptr;
        int size = 0;

        void destroy(SinglyNode<T> *node);

    public:

        SinglyLinkedList() = default;

        explicit inline SinglyLinkedList(T value);

        ~SinglyLinkedList();

        inline int getSize() override;

        inline bool isEmpty() override;

        void clear();

        void print() override;

        // Linked List algorithms
        void insertEnd(T value);

        void insertFront(T value);

        void insertAt(int pos, T value);

        T deleteFront();

        T deleteEnd();

        T deleteAt(int pos);
    };

}

#include "singly_linked_list.tpp"

#endif //DATA_STRUCTURES_SINGLYLINKEDLIST_H_H

#pragma clang diagnostic pop