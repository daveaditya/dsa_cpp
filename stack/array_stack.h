#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "ClangTidyInspection"

#pragma ide diagnostic ignored "OCUnusedStructInspection"

#pragma once

#include "../linked_lists/node.h"

namespace stack {

	const int UNINITIALIZED = -1;

	template<class T>
	class ArrayStack : public nodes::CommonMethods {
	private:
		T *array;
		const unsigned int MAX_SIZE;
		int top = UNINITIALIZED;

	public:
		explicit ArrayStack(unsigned int max_size);

		~ArrayStack();

		unsigned int getAvailableSpace();

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

#pragma clang diagnostic pop