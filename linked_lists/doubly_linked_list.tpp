#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#include <iostream>
#include "doubly_linked_list.h"

using namespace std;

namespace linked_list {

    template<class T>
    inline DoublyLinkedList<T>::DoublyLinkedList(T data) {
        head = new DoublyNode<T>(data);
        size = 0;
    }


    template<class T>
    inline int DoublyLinkedList<T>::getSize() {
        return size;
    }

    template<class T>
    inline bool DoublyLinkedList<T>::isEmpty() {
        return size == 0;
    }


    template<class T>
    void DoublyLinkedList<T>::insertFront(T data) {

    }


    template<class T>
    void DoublyLinkedList<T>::insertEnd(T data) {

    }


    template<class T>
    void DoublyLinkedList<T>::insertAt(T data, int pos) {

    }


    template<class T>
    T DoublyLinkedList<T>::deleteFront() {
        return nullptr;
    }


    template<class T>
    T DoublyLinkedList<T>::deleteEnd() {
        return nullptr;
    }


    template<class T>
    T DoublyLinkedList<T>::deleteAt(int pos) {
        return nullptr;
    }


    template<class T>
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