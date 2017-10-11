#pragma clang diagnostic push

#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#pragma once

#include "linked_deque.h"


namespace queue {

	template<class T>
	inline LinkedDeque<T>::LinkedDeque() {
		queue = new linked_list::SinglyLinkedList<T>();
	}

	template<class T>
	inline LinkedDeque<T>::LinkedDeque(T data) {
		queue = new linked_list::SinglyLinkedList<T>(data);
	}


	template<class T>
	LinkedDeque<T>::~LinkedDeque() {
		delete queue;
	}


	template<class T>
	void LinkedDeque<T>::enqueueFront(T data) {
		queue->insertFront(data);
	}


	template<class T>
	void LinkedDeque<T>::enqueueRear(T data) {
		queue->insertEnd(data);
	}


	template<class T>
	T LinkedDeque<T>::dequeueFront() {
		return queue->deleteFront();
	}


	template<class T>
	T LinkedDeque<T>::dequeueEnd() {
		return queue->deleteEnd();
	}


	template<class T>
	T LinkedDeque<T>::peek() {
		return queue->get(0);
	}


	template<class T>
	void LinkedDeque<T>::print() {
		queue->print();
	}


	template<class T>
	inline bool LinkedDeque<T>::isEmpty() {
		return queue->isEmpty();
	}


	template<class T>
	inline int LinkedDeque<T>::getSize() {
		return queue->getSize();
	}


}

#pragma clang diagnostic pop