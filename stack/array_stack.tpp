#include <iostream>
#include "array_stack.h"


namespace stack {

	template<class T>
	ArrayStack<T>::ArrayStack(unsigned int max_size):MAX_SIZE(max_size) {
		array = new T[MAX_SIZE];
	}


	template<class T>
	ArrayStack<T>::~ArrayStack() {
		delete array;
	}


	template<class T>
	int ArrayStack<T>::getSize() {
		return MAX_SIZE;
	}


	template<class T>
	unsigned int ArrayStack<T>::getFreeSpace() {
		return MAX_SIZE - top;
	}


	template<class T>
	T ArrayStack<T>::peek() {
		return array[top];
	}


	template<class T>
	T ArrayStack<T>::pop() {
		if (top == -1) {
			throw Underflow("Array Stack empty");
		}
		auto data = array[top];
		top--;
		return data;
	}


	template<class T>
	void ArrayStack<T>::push(T data) {
		if (top + 1 == MAX_SIZE) {
			throw Overflow("Array Stack Overflow");
		}
		top++;
		array[top] = data;
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
	bool ArrayStack<T>::isEmpty() {
		return top == NOT_INITIALIZED;
	}

}