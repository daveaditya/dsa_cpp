#pragma once

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

namespace stack {

	template<class T>
	class Stack {
	public:
		virtual T peek() = 0;

		virtual void push(T data) = 0;

		virtual T pop() = 0;
	};

}

#pragma clang diagnostic pop