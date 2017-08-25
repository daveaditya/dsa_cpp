#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace linked_list {

	template<class T>
	class LinkedList {

	public:
		virtual void insertFront(T data) = 0;

		virtual void insertAt(int pos, T data) = 0;

		virtual void insertEnd(T data) = 0;

		virtual T deleteFront() = 0;

		virtual T deleteAt(int pos) = 0;

		virtual T deleteEnd() = 0;

		virtual T get(int pos) = 0;
	};

}

#pragma clang diagnostic pop