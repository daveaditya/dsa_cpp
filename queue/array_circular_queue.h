#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#pragma once

#include "queue.h"
#include "../linked_lists/node.h"


namespace queue {

	template<class T>
	class ArrayCircularQueue : public queue::Queue<T>, public nodes::CommonMethods {

	private:
		T *array;
		const int MAX_SIZE;
		int front;
		int rear;

	public:
		explicit ArrayCircularQueue(const unsigned int max_size);

		~ArrayCircularQueue();

		void print() override;

		bool isEmpty() override;

		int getSize() override;

		int getAvailableSpace();

		T peek() override;

		void enqueue(T data) override;

		T dequeue() override;
	};

}


#include "array_circular_queue.tpp"

#pragma clang diagnostic pop