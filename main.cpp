#include "SinglyLinkedList.cpp"
#include "CircularSinglyLinkedList.cpp"

int main() {

    auto *list = new SinglyLinkedList<int>();
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

    SinglyLinkedList<int> list2;
    list2.insertEnd(10);
    list2.insertFront(11);
    list2.print();

    delete list;

    cout << "\n\n" << "***CIRCULAR LINKED LIST***" << endl;
    auto *c_list = new CircularSinglyLinkedList<int>();
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