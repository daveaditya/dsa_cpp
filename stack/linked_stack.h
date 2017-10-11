#pragma once
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#include "stack.h"
#include "../linked_lists/singly_linked_list.h"

namespace stack {

	template<class T>
	class LinkedStack : public Stack<T>, public nodes::CommonMethods {

	private:
		linked_list::SinglyLinkedList<T> *stack;

	public:
		explicit LinkedStack();

		explicit LinkedStack(T data);

		~LinkedStack();

		void print() override;

		bool isEmpty() override;

		int getSize() override;

		// stack operations
		T peek() override;

		void push(T data) override;

		T pop() override;
	};

}


#include "linked_stack.tpp"

#pragma clang diagnostic pop