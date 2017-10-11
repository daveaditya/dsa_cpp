#include "tester.h"
#include "linked_lists/singly_linked_list.h"
#include "linked_lists/circular_singly_linked_list.h"
#include "linked_lists/doubly_linked_list.h"
#include "stack/linked_stack.h"
#include "stack/array_stack.h"
#include "queue/linked_queue.h"
#include "queue/array_queue.h"
#include "linked_lists/circular_doubly_linked_list.h"
#include "queue/linked_circular_queue.h"
#include "queue/linked_deque.h"
#include "queue/array_circular_queue.h"
#include "queue/array_deque.h"
#include "tree/binary_tree.h"
#include "tree/binary_search_tree.h"
#include "sorting/sorting.h"
#include "util/utility.h"
#include "search/Searching.h"


void Tester::singlyLinkedList() {

	cout << "\n\n" << "***SINGLY LINKED LIST***" << endl;
	auto *list = new linked_list::SinglyLinkedList<int>();
	for (int i = 0; i < 9; ++i) {
		list->insertEnd(i);
	}
	list->insertFront(11);
	list->insertEnd(22);
	list->print();
	list->insertAt(2, 33);
	list->print();
	list->deleteFront();
	list->print();
	list->deleteEnd();
	list->print();
	list->deleteAt(4);
	list->print();
	list->clear();
	list->print();

	linked_list::SinglyLinkedList<int> list2;
	list2.insertEnd(10);
	list2.insertFront(11);
	list2.print();

	delete list;

}


void Tester::circularLinkedList() {

	cout << "\n\n" << "***CIRCULAR LINKED LIST***" << endl;
	auto *c_list = new linked_list::CircularSinglyLinkedList<int>();
	for (int i = 0; i < 10; i++) {
		c_list->insertEnd(i);
	}
	c_list->insertFront(11);
	c_list->insertFront(22);
	c_list->print();

	c_list->insertAt(4, 44);
	c_list->print();

	c_list->deleteFront();
	c_list->deleteFront();
	c_list->print();
	c_list->deleteEnd();
	c_list->deleteEnd();
	c_list->print();
	c_list->deleteAt(2);
	c_list->print();

	c_list->clear();
	c_list->print();

	delete c_list;

}


void Tester::doublyLinkedList() {

	cout << "\n\n" << "***DOUBLY LINKED LIST***" << endl;
	auto *d_list = new linked_list::DoublyLinkedList<int>();
	for (int i = 0; i < 10; ++i) {
		d_list->insertEnd(i);
	}
	d_list->print();

	d_list->insertEnd(11);
	d_list->insertEnd(22);
	d_list->insertEnd(44);
	d_list->insertAt(3, 33);
	d_list->print();

	d_list->deleteFront();
	d_list->deleteEnd();
	d_list->deleteAt(3);
	d_list->print();

	delete d_list;

}


void Tester::circularDoublyLinkedList() {

	cout << "\n\n" << "***CIRCULAR DOUBLY LINKED LIST***" << endl;
	auto *cd_list = new linked_list::CircularDoublyLinkedList<int>();
	for (int i = 0; i < 10; i++) {
		cd_list->insertEnd(i);
	}
	cd_list->print();
	cd_list->insertEnd(11);
	cd_list->insertEnd(22);
	cd_list->insertEnd(44);
	cd_list->print();
	cd_list->insertAt(3, 33);
	cd_list->print();

	cd_list->deleteFront();
	cd_list->print();
	cd_list->deleteEnd();
	cd_list->print();
	cd_list->deleteAt(3);
	cd_list->print();

	delete cd_list;

}


void Tester::linkedStack() {

	cout << "\n\n" << "***LINKED STACK***" << endl;
	auto *l_stack = new stack::LinkedStack<int>();
	for (unsigned int i = 0; i < 10; i++) {
		l_stack->push(i);
	}
	cout << l_stack->peek() << endl;
	l_stack->print();
	l_stack->pop();
	l_stack->pop();
	l_stack->pop();
	cout << l_stack->peek() << endl;
	l_stack->print();

	delete l_stack;

}


void Tester::arrayStack() {

	cout << "\n\n" << "***ARRAY STACK***" << endl;
	auto *a_stack = new stack::ArrayStack<int>(15);
	for (unsigned int i = 0; i < 10; i++) {
		a_stack->push(i);
	}
	cout << a_stack->peek() << endl;
	a_stack->pop();
	a_stack->pop();
	a_stack->pop();
	cout << a_stack->peek() << endl;
	a_stack->print();
	delete a_stack;

}


void Tester::linkedQueue() {

	cout << "\n\n" << "***LINKED QUEUE***" << endl;
	auto *l_queue = new queue::LinkedQueue<int>();
	for (int i = 0; i < 10; i++) {
		l_queue->enqueue(i);
	}
	l_queue->print();
	cout << l_queue->peek() << endl;
	l_queue->dequeue();
	l_queue->dequeue();
	cout << l_queue->peek() << endl;
	l_queue->dequeue();
	l_queue->print();
	delete l_queue;

}


void Tester::arrayQueue() {

	cout << "\n\n" << "***ARRAY QUEUE***" << endl;
	auto *a_queue = new queue::ArrayQueue<int>(15);
	for (int i = 0; i < 10; i++) {
		a_queue->enqueue(i);
	}
	a_queue->print();
	cout << a_queue->peek() << endl;
	a_queue->dequeue();
	a_queue->dequeue();
	cout << a_queue->peek() << endl;
	a_queue->dequeue();
	a_queue->print();
	delete a_queue;

}


void Tester::linkedCircularQueue() {

	cout << "\n\n" << "***LINKED CIRCULAR QUEUE***" << endl;
	auto *l_cq = new queue::LinkedCircularQueue<int>();
	for (int i = 0; i < 10; ++i) {
		l_cq->enqueue(i);
	}
	l_cq->print();
	cout << l_cq->peek() << endl;
	l_cq->dequeue();
	l_cq->dequeue();
	l_cq->print();
	l_cq->dequeue();
	l_cq->print();
	delete l_cq;

}


void Tester::arrayCircularQueue() {

	cout << "\n\n" << "***ARRAY CIRCULAR QUEUE***" << endl;
	auto *a_cq = new queue::ArrayCircularQueue<int>(15);
	for (int i = 0; i < 10; ++i) {
		a_cq->enqueue(i);
	}
	a_cq->print();
	a_cq->dequeue();
	a_cq->dequeue();
	a_cq->print();
	a_cq->enqueue(11);
	a_cq->print();
	delete a_cq;

}


void Tester::linkedDeque() {

	cout << "\n\n" << "***LINKED DEQUE***" << endl;
	auto *l_dq = new queue::LinkedDeque<int>();
	for (int i = 0; i < 10; ++i) {
		l_dq->enqueueRear(i);
	}
	l_dq->print();
	l_dq->enqueueFront(11);
	l_dq->enqueueFront(22);
	l_dq->print();
	l_dq->dequeueEnd();
	l_dq->dequeueEnd();
	l_dq->print();
	l_dq->dequeueFront();
	l_dq->dequeueFront();
	l_dq->print();
	delete l_dq;

}


void Tester::arrayDeque() {

	cout << "\n\n" << "***ARRAY DEQUE***" << endl;
	auto *a_dq = new queue::ArrayDeque<int>(15);
	for (int i = 0; i < 10; ++i) {
		a_dq->enqueueRear(i);
	}
	a_dq->print();
	a_dq->dequeueFront();
	a_dq->dequeueFront();
	a_dq->print();
	a_dq->enqueueFront(11);
	a_dq->enqueueFront(22);
	a_dq->print();
	a_dq->dequeueRear();
	a_dq->dequeueFront();
	a_dq->print();
	delete a_dq;

}


void Tester::binaryTree() {

	cout << "\n\n" << "***BINARY TREE***" << endl;
	auto *n = new tree::Node<int>(1);
	n->setLeftChild(new tree::Node<int>(2));
	n->setRightChild(new tree::Node<int>(3));
	auto *bt = new tree::BinaryTree<int>(n);
	bt->getPrefix();
	bt->getInfix();
	bt->getPostfix();
	delete bt;

}


void Tester::binarySearchTree() {

	cout << "\n\n" << "***BINARY SEARCH TREE***" << endl;
	auto *bst = new tree::BinarySearchTree<int>();
	for (int i = 0; i < 10; ++i) {
		bst->insert(i);
	}
	bst->insert(-2);
	bst->insert(-10);
	bst->insert(100);
	bst->insert(50);
	bst->getPrefix();
	bst->getInfix();
	bst->getPostfix();
	delete bst;

}


void Tester::bubbleSort() {

	cout << "\n\n" << "***BUBBLE SORT***" << endl;
	cout << "Unsorted : ";
	int array[] = {
			23, 76, 12, 3, 4, 9, 0, 12, 43, 76
	};
	Utility::printArray(array, 10);
	algorithms::Sorting::bubbleSort(array, 10);
	cout << "Sorted : ";
	Utility::printArray(array, 10);

}


void Tester::selectionSort() {

	cout << "\n\n" << "***SELECTION SORT***" << endl;
	cout << "Unsorted : ";
	int array[] = {
			23, 76, 12, 3, 4, 9, 0, 12, 43, 76
	};
	Utility::printArray(array, 10);
	algorithms::Sorting::selectionSort(array, 10);
	cout << "Sorted : ";
	Utility::printArray(array, 10);

}


void Tester::insertionSort() {

	cout << "\n\n" << "***INSERTION SORT***" << endl;
	cout << "Unsorted : ";
	int array[] = {
			23, 76, 12, 3, 4, 9, 0, 12, 43, 76
	};
	Utility::printArray(array, 10);
	algorithms::Sorting::insertionSort(array, 10);
	cout << "Sorted : ";
	Utility::printArray(array, 10);

}


void Tester::mergeSort() {

	cout << "\n\n" << "***MERGE SORT***" << endl;
	cout << "Unsorted : ";
	int array[] = {
			23, 76, 12, 3, 4, 9, 0, 12, 43, 76
	};
	Utility::printArray(array, 10);
	algorithms::Sorting::mergeSort(array, 10);
	cout << "Sorted : ";
	Utility::printArray(array, 10);

}


void Tester::quickSort() {

	cout << "\n\n" << "***QUICK SORT***" << endl;
	cout << "Unsorted : ";
	int array[] = {
			23, 76, 12, 3, 4, 9, 0, 12, 43, 76
	};
	Utility::printArray(array, 10);
	algorithms::Sorting::quickSort(array, 10);
	cout << "Sorted : ";
	Utility::printArray(array, 10);

}


void Tester::radixSort() {

	cout << "\n\n" << "***QUICK SORT***" << endl;
	cout << "Unsorted : ";
	int array[] = {
			23, 76, 12, 3, 4, 9, 0, 12, 43, 76
	};
	Utility::printArray(array, 10);
	algorithms::Sorting::quickSort(array, 10);
	cout << "Sorted : ";
	Utility::printArray(array, 10);

}


void Tester::bucketSort() {

	cout << "\n\n" << "***BUCKET SORT***" << endl;
	cout << "Unsorted : ";
	int array[] = {
			23, 76, 12, 3, 4, 9, 0, 12, 43, 76
	};
	Utility::printArray(array, 10);
	algorithms::Sorting::quickSort(array, 10);
	cout << "Sorted : ";
	Utility::printArray(array, 10);

}


void Tester::linearSearch() {

	cout << "\n\n" << "***LINEAR SEARCH***" << endl;
	cout << "Array: ";
	int array[] = {
			23, 76, 12, 3, 4, 9, 0, 12, 43, 76
	};
	Utility::printArray(array, 10);
	cout << "\nElement 76's first instance at ... " << algorithms::Searching::linearSearch(array, 10, 76);
	cout << "\nElement 99 at ... " << algorithms::Searching::linearSearch(array, 10, 99);
	cout << endl;

}


void Tester::binarySearch() {

	cout << "\n\n" << "***BINARY SEARCH***" << endl;
	cout << "Unsorted Array: ";
	int array[] = {
			23, 76, 12, 3, 4, 9, 0, 12, 43, 76
	};
	Utility::printArray(array, 10);
	algorithms::Sorting::bubbleSort(array, 10);
	cout << "Sorted Array: ";
	Utility::printArray(array, 10);
	cout << "\nElement 76's first instance at ... " << algorithms::Searching::binarySearch(array, 10, 76);
	cout << "\nElement 99 at ... " << algorithms::Searching::binarySearch(array, 10, 99);
	cout << endl;

}