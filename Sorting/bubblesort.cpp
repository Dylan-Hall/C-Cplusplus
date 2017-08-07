/*
 * bubblesort.cpp :: bubblesort.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 *
 *		  Time complexity:
 *		  	best case: O(n); already sorted
 *		  	worst case: O(n*n); not sorted
 */

// Standard Includes
#include <cstdlib>
#include <ctime>
#include <iostream>

// Prototypes
void print(int arr[], int size);
int rnd(int min, int max);
void swap(int* x, int* y);
void bubbleSort(int a[], int size);

int main(void) {

	int arr[25];
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; i++) {
		arr[i] = rnd(1, 50);
	}

	bubbleSort(arr, size);
	print(arr, size);

	return 0;
}

//bubbleSort; performs a bubble sort on a given array
void bubbleSort(int a[], int size) {
	bool passed;
	for (int i = 0; i < size - 1; i++) {
		passed = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j+1]) {
				swap(&a[j], &a[j+1]);
				passed = true;
			}
		}
		if(passed == true) {
			break;
		}
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

//swap; swaps two integers
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
} /* end */

