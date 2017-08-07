/*
 * main.c ::
 * 		-> doublyLinkedList.c :: doublyLinkedList.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 */

// Corresponding Headers
#include "doublyLinkedList.h"

// Standard Includes
#include <stdlib.h>
#include <stdio.h>

//main; program entry point
int main(void) {

	NodeT* head = NULL;
	addLast(&head, 3);
	addFirst(&head, 5);
	addFirst(&head, 10);
	addLast(&head, 7);
	addAfter(head->next->next, 25);

	print(head);
	free(head);
	return 0;
} /* END MAIN */

