/*
 * mergesort.cpp :: mergesort.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 3, 2017
 *		  Lang: C/C++
 *
 *	Merge sort source code, simple and straight forward
 */

// Standard Includes
#include <cstdlib>
#include <ctime>
#include <iostream>

// Prototypes
void print(int arr[], int s);
void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);
int rnd(int min, int max);

#define inc(i, j) ((i++),(j++));

//main; defined entry point
int main(void) {

	// Seeding pseudo-random number generated to NULL
	srand(time(NULL));

	// Declare the array of size ten, and create a quick-use variable for its size
	int arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);

	// Randomly generate values for this array.
	for (int i = 0; i < size; i++) {
		arr[i] = rnd(1, 50);
	}

	std::cout << "Init array: ";
	print(arr, size);

	mergeSort(arr, 0, size - 1);

	std::cout << "\nSorted array: ";
	print(arr, size);

	return EXIT_SUCCESS;
} /* END MAIN */

//merge; merge sub-arrays
void merge(int arr[], int l, int m, int r) {

	// Variables
	int i = 0, j = 0, k = 0;
	int lsize = m - l + 1;
	int rsize = r - m;

	// Sub-arrays
	int larr[lsize], rarr[rsize];

	/* Fill sub-arrays */
	for (int it = 0; it < lsize; it++) {
		larr[it] = arr[l + it];
	}
	for (int it = 0; it < rsize; it++) {
		rarr[it] = arr[m + 1 + it];
	}

	k = l;

	/* Sort the new array */
	while (i < lsize && j < rsize) {
		if (larr[i] <= rarr[j]) {
			arr[k] = larr[i];
			inc(i, k);
		} else {
			arr[k] = rarr[j];
			inc(j, k);
		}
	}

	/* Handle left-overs from sub-arrays */
	while (i < lsize) {
		arr[k] = larr[i];
		inc(i, k);
	}

	while (j < rsize) {
		arr[k] = rarr[j];
		inc(j, k);
	}
} /* end */

//mergeSort; merge sort recursive function to create sub-arrays and merge them into a new sorted array
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
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
