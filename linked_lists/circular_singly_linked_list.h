#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma once

#include "node.h"

namespace linked_list {

	using namespace nodes;

	template<class T>
	class CircularSinglyLinkedList : public CommonMethods {
	private:
		CircularNode<T> *head = nullptr;
		int size = 0;

		void destroy(CircularNode<T> *node);

	public:
		CircularSinglyLinkedList() = default;

		explicit CircularSinglyLinkedList(T data);

		~CircularSinglyLinkedList();

		bool isEmpty() override;

		int getSize() override;

		void clear();

		void print() override;

		void insertFront(T data);

		void insertEnd(T data);

		void insertAt(T data, int pos);

		T deleteFront();

		T deleteEnd();

		T deleteAt(int pos);
	};

}

#include "circular_singly_linked_list.tpp"

#pragma clang diagnostic pop