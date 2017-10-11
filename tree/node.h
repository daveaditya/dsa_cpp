#pragma once

#include <iostream>


namespace tree {

	using namespace std;

	template<class T>
	class Node {

	private:
		Node *leftChild;
		T data;
		Node *rightChild;

	public:
		Node() = default;

		explicit Node(T data) {
			Node::data = data;
			Node::leftChild = Node::rightChild = nullptr;
		}

		explicit Node(Node *leftChild, T data, Node *rightChild) {
			Node::leftChild = leftChild;
			Node::data = data;
			Node::rightChild = rightChild;
		}

		Node *getLeftChild() const {
			return leftChild;
		}

		void setLeftChild(Node *leftChild) {
			Node::leftChild = leftChild;
		}

		T getData() const {
			return data;
		}

		void setData(T data) {
			Node::data = data;
		}

		Node *getRightChild() const {
			return rightChild;
		}

		void setRightChild(Node *rightChild) {
			Node::rightChild = rightChild;
		}

	};

}

