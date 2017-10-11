#pragma clang diagnostic push

#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedImportStatement"

#pragma once

#include "array_circular_queue.h"
#include "array_queue.h"


namespace queue {

	template<class T>
	inline ArrayCircularQueue<T>::ArrayCircularQueue(const unsigned int max_size): MAX_SIZE(max_size) {
		array = new T[MAX_SIZE];
		front = rear = queue::UNINITIALIZED;
	}


	template<class T>
	inline ArrayCircularQueue<T>::~ArrayCircularQueue() {
		delete array;
	}


	template<class T>
	void ArrayCircularQueue<T>::print() {
		if (front == UNINITIALIZED) {
			std::cout << "Empty...\n";
			return;
		}
		std::cout << "[ ";
		if (front < rear) {
			for (int i = front; i <= rear; ++i) {
				std::cout << array[i] << " , ";
			}
		} else {
			for (int i = front; i < MAX_SIZE; i++) {
				std::cout << array[i] << " , ";
			}
			for (int i = 0; i < rear; ++i) {
				std::cout << array[i] << " , ";
			}
		}
		std::cout << " ]\n";
	}


	template<class T>
	inline bool ArrayCircularQueue<T>::isEmpty() {
		return front == UNINITIALIZED;
	}


	template<class T>
	inline int ArrayCircularQueue<T>::getSize() {
		return MAX_SIZE;
	}


	template<class T>
	inline int ArrayCircularQueue<T>::getAvailableSpace() {
		int used = (front < rear) ? (rear - front + 1) : ((MAX_SIZE - front) + (rear + 1));
		return MAX_SIZE - used;
	}


	template<class T>
	inline T ArrayCircularQueue<T>::peek() {
		if (front == UNINITIALIZED) {
			throw IllegalPosition(front);
		}
		return array[front];
	}


	template<class T>
	void ArrayCircularQueue<T>::enqueue(T data) {
		if ((front == 0 && rear + 1 == MAX_SIZE) || (rear + 1 == front)) {
			throw Overflow("Array Circular Queue overflow");
		}
		if (front == UNINITIALIZED && rear == UNINITIALIZED) {
			front = rear = 0;
			array[rear] = data;
		} else if (front > 0 && rear + 1 == MAX_SIZE) {
			rear = 0;
			array[rear] = 0;
		} else {
			rear++;
			array[rear] = data;
		}
	}

	template<class T>
	T ArrayCircularQueue<T>::dequeue() {
		if (front == UNINITIALIZED) {
			throw Underflow("Array Circular Queue underflow");
		}
		auto data = array[front];
		if (front + 1 == rear) {
			front = rear = UNINITIALIZED;
		} else if (front + 1 == MAX_SIZE && rear < front) {
			front = 0;
		} else {
			front++;
		}
	}

}


#pragma clang diagnostic pop