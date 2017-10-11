#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#include "queue.h"
#include "../linked_lists/singly_linked_list.h"

namespace queue {

	template<class T>
	class LinkedQueue : public Queue<T>, public nodes::CommonMethods {
	private:
		linked_list::SinglyLinkedList<T> *queue;

	public:

		explicit LinkedQueue();

		explicit LinkedQueue(T data);

		~LinkedQueue();

		int getSize() override;

		void print() override;

		bool isEmpty() override;

		// Queue operations
		T peek() override;

		void enqueue(T data) override;

		T dequeue() override;

	};

}

#include "linked_queue.tpp"

#pragma clang diagnostic pop