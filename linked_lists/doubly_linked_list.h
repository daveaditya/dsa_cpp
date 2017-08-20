#ifndef DATA_STRUCTURES_DOUBLYLINKEDLIST_H
#define DATA_STRUCTURES_DOUBLYLINKEDLIST_H

#include "node.h"

namespace linkedlist {

    template<class T>
    class DoublyLinkedList : CommonMethods {
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
}

#endif //DATA_STRUCTURES_DOUBLYLINKEDLIST_H
