/*
 * quickSort.cpp :: quickSort.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 */

// Standard Includes
#include <ctime>
#include <cstdlib>
#include <iostream>

// Prototypes
void print(int arr[], int size);
int rnd(int min, int max);
void swap(int* x, int* y);
void quickSort(int a[], int low, int high);
int sortPivot(int a[], int low, int high);

//main; entry point for program
int main(void) {

	int arr[20];
	int size = sizeof(arr)/sizeof(arr[0]);

	for(int i = 0; i < size; i++) {
		arr[i] = rnd(1, 50);
	}

	quickSort(arr, 0, size-1);
	print(arr, size);

	return 0;
} /* END MAIN */

//quickSort; performs recursive quick sort on a given array
void quickSort(int a[], int low, int high) {
	if (low < high) {
		int pivot = sortPivot(a, low, high);
		quickSort(a, low, pivot - 1);
		quickSort(a, pivot + 1, high);
	}
} /* end */

//sortPivot; finds the pivot to use, then sorts the surrounding elements relative to the pivot
int sortPivot(int a[], int low, int high) {

	int pivot = a[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (a[j] <= pivot) {
			i++;
			swap(&a[i], &a[j]);
		}
	}

	swap(&a[i + 1], &a[high]);
	return (i + 1);
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

