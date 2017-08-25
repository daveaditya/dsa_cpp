#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"


#pragma once

#include "../linked_lists/node.h"


namespace queue {

	template<class T>
	class ArrayDeque : public nodes::CommonMethods {

	private:
		T *array;
		int front;
		int rear;
		const unsigned int MAX_SIZE;

	public:
		explicit ArrayDeque(unsigned int max_size);

		~ArrayDeque();

		void enqueueFront(T data);

		void enqueueRear(T data);

		T dequeueFront();

		T dequeueRear();

		void print() override;

		bool isEmpty() override;

		int getSize() override;

		int getAvailableSpace();

	};

}


#include "array_deque.tpp"

#pragma clang diagnostic pop