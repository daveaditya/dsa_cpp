#pragma clang diagnostic push

#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"


#pragma once

#include "node.h"
#include "linked_list.h"

namespace linked_list {

	using namespace nodes;

	template<class T>
	class CircularDoublyLinkedList : public CommonMethods, public LinkedList<T> {

	private:
		CircularDoublyNode<T> *head = nullptr;
		unsigned int size = 0;

		void destroy(CircularDoublyNode<T> *node);

	public:
		CircularDoublyLinkedList() = default;

		explicit CircularDoublyLinkedList(T data);

		~CircularDoublyLinkedList();

		void print() override;

		bool isEmpty() override;

		int getSize() override;

		// CircularDoublyLinkedList operations
		void insertFront(T data) override;

		void insertAt(int pos, T data) override;

		void insertEnd(T data) override;

		T deleteFront() override;

		T deleteAt(int pos) override;

		T deleteEnd() override;

		T get(int pos) override;

	};

}


#include "circular_doubly_linked_list.tpp"

#pragma clang diagnostic pop