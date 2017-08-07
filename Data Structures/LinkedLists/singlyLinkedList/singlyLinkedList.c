/*
 * singlyLinkedList.c :: singlyLinkedList.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 */

// Standard Includes
#include "singlyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

//newNode; allocates and creates a new node
NodeT* newNode(int data) {
	NodeT* node = (NodeT*) malloc(sizeof(NodeT));
	node->data = data;
	node->next = NULL;
	return node;
} /* end */

//addFirst; adds a node at the front of the list
void addFirst(NodeT** head, int data) {
	NodeT* node = newNode(data);
	node->next = *head;
	*head = node;
} /* end */

//addLast; adds a node at the end of the linked list
void addLast(NodeT** head, int data) {
	NodeT* node = newNode(data);
	NodeT* current = *head;

	if(!*head) {
		*head = node;
		return;
	}

	while(current->next) {
		current = current->next;
	}
	current->next = node;
} /* end */

//addBefore; adds a node before a given node
void addAfter(NodeT* prev, int data) {
	if(!prev) {
		printf("Error:: previous node is NULL.\n\n");
		return;
	}

	NodeT* node = newNode(data);
	node->next = prev->next;
	prev->next = node;

} /* end */

//print; prints the linked list
void print(NodeT* head) {
	while(head) {
		printf("%d ", head->data);
		head = head->next;
	}
} /* end */

//length; determine the length of the list
int length(NodeT* head) {
	int length = 0;
	while (head) {
		head = head->next;
		length++;
	}
	return length;
} /* end */

//isEmpty; checks to see if the list is empty
int isEmpty(NodeT* head) {
	if (!head) {
		return -1;
	}
	return 1;
} /* end */

//freeList; deallocates memory for the list
void freeList(NodeT* head) {
	NodeT* tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
} /* end */
