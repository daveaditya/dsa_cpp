#include <iostream>
#include "binary_tree.h"


namespace tree {

	template<class T>
	BinaryTree<T>::BinaryTree(T data) {
		BinaryTree::root = new Node<T>(data);
		size++;
	}


	template<class T>
	BinaryTree<T>::BinaryTree(Node <T> *root) {
		BinaryTree::root = root;
	}


	template<class T>
	void BinaryTree<T>::performPrefixTraversal(Node <T> *node) {
		if (node != nullptr) {
			cout << node->getData() << "\t";
			this->performPrefixTraversal(node->getLeftChild());
			this->performPrefixTraversal(node->getRightChild());
		}
	}


	template<class T>
	BinaryTree<T>::~BinaryTree() {
		deleteTree(this->root);
	}


	template<class T>
	void BinaryTree<T>::deleteTree(Node <T> *node) {
		if (node != nullptr) {
			deleteTree(node->getLeftChild());
			deleteTree(node->getRightChild());
			delete node;
		}
	}


	template<class T>
	void BinaryTree<T>::performInfixTraversal(Node <T> *node) {
		if (node != nullptr) {
			this->performInfixTraversal(node->getLeftChild());
			cout << node->getData() << "\t";
			this->performInfixTraversal(node->getRightChild());
		}
	}


	template<class T>
	void BinaryTree<T>::performPostfixTraversal(Node <T> *node) {
		if (node != nullptr) {
			this->performPostfixTraversal(node->getLeftChild());
			this->performPostfixTraversal(node->getRightChild());
			cout << node->getData() << "\t";
		}
	}


	template<class T>
	void BinaryTree<T>::insert(T data) {

	}


	template<class T>
	void BinaryTree<T>::remove(T data) {

	}


	template<class T>
	void BinaryTree<T>::getPrefix() {
		this->performPrefixTraversal(this->root);
		cout << "\n";
	}


	template<class T>
	void BinaryTree<T>::getInfix() {
		this->performInfixTraversal(this->root);
		cout << "\n";
	}


	template<class T>
	void BinaryTree<T>::getPostfix() {
		this->performPostfixTraversal(this->root);
		cout << "\n";
	}

}