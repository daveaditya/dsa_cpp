#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedImportStatement"

#pragma once

#include <iostream>
#include "array_stack.h"
#include "../exceptions.h"


namespace stack {

	template<class T>
	inline ArrayStack<T>::ArrayStack(unsigned int max_size):MAX_SIZE(max_size) {
		array = new T[MAX_SIZE];
	}


	template<class T>
	inline ArrayStack<T>::~ArrayStack() {
		delete array;
	}


	template<class T>
	void ArrayStack<T>::print() {
		if (top == -1) {
			std::cout << "\nEmpty...";
			return;
		}
		std::cout << "[ ";
		for (int i = top; i >= 0; i--) {
			std::cout << array[i] << ", ";
		}
		std::cout << "]\n";
	}


	template<class T>
	inline bool ArrayStack<T>::isEmpty() {
		return top == UNINITIALIZED;
	}


	template<class T>
	inline int ArrayStack<T>::getSize() {
		return MAX_SIZE;
	}


	template<class T>
	inline unsigned int ArrayStack<T>::getAvailableSpace() {
		return MAX_SIZE - top;
	}


	template<class T>
	inline T ArrayStack<T>::peek() {
		if (top != UNINITIALIZED) {
			return array[top];
		}
		throw Underflow("Array Stack Uninitialized");
	}


	template<class T>
	inline T ArrayStack<T>::pop() {
		if (top == -1) {
			throw Underflow("Array Stack empty");
		}
		auto data = array[top];
		top--;
		return data;
	}


	template<class T>
	inline void ArrayStack<T>::push(T data) {
		if (top + 1 == MAX_SIZE) {
			throw Overflow("Array Stack Overflow");
		}
		top++;
		array[top] = data;
	}

}
#pragma clang diagnostic pop