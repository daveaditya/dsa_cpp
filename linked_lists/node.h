#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma once

namespace nodes {

	template<class T>
	class SinglyNode {
	private:
		T data;
		SinglyNode *next;

	public:
		SinglyNode() = default;

		explicit SinglyNode(T data) {
			SinglyNode::data = data;
			next = nullptr;
		}

		void setData(T data) {
			SinglyNode::data = data;
		}

		virtual void setNext(SinglyNode *next) {
			SinglyNode::next = next;
		}

		T getData() {
			return data;
		}

		virtual SinglyNode *getNext() {
			return next;
		}
	};


	template<class T>
	class CircularNode {
	private:
		T data;
		CircularNode *next;

	public:
		CircularNode() {
			next = this;
		}

		explicit CircularNode(T data) {
			next = this;
			CircularNode::data = data;
		}

		T getData() const {
			return data;
		}

		void setData(T data) {
			CircularNode::data = data;
		}

		CircularNode *getNext() const {
			return next;
		}

		void setNext(CircularNode *next) {
			CircularNode::next = next;
		}
	};


	template<class T>
	class DoublyNode {
	private:
		DoublyNode *previous;
		T data;
		DoublyNode *next;

	public:
		DoublyNode() {
			previous = nullptr;
			next = nullptr;
		}

		explicit DoublyNode(T data) {
			previous = nullptr;
			DoublyNode::data = data;
			next = nullptr;
		}

		DoublyNode *getPrevious() const {
			return previous;
		}

		void setPrevious(DoublyNode *previous) {
			DoublyNode::previous = previous;
		}

		T getData() const {
			return data;
		}

		void setData(T data) {
			DoublyNode::data = data;
		}

		DoublyNode *getNext() const {
			return next;
		}

		void setNext(DoublyNode *next) {
			DoublyNode::next = next;
		}
	};


	template<class T>
	class CircularDoublyNode {
	private:
		CircularDoublyNode *previous;
		T data;
		CircularDoublyNode *next;

	public:
		CircularDoublyNode() {
			previous = this;
			next = this;
		}

		explicit CircularDoublyNode(T data) {
			CircularDoublyNode();
			CircularDoublyNode::data = data;
		}

		CircularDoublyNode *getPrevious() const {
			return previous;
		}

		void setPrevious(CircularDoublyNode *previous) {
			CircularDoublyNode::previous = previous;
		}

		T getData() const {
			return data;
		}

		void setData(T data) {
			CircularDoublyNode::data = data;
		}

		CircularDoublyNode *getNext() const {
			return next;
		}

		void setNext(CircularDoublyNode *next) {
			CircularDoublyNode::next = next;
		}
	};

	class CommonMethods {
	public:
		virtual void print() = 0;

		virtual inline bool isEmpty() = 0;

		virtual inline int getSize() = 0;
	};

}

#pragma clang diagnostic pop