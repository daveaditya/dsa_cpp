#ifndef DATA_STRUCTURES_CIRCULARSINGLYLINKEDLIST_H
#define DATA_STRUCTURES_CIRCULARSINGLYLINKEDLIST_H

#include "node.h"

namespace linkedlist {

    template<class T>
    class CircularSinglyLinkedList : public CommonMethods {
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

}

#endif //DATA_STRUCTURES_CIRCULARSINGLYLINKEDLIST_H
