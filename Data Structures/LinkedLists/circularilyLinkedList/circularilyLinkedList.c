/*
 * circularilyLinkedList.c :: circularilyLinkedList.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 */

// Corresponding Headers
#include "circularilyLinkedList.h"

// Standard Includes
#include <stdlib.h>
#include <stdio.h>

//newNode; allocates and creates a new node
NodeT* newNode(int data) {
	NodeT* node = malloc(sizeof(NodeT));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
} /* end */

//addFirst; adds a node to the front of the list
void addFirst(NodeT** head, int data) {
	NodeT* node = newNode(data);

	if ((*head) == NULL) {
		*head = node;
		return;
	}

	NodeT* tail = getTail(*head);

	(*head)->prev = node;
	node->next = *head;
	*head = node;
	(*head)->prev = tail;
} /* end */

//addLast; adds a node at the end of the linked list
void addLast(NodeT** head, int data) {
	NodeT* node = newNode(data);
	NodeT* current = *head;

	if (!(*head)) {
		*head = node;
		return;
	}

	while (current->next) {
		current = current->next;
	}
	current->next = node;
	node->prev = current;
	node->next = *head;
} /* end */

//addBefore; adds a node before a given node
void addAfter(NodeT* prev, int data) {
	if (!prev) {
		printf("Error:: previous node is NULL.\n\n");
		return;
	}

	NodeT* node = newNode(data);
	node->next = prev->next;
	prev->next = node;

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

//print; prints the list
void print(NodeT* current) {
	printf("The list: ");
	while (current) {
		printf("%d ", current->data);
		current = current->next;
	}
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

//getTail; returns the tail of a linked list
NodeT* getTail(NodeT* head) {
	NodeT* curr = head;
	while (curr) {
		curr = curr->next;
	}
	return curr;
} /* end */

