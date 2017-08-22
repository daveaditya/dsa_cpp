#pragma once

#include "../linked_lists/singly_linked_list.h"

namespace stack {

	template<class T>
	class LinkedStack : public nodes::CommonMethods {

	private:
		linked_list::SinglyLinkedList<T> *stack;

	public:
		explicit LinkedStack();

		explicit LinkedStack(T data);

		~LinkedStack();

		// stack operations
		T peek();

		void print() override;

		bool isEmpty() override;

		int getSize() override;

		void push(T data);

		T pop();
	};

}


#include "linked_stack.tpp"