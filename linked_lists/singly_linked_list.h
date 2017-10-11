#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"

#include "node.h"
#include "linked_list.h"

namespace linked_list {

	using namespace nodes;

	template<class T>
	class SinglyLinkedList : public CommonMethods, public LinkedList<T> {
	private:
		SinglyNode<T> *head = nullptr;
		int size = 0;

		void destroy(SinglyNode<T> *node);

	public:

		SinglyLinkedList() = default;

		explicit SinglyLinkedList(T value);

		~SinglyLinkedList();

		int getSize() override;

		bool isEmpty() override;

		void clear();

		void print() override;

		// Linked List algorithms
		void insertEnd(T value) override;

		void insertFront(T value) override;

		void insertAt(int pos, T value) override;

		T deleteFront() override;

		T deleteEnd() override;

		T deleteAt(int pos) override;

		T get(int pos) override;
	};

}

#include "singly_linked_list.tpp"

#pragma clang diagnostic pop