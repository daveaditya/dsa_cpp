#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#pragma once

#include "../linked_lists/node.h"

namespace queue {

	const int UNINITIALIZED = -1;

	template<class T>
	class ArrayQueue : public Queue<T>, public nodes::CommonMethods {
		int front;
	private:
		T *array;
		int rear;
		const unsigned int MAX_SIZE;

	public:
		explicit ArrayQueue(unsigned int max_size);

		~ArrayQueue();

		void print() override;

		bool isEmpty() override;

		int getSize() override;

		int getAvailableSpace();

		T peek() override;

		void enqueue(T data) override;

		T dequeue() override;
	};

}


#include "array_queue.tpp"

#pragma clang diagnostic pop