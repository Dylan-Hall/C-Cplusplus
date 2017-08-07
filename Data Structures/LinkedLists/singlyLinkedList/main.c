/*
 * main.c :: ->
 * 			singlyLinkedList.c :: singlyLinkedList.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 */

// Standard Includes
#include <stdio.h>

// Corresponding Headers
#include "singlyLinkedList.h"

int main(void) {

	NodeT* head = NULL;

	addLast(&head, 4);
	addLast(&head, 4);
	addFirst(&head, 7);
	addLast(&head, 6);
	addFirst(&head, 1);
	addAfter(head->next, 8);

	printf("Head Data: %d\n", head->data);
	printf("List is: ");
	print(head);

	return 0;
} /* END MAIN */

