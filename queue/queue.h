#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace queue {

	template<class T>
	class Queue {
	public:
		virtual T peek() = 0;

		virtual void enqueue(T data) = 0;

		virtual T dequeue() = 0;
	};

}

#pragma clang diagnostic pop