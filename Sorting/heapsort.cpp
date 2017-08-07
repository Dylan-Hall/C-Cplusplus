/*
 * heapSort.cpp :: heapSort.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 *
 *		  I considered putting this into the DSA folder, because I learned about heaps and heap sorting
 *		  in that class. But, its still a form of sorting so I decided to just keep to my orional layout
 *		  scheme.
 */

// Standard Includes
#include <ctime>
#include <cstdlib>
#include <iostream>

// Prototypes
void print(int arr[], int size);
int rnd(int min, int max);
void heapify(int a[], int size, int i);
void swap(int* x, int* y);
void heapSort(int arr[], int size);

//main; entry point for the program
int main(void) {

	int arr[25];
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; i++) {
		arr[i] = rnd(1, 50);
	}

	heapSort(arr, size);
	print(arr, size);

	return 0;
} /* END MAIN */

//heapify; heapify an array or a tree
void heapify(int a[], int size, int i) {

	// Relative tree locations of indexes
	int largest = i; //root
	int lhs = 2 * i + 1; //left index
	int rhs = 2 * i + 2; //right index

	if (lhs < size && a[lhs] > a[largest])
		largest = lhs;

	if (rhs < size && a[rhs] > a[largest])
		largest = rhs;

	if (largest != i) {
		swap(&a[i], &a[largest]);
		heapify(a, size, largest);
	}
} /* end */

//heapSort; performs a heap sort on a given array
void heapSort(int arr[], int size) {

	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}

	for (int i = size - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
} /* end */

//swap; swaps two integers
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
} /* end */

//print; prints the array
void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
} /* end */

//random; pseudo random uniform distributed number generator
int rnd(int min, int max) {
	static bool first = true;
	if (first) {
		srand(time(NULL));
		first = false;
	}
	return min + rand() % (max - min);
} /* end */

