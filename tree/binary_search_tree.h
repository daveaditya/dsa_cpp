#pragma once


#include "node.h"

namespace tree {


	// Warning only numeric types supported
	template<class T>
	class BinarySearchTree {

	private:
		Node<T> *root;

		unsigned int size = 0;

		void performPrefixTraversal(Node<T> *node);

		void performInfixTraversal(Node<T> *node);

		void performPostfixTraversal(Node<T> *node);

		void deleteTree(Node<T> *node);

		void findAndInsertAt(T data, Node<T> *node);

		void findAndRemove(T data, Node<T> *node, Node<T> *parent);


	public:
		BinarySearchTree() = default;

		explicit BinarySearchTree(T data);

		~BinarySearchTree();

		void insert(T data);

		void remove(T data);

		void getPrefix();

		void getInfix();

		void getPostfix();

	};

}

#include "binary_search_tree.tpp"