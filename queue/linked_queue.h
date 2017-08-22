#pragma once

#include "../linked_lists/singly_linked_list.h"

namespace queue {

	template<class T>
	class LinkedQueue : nodes::CommonMethods {
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
		T peek();

		void insert(T data);

		T remove();

	};

}

#include "linked_queue.tpp"
