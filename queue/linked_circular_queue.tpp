#pragma once

#include "linked_circular_queue.h"


namespace queue {

	template<class T>
	LinkedCircularQueue<T>::LinkedCircularQueue() {
		queue = new linked_list::CircularSinglyLinkedList<T>();
	}


	template<class T>
	LinkedCircularQueue<T>::LinkedCircularQueue(T data) {
		queue = new linked_list::CircularSinglyLinkedList<T>(data);
	}


	template<class T>
	LinkedCircularQueue<T>::~LinkedCircularQueue() {
		if (queue != nullptr) {
			delete queue;
		}
	}


	template<class T>
	int LinkedCircularQueue<T>::getSize() {
		return queue->getSize();
	}


	template<class T>
	bool LinkedCircularQueue<T>::isEmpty() {
		return queue->isEmpty();
	}


	template<class T>
	T LinkedCircularQueue<T>::peek() {
		if (queue == nullptr) {
			throw IllegalPosition(0);
		}
		return queue->get(0);
	}


	template<class T>
	void LinkedCircularQueue<T>::print() {
		queue->print();
	}


	template<class T>
	void LinkedCircularQueue<T>::enqueue(T data) {
		queue->insertEnd(data);
	}


	template<class T>
	T LinkedCircularQueue<T>::dequeue() {
		return queue->deleteFront();
	}

}