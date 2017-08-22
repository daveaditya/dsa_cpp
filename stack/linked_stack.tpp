#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include "linked_stack.h"

namespace stack {

	template<class T>
	inline LinkedStack<T>::LinkedStack() {
		stack = new linked_list::SinglyLinkedList<T>();
	}


	template<class T>
	inline LinkedStack<T>::LinkedStack(T data) {
		stack = new linked_list::SinglyLinkedList<T>(data);
	}


	template<class T>
	LinkedStack<T>::~LinkedStack() {
		delete stack;
	}


	template<class T>
	void LinkedStack<T>::print() {
		stack->print();
	}

	template<class T>
	bool LinkedStack<T>::isEmpty() {
		return stack->isEmpty();
	}


	template<class T>
	int LinkedStack<T>::getSize() {
		return stack->getSize();
	}


	template<class T>
	T LinkedStack<T>::peek() {
		return stack->get(0);
	}


	template<class T>
	void LinkedStack<T>::push(T data) {
		stack->insertFront(data);
	}

	template<class T>
	T LinkedStack<T>::pop() {
		return stack->deleteFront();
	}

}


#pragma clang diagnostic pop