#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedImportStatement"

#pragma once

#include <iostream>
#include "array_queue.h"
#include "../exceptions.h"


namespace queue {

	template<class T>
	inline ArrayQueue<T>::ArrayQueue(unsigned int max_size): MAX_SIZE(max_size) {
		array = new T[max_size];
		front = UNINITIALIZED;
		rear = UNINITIALIZED;
	}


	template<class T>
	inline ArrayQueue<T>::~ArrayQueue() {
		delete array;
	}


	template<class T>
	void ArrayQueue<T>::print() {
		if (front == UNINITIALIZED) {
			std::cout << "Empty\n";
			return;
		}
		std::cout << "[ ";
		for (int i = front; i <= rear; ++i) {
			std::cout << array[i] << " , ";
		}
		std::cout << " ]\n";
	}


	template<class T>
	inline bool ArrayQueue<T>::isEmpty() {
		return rear == MAX_SIZE - 1;
	}


	template<class T>
	inline int ArrayQueue<T>::getSize() {
		return MAX_SIZE;
	}


	template<class T>
	inline int ArrayQueue<T>::getAvailableSpace() {
		return MAX_SIZE - rear;
	}


	template<class T>
	void ArrayQueue<T>::enqueue(T data) {
		if (rear + 1 == MAX_SIZE) {
			throw Overflow("Queue Overflow");
		}
		if (front == UNINITIALIZED) {
			front = 0;
			rear = 0;
			array[rear] = data;
		} else {
			rear++;
			array[rear] = data;
		}
	}


	template<class T>
	T ArrayQueue<T>::peek() {
		if (front != UNINITIALIZED) {
			return array[front];
		}
		throw Underflow("Array Queue Empty");
	}


	template<class T>
	T ArrayQueue<T>::dequeue() {
		if (front == UNINITIALIZED) {
			throw Underflow("Array Queue Underflow");
		}
		auto data = array[front];
		if (front + 1 == MAX_SIZE) {
			front = rear = UNINITIALIZED;
		} else {
			front++;
		}
		return data;
	}


}
#pragma clang diagnostic pop