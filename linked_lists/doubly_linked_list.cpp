#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#include <iostream>
#include "doubly_linked_list.h"

using namespace std;

namespace linkedlist {

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

}

#pragma clang diagnostic pop