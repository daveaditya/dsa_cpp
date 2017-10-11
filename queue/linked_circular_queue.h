#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#include "../linked_lists/circular_singly_linked_list.h"
#include "queue.h"


namespace queue {

	template<class T>
	class LinkedCircularQueue : queue::Queue<T>, nodes::CommonMethods {

	private:
		linked_list::CircularSinglyLinkedList<T> *queue;

	public:

		explicit LinkedCircularQueue();

		explicit LinkedCircularQueue(T data);

		~LinkedCircularQueue();

		void print() override;

		bool isEmpty() override;

		int getSize() override;

		T peek() override;

		void enqueue(T data) override;

		T dequeue() override;

	};

}


#include "linked_circular_queue.tpp"

#pragma clang diagnostic pop