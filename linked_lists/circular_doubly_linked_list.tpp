#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedImportStatement"


#include "circular_doubly_linked_list.h"
#include "../exceptions.h"


namespace linked_list {

	template<class T>
	inline CircularDoublyLinkedList<T>::CircularDoublyLinkedList(T data) {
		head = new CircularDoublyNode<T>(data);
		size = 1;
	}


	template<class T>
	CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
		if (head != nullptr) {
			destroy(head);
		}
	}


	template<class T>
	void CircularDoublyLinkedList<T>::destroy(CircularDoublyNode <T> *node) {
		if (node->getNext() != head) {
			return destroy(node->getNext());
		}
		delete node;
	}


	template<class T>
	void CircularDoublyLinkedList<T>::print() {
		if (head == nullptr) {
			std::cout << "Empty\n";
			return;
		}
		auto *temp = head;
		std::cout << "[ ";
		while (true) {
			std::cout << temp->getData() << ", ";
			temp = temp->getNext();
			if (temp == head) {
				break;
			}
		}
		std::cout << " ]\n";
	}


	template<class T>
	inline bool CircularDoublyLinkedList<T>::isEmpty() {
		return size == 0;
	}


	template<class T>
	inline int CircularDoublyLinkedList<T>::getSize() {
		return size;
	}


	template<class T>
	void CircularDoublyLinkedList<T>::insertFront(T data) {
		auto *new_node = new CircularDoublyNode<T>(data);
		if (head == nullptr) {
			head = new_node;
			return;
		}
		auto *last_node = head;
		while (last_node->getNext() != head) {
			last_node = last_node->getNext();
		}
		last_node->setNext(new_node);
		new_node->setPrevious(last_node);
		new_node->setNext(head);
		head->setPrevious(new_node);
		head = new_node;
		size++;
	}


	template<class T>
	void CircularDoublyLinkedList<T>::insertAt(int pos, T data) {
		if (pos < 0 || pos >= size) {
			throw IllegalPosition(pos);
		}
		auto *new_node = new CircularDoublyNode<T>(data);
		auto *prev = head;
		for (int i = 0; i < pos; ++i) {
			prev = prev->getNext();
		}
		new_node->setNext(prev->getNext());
		prev->getNext()->setPrevious(new_node);
		prev->setNext(new_node);
		new_node->setPrevious(prev);
	}


	template<class T>
	void CircularDoublyLinkedList<T>::insertEnd(T data) {
		auto *new_node = new CircularDoublyNode<T>(data);
		if (head == nullptr) {
			head = new_node;
			return;
		}
		auto *last_node = head;
		while (last_node->getNext() != head) {
			last_node = last_node->getNext();
		}
		last_node->setNext(new_node);
		new_node->setPrevious(last_node);
		new_node->setNext(head);
		head->setPrevious(new_node);
		size++;
	}


	template<class T>
	T CircularDoublyLinkedList<T>::deleteFront() {
		if (head == nullptr) {
			throw Underflow("Circular Doubly Linked List underflow");
		}
		auto *to_delete = head, *to_last = head;
		while (to_last->getNext() != head) {
			to_last = to_last->getNext();
		}
		head = head->getNext();
		to_last->setNext(head);
		head->setPrevious(to_last);
		auto data = to_delete->getData();
		delete to_delete;
		return data;
	}


	template<class T>
	T CircularDoublyLinkedList<T>::deleteAt(int pos) {
		if (pos < 0 || pos >= size) {
			throw IllegalPosition(pos);
		}
		auto *to_delete = head, *prev = head;
		for (int i = 0; i <= pos; ++i) {
			prev = to_delete;
			to_delete = to_delete->getNext();
		}
		prev->setNext(to_delete->getNext());
		to_delete->getNext()->setPrevious(prev);
		auto data = to_delete->getData();
		delete to_delete;
		return data;
	}


	template<class T>
	T CircularDoublyLinkedList<T>::deleteEnd() {
		if (head == nullptr) {
			throw Underflow("Circular Doubly Linked List underflow");
		}
		auto *to_delete = head;
		while (to_delete->getNext() != head) {
			to_delete = to_delete->getNext();
		}
		to_delete->getPrevious()->setNext(head);
		head->setPrevious(to_delete->getPrevious());
		auto data = to_delete->getData();
		delete to_delete;
		return data;
	}


	template<class T>
	T CircularDoublyLinkedList<T>::get(int pos) {
		if (head == nullptr) {
			throw Underflow("Linked list is empty");
		}
		if (pos < 0 || pos >= size) {
			throw IllegalPosition(pos);
		}
		auto *temp = head;
		for (int i = 0; i <= pos; ++i) {
			temp = temp->getNext();
		}
		return temp->getData();
	}

}
#pragma clang diagnostic pop