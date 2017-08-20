#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma once

#include "node.h"

namespace linked_list {

    using namespace nodes;

    template<class T>
    class DoublyLinkedList : CommonMethods {
    private:
        DoublyNode<T> *head = nullptr;
        int size = 0;

    public:
        DoublyLinkedList() = default;

        explicit inline DoublyLinkedList(T data);

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

}

#include "doubly_linked_list.tpp"

#pragma clang diagnostic pop