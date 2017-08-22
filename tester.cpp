#include "tester.h"
#include "linked_lists/singly_linked_list.h"
#include "linked_lists/circular_singly_linked_list.h"
#include "linked_lists/doubly_linked_list.h"
#include "stack/linked_stack.h"
#include "stack/array_stack.h"
#include "queue/linked_queue.h"


void Tester::singlyLinkedList() {

	cout << "\n\n" << "***SINGLY LINKED LIST***" << endl;
	auto *list = new linked_list::SinglyLinkedList<int>();
	for (int i = 0; i < 9; ++i) {
		list->insertEnd(i);
	}
	list->insertFront(11);
	list->insertEnd(22);
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

	c_list->insertAt(44, 4);
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
	d_list->insertAt(33, 3);
	d_list->print();

	d_list->deleteFront();
	d_list->deleteEnd();
	d_list->deleteAt(3);
	d_list->print();

	delete d_list;

}


void Tester::circularDoublyLinkedList() {

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
		l_queue->insert(i);
	}
	l_queue->print();
	cout << l_queue->peek() << endl;
	l_queue->remove();
	l_queue->remove();
	cout << l_queue->peek() << endl;
	l_queue->remove();
	l_queue->print();
	delete l_queue;

}


void Tester::arrayQueue() {

}