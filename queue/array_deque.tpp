#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedImportStatement"

#pragma once

#include "array_deque.h"
#include "array_queue.h"


namespace queue {

	template<class T>
	ArrayDeque<T>::ArrayDeque(unsigned int max_size): MAX_SIZE(max_size) {
		array = new T[max_size];
		front = rear = UNINITIALIZED;
	}


	template<class T>
	ArrayDeque<T>::~ArrayDeque() {
		delete array;
	}


	template<class T>
	void ArrayDeque<T>::enqueueFront(T data) {
		if (front - 1 == UNINITIALIZED) {
			throw Overflow("Array Deque Overflow");
		}
		if (front == UNINITIALIZED) {
			front = rear = 0;
			array[front] = data;
		} else {
			front--;
			array[front] = data;
		}
	}


	template<class T>
	void ArrayDeque<T>::enqueueRear(T data) {
		if (rear + 1 == MAX_SIZE) {
			throw Overflow("Array Deque Overflow");
		}
		if (front == UNINITIALIZED) {
			front = rear = 0;
			array[rear] = data;
			return;
		} else {
			rear++;
			array[rear] = data;
		}
	}


	template<class T>
	T ArrayDeque<T>::dequeueFront() {
		if (front == UNINITIALIZED) {
			throw Underflow("Array Deque Underflow");
		}
		if (front + 1 > rear || front + 1 == MAX_SIZE) {
			auto data = array[front];
			front = rear = UNINITIALIZED;
			return data;
		} else {
			auto data = array[front++];
			return data;
		}
	}


	template<class T>
	T ArrayDeque<T>::dequeueRear() {
		if (front == UNINITIALIZED && rear == UNINITIALIZED) {
			throw Underflow("Array Deque Underflow");
		}
		if (rear - 1 == UNINITIALIZED) {
			auto data = array[rear];
			rear = UNINITIALIZED;
			return data;
		} else {
			auto data = array[rear--];
			return data;
		}
	}


	template<class T>
	void ArrayDeque<T>::print() {
		if (front == UNINITIALIZED) {
			std::cout << "Empty...\n";
			return;
		}
		std::cout << "[ ";
		for (int i = front; i <= rear; ++i) {
			std::cout << array[i] << " , ";
		}
		std::cout << " ]\n";
	}


	template<class T>
	bool ArrayDeque<T>::isEmpty() {
		return front == UNINITIALIZED;
	}


	template<class T>
	int ArrayDeque<T>::getSize() {
		return MAX_SIZE;
	}


	template<class T>
	int ArrayDeque<T>::getAvailableSpace() {
		return MAX_SIZE - (rear - front + 1);
	}

}


#pragma clang diagnostic pop