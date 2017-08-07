/*
 * main.c ::
 * 		-> circularilyLinkedList.c :: circularilyLinkedList.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 */

// Standard Includes
#include <stdio.h>

#include "circularilyLinkedList.h"

//main; program entry point
int main(void) {

	NodeT* head = NULL;

	addFirst(&head, 5);
	addFirst(&head, 5);
	addFirst(&head, 5);
	addFirst(&head, 5);
	addFirst(&head, 5);

	printf("%d", head->data);
	print(head);

	return 0;
} /* END MAIN */


