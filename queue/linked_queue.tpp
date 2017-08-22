#include "linked_queue.h"


namespace queue {

	template<class T>
	LinkedQueue<T>::LinkedQueue() {
		queue = new linked_list::SinglyLinkedList<T>();
	}


	template<class T>
	LinkedQueue<T>::LinkedQueue(T data) {
		queue = new linked_list::SinglyLinkedList<T>(data);
	}


	template<class T>
	LinkedQueue<T>::~LinkedQueue() {
		delete queue;
	}


	template<class T>
	int LinkedQueue<T>::getSize() {
		return queue->getSize();
	}


	template<class T>
	T LinkedQueue<T>::peek() {
		return queue->get(0);
	}


	template<class T>
	void LinkedQueue<T>::insert(T data) {
		queue->insertEnd(data);
	}


	template<class T>
	T LinkedQueue<T>::remove() {
		return queue->deleteFront();
	}

	template<class T>
	void LinkedQueue<T>::print() {
		queue->print();
	}


	template<class T>
	bool LinkedQueue<T>::isEmpty() {
		return queue->isEmpty();
	}

}
