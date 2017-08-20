#ifndef DATA_STRUCTURES_SINGLYLINKEDLIST_H_H
#define DATA_STRUCTURES_SINGLYLINKEDLIST_H_H

#include "node.h"

namespace linkedlist {

    template<class T>
    class SinglyLinkedList : public CommonMethods {
    private:
        SinglyNode<T> *head = nullptr;
        int size = 0;

        void destroy(SinglyNode<T> *node);

    public:

        SinglyLinkedList() = default;

        explicit SinglyLinkedList(T value) {
            head = new SinglyNode<T>(value);
        }

        ~SinglyLinkedList() {
            if (head != nullptr) {
                destroy(head);
            }
        }

        inline int getSize() override {
            return size;
        }

        inline bool isEmpty() override {
            return (size == 0);
        }

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

#endif //DATA_STRUCTURES_SINGLYLINKEDLIST_H_H
