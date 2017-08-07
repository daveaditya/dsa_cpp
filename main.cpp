#include "SinglyLinkedList.cpp"

int main() {

    auto *list = new SinglyLinkedList<int>();
    for (int i = 0; i < 9; ++i) {
        list->insert_end(i);
    }
    list->insert_front(11);
    list->insert_end(22);
    list->insert_at(2, 33);
    list->getRepr();
    list->delete_front();
    list->getRepr();
    list->delete_end();
    list->getRepr();
    list->delete_at(4);
    list->getRepr();
    list->clear();
    list->getRepr();

    SinglyLinkedList<int> list2;
    list2.insert_end(10);
    list2.insert_front(11);
    list2.getRepr();

    return 0;
}