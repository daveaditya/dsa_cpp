#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"

#pragma once

#include "../linked_lists/singly_linked_list.h"
#include "queue.h"


namespace queue {

	template<class T>
	class LinkedDeque : public nodes::CommonMethods {
	private:
		linked_list::SinglyLinkedList<T> *queue;

	public:
		explicit LinkedDeque();

		explicit LinkedDeque(T data);

		~LinkedDeque();

		T peek();

		void enqueueFront(T data);

		void enqueueRear(T data);

		T dequeueFront();

		T dequeueEnd();

		void print() override;

		bool isEmpty() override;

		int getSize() override;
	};

}


#include "linked_deque.tpp"

#pragma clang diagnostic pop