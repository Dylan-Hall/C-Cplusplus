/*
 * insertionsort.cpp :: insertionsort.h
 *
 *		  Author: Dylan Hall
 *  	  Date: Aug 6, 2017
 *		  Lang: C/C++
 *
 *		  Time Complexity : O(n*n)
 */

// Standard Includes
#include <cstdlib>
#include <ctime>
#include <iostream>

// Prototypes
void insertionSort(int a[], int size);
void print(int arr[], int size);
int rnd(int min, int max);

//main; program entry point
int main(void) {

	int arr[25];
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; i++) {
		arr[i] = rnd(1, 50);
	}

	insertionSort(arr, size);
	print(arr, size);

	return 0;
} /* END MAIN */

void insertionSort(int a[], int size) {
	int i, j, k;

	for (int i = 1; i < size; i++) {
		k = a[i];
		while (j >= 0 && a[j] > k) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
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
