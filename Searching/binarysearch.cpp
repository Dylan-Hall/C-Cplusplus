/*
 * binarySort.cpp :: binarySort.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 *
 *		  Time Complexity:
 *		  best case: O(log(n))
 */

// Standard Includes
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iostream>

// Prototypes
int binarySearch(int arr[], int l, int r, int x);
void print(int arr[], int size);
int rnd(int min, int max);
void swap(int* x, int* y);

//main; entry point of the program
int main(void) {

	int arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);
	int srch = rnd(1, 10);

	for (int i = 0; i < size; i++) {
		arr[i] = rnd(1, 15);
	}

	print(arr, size);
	std::cout << "\n" << "Search key: " << srch << std::endl;

	int chk = binarySearch(arr, 0, size - 1, srch);
	(chk == -1) ?
			printf("Element is not present in array") :
			printf("Element is present at index %d", chk);

	return 0;
} /* END MAIN */

//binarySearch; performs a binary search on an array for a search key
int binarySearch(int arr[], int lhs, int rhs, int srch) {
	if (rhs >= lhs) {
		int mid = lhs + (rhs - lhs) / 2;

		if (arr[mid] == srch)
			return mid;

		if (arr[mid] > srch)
			return binarySearch(arr, lhs, mid - 1, srch);

		return binarySearch(arr, mid + 1, rhs, srch);
	}

	return -1;
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

