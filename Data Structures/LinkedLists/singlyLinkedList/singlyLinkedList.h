/*
 * singlyLinkedList.h :: singlyLinkedList.c
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

typedef struct NodeStruct {
	struct NodeStruct* next;
	int data;
} NodeT;

NodeT* newNode(int data);
void addFirst(NodeT** head, int data);
void addLast(NodeT** head, int data);
void addAfter(NodeT* prev, int data);
void print(NodeT* head);
int length(NodeT* head);
int isEmpty(NodeT* head);
void freeList(NodeT* head);

#endif /* SINGLYLINKEDLIST_H_ */
