#pragma once

#include "../linked_lists/node.h"

namespace stack {

	const int NOT_INITIALIZED = -1;

	template<class T>
	class ArrayStack : public nodes::CommonMethods {
	private:
		T *array;
		const unsigned int MAX_SIZE;
		int top = NOT_INITIALIZED;

	public:
		explicit ArrayStack(unsigned int max_size);

		~ArrayStack();

		unsigned int getFreeSpace();

		void print() override;

		bool isEmpty() override;

		int getSize() override;

		// stack operations
		T peek();

		void push(T data);

		T pop();
	};

}

#include "array_stack.tpp"