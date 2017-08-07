#include <iostream>
#include "node.cpp"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"


using namespace std;

template <class T>
class SinglyLinkedList {
private:
    SinglyNode<T> *head = nullptr;
    int size = 0;

public:
    SinglyLinkedList() = default;

    explicit SinglyLinkedList(T value) {
        head = new SinglyNode<T>(value);
    }

    int getSize() const {
        return size;
    }

    inline bool isEmpty() {
        return (size == 0);
    }

    void clear();

    void getRepr();

    // Linked List algorithms
    void insert_end(T value);

    void insert_front(T value);

    void insert_at(int pos, T value);

    T delete_front();

    T delete_end();

    T delete_at(int pos);
};


template <class T>
void SinglyLinkedList<T>::insert_end(T value) {
    auto *newNode = new SinglyNode<T>();
    newNode->setData(value);
    if(head == nullptr) {
        head = newNode;
    } else {
        SinglyNode<T> *temp = head;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    size++;
}


template <class T>
void SinglyLinkedList<T>::insert_front(T value) {
    auto *newNode = new SinglyNode<T>();
    newNode->setData(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->setNext(head);
    head = newNode;
    size++;
}


template <class T>
void SinglyLinkedList<T>::insert_at(int pos, T value) {
    if (pos >= getSize()) {
        cerr << "Illegal Index";
        return;
    }
    auto *newNode = new SinglyNode<T>();
    newNode->setData(value);
    SinglyNode<T> *temp = head, *prev = temp;
    for (int i = 0; i <= pos; ++i) {
        prev = temp;
        temp = temp->getNext();
    }
    newNode->setNext(temp);
    prev->setNext(newNode);
    size++;
}


template <class T>
T SinglyLinkedList<T>::delete_front() {
    if (head == nullptr) {
        cerr << "Empty List";
        return 0;
    }
    auto temp = head;
    head = head->getNext();
    auto data = temp->getData();
    delete temp;
    size--;
    return data;
}


template <class T>
T SinglyLinkedList<T>::delete_end() {
    if (head == nullptr) {
        cerr << "Empty List";
        return 0;
    }
    SinglyNode<T> *temp = head, *prev = temp;
    while (temp->getNext() != nullptr) {
        prev = temp;
        temp = temp->getNext();
    }
    prev->setNext(nullptr);
    auto data = temp->getData();
    delete temp;
    size--;
    return data;
}


template <class T>
T SinglyLinkedList<T>::delete_at(int pos) {
    if (head == nullptr) {
        cerr << "Empty List";
        return 0;
    }
    if (pos >= size) {
        cerr << "Illegal Index";
        return 0;
    }
    SinglyNode<T> *temp = head, *prev = temp;
    for (int i = 0; i < pos; ++i) {
        prev = temp;
        temp = temp->getNext();
    }
    prev->setNext(temp->getNext());
    auto data = temp->getData();
    delete temp;
    size--;
    return data;
}


template <class T>
void SinglyLinkedList<T>::clear() {
    auto temp = head;
    while (temp != nullptr) {
        auto del = temp;
        temp = temp->getNext();
        delete del;
    }
    delete head;
    size = 0;
}


template <class T>
void SinglyLinkedList<T>::getRepr() {
    if (size == 0) {
        cout << "Empty" << endl;
        return;
    }
    cout << "[ ";
    SinglyNode<T> *temp = head;
    while (temp != nullptr) {
        cout << temp->getData() << ", ";
        temp = temp->getNext();
    }
    cout << " ]" << endl;
}
#pragma clang diagnostic pop