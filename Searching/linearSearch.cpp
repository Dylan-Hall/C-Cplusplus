/*
 * linearSearch.cpp :: linearSearch.h
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
int linearSearch(int a[], int size, int chk);

//main; entry point for the program
int main(void) {

	int arr[20];
	int size = sizeof(arr) / sizeof(arr[0]);
	int srch = rnd(5, 20);

	for (int i = 0; i < size; i++) {
		arr[i] = rnd(1, 20);
	}

	print(arr, size);
	std::cout << "\nSearch key: " << srch;
	int result = linearSearch(arr, size, srch);
	(result == -1) ?
			std::cout << "\nSearch key not found." :
			std::cout << "\nSearch key found at index: " << result;

	return 0;
} /* END MAIN */

//linearSearch; performs a linear search for a search key in a given array
int linearSearch(int a[], int size, int chk) {
	for (int i = 0; i < size; i++) {
		if (a[i] == chk) {
			return i;
		}
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

