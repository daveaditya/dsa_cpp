#include <iostream>
#include "linked_lists/node.h"
#include "linked_lists/singly_linked_list.h"
#include "linked_lists/circular_singly_linked_list.h"

using namespace std;

int main() {

    auto *list = new linkedlist::SinglyLinkedList<int>();
    for (int i = 0; i < 9; ++i) {
        list->insertEnd(i);
    }
    list->insertFront(11);
    list->insertEnd(22);
    list->insertAt(2, 33);
    list->print();
    list->deleteFront();
    list->print();
    list->deleteEnd();
    list->print();
    list->deleteAt(4);
    list->print();
    list->clear();
    list->print();

    linkedlist::SinglyLinkedList<int> list2;
    list2.insertEnd(10);
    list2.insertFront(11);
    list2.print();

    delete list;

    cout << "\n\n" << "***CIRCULAR LINKED LIST***" << endl;
    auto *c_list = new linkedlist::CircularSinglyLinkedList<int>();
    for (int i = 0; i < 10; i++) {
        c_list->insertEnd(i);
    }
    c_list->insertFront(11);
    c_list->insertFront(22);
    c_list->print();

    c_list->insertAt(44, 4);
    c_list->print();

    c_list->deleteFront();
    c_list->deleteFront();
    c_list->print();
    c_list->deleteEnd();
    c_list->deleteEnd();
    c_list->print();
    c_list->deleteAt(2);
    c_list->print();

    c_list->clear();
    c_list->print();

    delete c_list;

    return 0;
}