#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedImportStatement"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#include <iostream>
#include "doubly_linked_list.h"
#include "../exceptions.h"

using namespace std;

namespace linked_list {

	template<class T>
	DoublyLinkedList<T>::DoublyLinkedList(T data) {
		head = new DoublyNode<T>(data);
		size = 1;
	}

	template<class T>
	DoublyLinkedList<T>::~DoublyLinkedList() {
		if (head != nullptr) {
			destroy(head);
			size = 0;
		}
	}

	template<class T>
	void DoublyLinkedList<T>::destroy(DoublyNode<T> *node) {
		if (node != nullptr) {
			destroy(node->getNext());
			delete node;
		}
	}

	template<class T>
	bool DoublyLinkedList<T>::isEmpty() {
		return size == 0;
	}

	template<class T>
	int DoublyLinkedList<T>::getSize() {
		return size;
	}

	template<class T>
	void DoublyLinkedList<T>::clear() {
		destroy(head);
		head = nullptr;
		size = 0;
	}

	template<class T>
	void DoublyLinkedList<T>::insertFront(T data) {
		DoublyNode<T> *new_node = new DoublyNode<T>(data);
		if (head == nullptr) {
			head = new_node;
			size++;
			return;
		}
		new_node->setNext(head);
		head->setPrevious(new_node);
		head = new_node;
		size++;
	}

	template<class T>
	void DoublyLinkedList<T>::insertEnd(T data) {
		DoublyNode<T> *new_node = new DoublyNode<T>(data);
		if (head == nullptr) {
			head = new_node;
			size++;
			return;
		}
		auto *temp = head;
		while (temp->getNext() != nullptr) {
			temp = temp->getNext();
		}
		temp->setNext(new_node);
		new_node->setPrevious(temp);
		size++;
	}

	template<class T>
	void DoublyLinkedList<T>::insertAt(T data, int pos) {
		if (pos > size) {
			cerr << "Illegal Position...\n";
			return;
		}
		DoublyNode<T> *new_node = new DoublyNode<T>(data);
		auto *temp = head;
		for (int i = 0; i < pos - 1; ++i) {
			temp = temp->getNext();
		}
		temp->getNext()->setPrevious(new_node);
		new_node->setNext(temp->getNext());
		new_node->setPrevious(new_node);
		temp->setNext(new_node);
		size++;
	}

	template<class T>
	T DoublyLinkedList<T>::deleteFront() {
		if (head == nullptr) {
			throw Underflow("Doubly Linked list is empty");
		}
		auto *temp = head;
		head = head->getNext();
		head->setPrevious(nullptr);
		auto data = temp->getData();
		delete temp;
		size--;
		return data;
	}

	template<class T>
	T DoublyLinkedList<T>::deleteEnd() {
		if (head == nullptr) {
			throw Underflow("Doubly Linked list is empty");
		}
		auto *temp = head, *prev = temp;
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

	template<class T>
	T DoublyLinkedList<T>::deleteAt(int pos) {
		if (pos > size) {
			throw IllegalPosition(pos);
		}
		if (head == nullptr) {
			throw Underflow("Doubly Linked list is empty");
		}
		auto *temp = head;
		for (int i = 0; i < pos; ++i) {
			temp = temp->getNext();
		}
		auto *to_delete = temp->getNext();
		temp->setNext(to_delete->getNext());
		to_delete->getNext()->setPrevious(temp);
		auto data = to_delete->getData();
		delete to_delete;
		size--;
		return data;
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