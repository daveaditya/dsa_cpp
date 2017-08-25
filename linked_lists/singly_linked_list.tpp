#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedImportStatement"
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#include <iostream>
#include "singly_linked_list.h"
#include "../exceptions.h"

using namespace std;

namespace linked_list {

	template<class T>
	inline SinglyLinkedList<T>::SinglyLinkedList(T value) {
		head = new SinglyNode<T>(value);
		size = 1;
	}

	template<class T>
	SinglyLinkedList<T>::~SinglyLinkedList() {
		if (head != nullptr) {
			destroy(head);
		}
	}

	template<class T>
	void SinglyLinkedList<T>::destroy(SinglyNode<T> *node) {
		if (node->getNext() != nullptr) {
			destroy(node->getNext());
		}
		delete node;
	}


	template<class T>
	inline int SinglyLinkedList<T>::getSize() {
		return size;
	}


	template<class T>
	inline bool SinglyLinkedList<T>::isEmpty() {
		return (size == 0);
	}


	template<class T>
	void SinglyLinkedList<T>::insertEnd(T value) {
		auto *new_node = new SinglyNode<T>();
		new_node->setData(value);
		if (head == nullptr) {
			head = new_node;
		} else {
			SinglyNode<T> *temp = head;
			while (temp->getNext() != nullptr) {
				temp = temp->getNext();
			}
			temp->setNext(new_node);
		}
		size++;
	}


	template<class T>
	void SinglyLinkedList<T>::insertFront(T value) {
		auto *new_node = new SinglyNode<T>();
		new_node->setData(value);
		if (head == nullptr) {
			head = new_node;
			return;
		}
		new_node->setNext(head);
		head = new_node;
		size++;
	}


	template<class T>
	void SinglyLinkedList<T>::insertAt(int pos, T value) {
		if (pos < 0 || pos >= size) {
			throw IllegalPosition(pos);
		}
		auto *new_node = new SinglyNode<T>();
		new_node->setData(value);
		SinglyNode<T> *temp = head, *prev = temp;
		for (int i = 0; i < pos; ++i) {
			prev = temp;
			temp = temp->getNext();
		}
		new_node->setNext(temp);
		prev->setNext(new_node);
		size++;
	}


	template<class T>
	T SinglyLinkedList<T>::deleteFront() {
		if (head == nullptr) {
			throw Underflow("Linked list is empty");
		}
		auto temp = head;
		head = head->getNext();
		auto data = temp->getData();
		delete temp;
		size--;
		return data;
	}


	template<class T>
	T SinglyLinkedList<T>::deleteEnd() {
		if (head == nullptr) {
			throw Underflow("Linked list is empty");
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


	template<class T>
	T SinglyLinkedList<T>::deleteAt(int pos) {
		if (head == nullptr) {
			throw Underflow("Linked list is empty");
		}
		if (pos < 0 || pos >= size) {
			throw IllegalPosition(pos);
		}
		SinglyNode<T> *temp = head, *prev = temp;
		for (int i = 0; i <= pos; ++i) {
			prev = temp;
			temp = temp->getNext();
		}
		prev->setNext(temp->getNext());
		auto data = temp->getData();
		delete temp;
		size--;
		return data;
	}


	template<class T>
	T SinglyLinkedList<T>::get(int pos) {
		if (head == nullptr) {
			throw Underflow("Linked list is empty");
		}
		if (pos < 0 || pos >= size) {
			throw IllegalPosition(pos);
		}
		SinglyNode<T> *temp = head;
		for (int i = 0; i < pos; ++i) {
			temp = temp->getNext();
		}
		auto data = temp->getData();
		return data;
	}


	template<class T>
	void SinglyLinkedList<T>::clear() {
		destroy(head);
		head = nullptr;
		size = 0;
	}

	template<class T>
	void SinglyLinkedList<T>::print() {
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

}

#pragma clang diagnostic pop