/*
 * doublyLinkedList.h :: doublyLinkedList.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

typedef struct DoublyLinkedList {
	struct DoublyLinkedList* next;
	struct DoublyLinkedList* prev;
	int data;
} NodeT;

/**
 * newNode function
 *
 * @param:
 * 	int data; the data for the new node
 *
 * 	#returns the new node
 */
NodeT* newNode(int data);

/**
 * The next three functions are used for insertion into a doubly linked list
 *
 * @params:
 * 	NodeT** head; a reference to the head of the list
 * 	int data; the data being put into the list
 * 	NodeT* prev; the node to place the new node after
 *
 *	-functions-
 * 	addFirst; adds a node to the from of the list
 * 	addLast; adds a node to the end of the list
 * 	addAfter; adds a node after a given node
 */
void addFirst(NodeT** head, int data);
void addLast(NodeT** head, int data);
void addAfter(NodeT* prev, int data);

/**
 * The next three functions are used for pure utility
 *
 * @params:
 * 	NodeT* head; pointer to the head node in the list
 *
 *	-functions-
 * 	print; prints the list
 * 	length; returns the length of the list
 * 	isEmpty; determines if the list is empty
 */
void print(NodeT* head);
int length(NodeT* head);
int isEmpty(NodeT* head);

#endif /* DOUBLYLINKEDLIST_H_ */
