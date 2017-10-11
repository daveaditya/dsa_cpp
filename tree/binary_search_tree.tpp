#include "binary_search_tree.h"
#include "../exceptions.h"


namespace tree {

	template<class T>
	BinarySearchTree<T>::BinarySearchTree(T data) {
		BinarySearchTree::root = new tree::Node<T>(data);
	}


	template<class T>
	BinarySearchTree<T>::~BinarySearchTree() {
		this->deleteTree(this->root);
	}


	template<class T>
	void BinarySearchTree<T>::deleteTree(Node <T> *node) {
		if (node != nullptr) {
			this->deleteTree(node->getLeftChild());
			this->deleteTree(node->getRightChild());
			delete node;
		}
	}


	template<class T>
	void BinarySearchTree<T>::performPrefixTraversal(Node <T> *node) {
		if (node != nullptr) {
			cout << node->getData() << "\t";
			this->performPrefixTraversal(node->getLeftChild());
			this->performPrefixTraversal(node->getRightChild());
		}
	}


	template<class T>
	void BinarySearchTree<T>::performInfixTraversal(Node <T> *node) {
		if (node != nullptr) {
			this->performInfixTraversal(node->getLeftChild());
			cout << node->getData() << "\t";
			this->performInfixTraversal(node->getRightChild());
		}
	}


	template<class T>
	void BinarySearchTree<T>::performPostfixTraversal(Node <T> *node) {
		if (node != nullptr) {
			this->performPostfixTraversal(node->getLeftChild());
			this->performPostfixTraversal(node->getRightChild());
			cout << node->getData() << "\t";
		}
	}


	template<class T>
	void BinarySearchTree<T>::getPrefix() {
		this->performPrefixTraversal(this->root);
		cout << "\n";
	}


	template<class T>
	void BinarySearchTree<T>::getInfix() {
		this->performInfixTraversal(this->root);
		cout << "\n";
	}


	template<class T>
	void BinarySearchTree<T>::getPostfix() {
		this->performPostfixTraversal(this->root);
		cout << "\n";
	}


	template<class T>
	void BinarySearchTree<T>::findAndInsertAt(T data, Node <T> *node) {
		if (data == node->getData()) {
			return;
		} else if (data <= node->getData()) {
			if (node->getLeftChild() == nullptr) {
				node->setLeftChild(new Node<T>(data));
				size++;
			} else {
				findAndInsertAt(data, node->getLeftChild());
			}
		} else if (data > node->getData()) {
			if (node->getRightChild() == nullptr) {
				node->setRightChild(new Node<T>(data));
				size++;
			} else {
				findAndInsertAt(data, node->getRightChild());
			}
		}
	}


	template<class T>
	void BinarySearchTree<T>::insert(T data) {

		if (this->size == 0) {
			root = new Node<T>(data);
			size = 1;
			return;
		} else {
			this->findAndInsertAt(data, this->root);
		}

	}


	template<class T>
	void BinarySearchTree<T>::findAndRemove(T data, Node <T> *node, Node <T> *parent) {

		if (data == node->getData()) {

			// If the node has no children
			if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr) {
				if (parent->getLeftChild() == node) {
					parent->setLeftChild(nullptr);
				} else {
					parent->setRightChild(nullptr);
				}
				size--;
				delete node;
				return;
			}

			// If the node has single child
			// If the left child is only present
			if (node->getLeftChild() != nullptr && node->getRightChild() == nullptr) {
				if (node == parent->getLeftChild()) {
					parent->setLeftChild(node->getLeftChild());
				} else {
					parent->setRightChild(node->getLeftChild());
				}
				size--;
				delete node;
				return;
				// If the right child is only present
			} else if (node->getLeftChild() == nullptr && node->getRightChild() != nullptr) {
				if (node == parent->getLeftChild()) {
					parent->setLeftChild(node->getRightChild());
				} else {
					parent->setRightChild(node->getRightChild());
				}
				size--;
				delete node;
				return;
			}

			// If the node has both children

			size--;

		} else if (data < node->getData()) {
			this->findAndRemove(data, node->getLeftChild(), node);
		} else if (data > node->getData()) {
			this->findAndRemove(data, node->getRightChild(), node);
		}

	}


	template<class T>
	void BinarySearchTree<T>::remove(T data) {

		if (this->size == 0) {
			throw new Underflow("Tree is already empty");
		}
		findAndRemove(data, this->root, this->root);

	}

}