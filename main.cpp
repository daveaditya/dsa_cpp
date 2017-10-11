#include "tester.h"

int main() {

	// Linear Data Structures
	Tester::singlyLinkedList();
	Tester::circularLinkedList();
	Tester::doublyLinkedList();
	Tester::circularDoublyLinkedList();

	Tester::linkedStack();
	Tester::arrayStack();
	Tester::linkedQueue();
	Tester::arrayQueue();
	Tester::linkedCircularQueue();
	Tester::arrayCircularQueue();
	Tester::linkedDeque();
	Tester::arrayDeque();


	// Non Linear Data Structures
	Tester::binaryTree();
	Tester::binarySearchTree();


	// Sorting Algorithms
	Tester::bubbleSort();
	Tester::selectionSort();
	Tester::insertionSort();
	Tester::mergeSort();
	Tester::quickSort();
	Tester::radixSort();
	Tester::bucketSort();


	// Searching Algorithms
	Tester::linearSearch();
	Tester::binarySearch();

	return 0;

}