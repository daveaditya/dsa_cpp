#pragma once


#include "../tree/node.h"


namespace tree {

	template<class T>
	class BinaryTree {

	private:
		Node<T> *root;

		unsigned int size = 0;

		void deleteTree(Node<T> *node);

		void performPrefixTraversal(Node<T> *node);

		void performInfixTraversal(Node<T> *node);

		void performPostfixTraversal(Node<T> *node);


	public:
		BinaryTree() = default;

		explicit BinaryTree(T data);

		explicit BinaryTree(Node<T> *root);

		~BinaryTree();

		void insert(T data);

		void remove(T data);

		void getPrefix();

		void getInfix();

		void getPostfix();

	};

}

#include "binary_tree.tpp"