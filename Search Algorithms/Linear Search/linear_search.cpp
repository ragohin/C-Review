#include <iostream>
using namespace std;

/*
Linear search is the most basic of searching algorithms.

It searches every element in an array until the correct one is found.
Does not require array to be sorted.
Best for small arrays as it is the simplest to implement.

Worst Case Time Complexity: O(n)
*/

int linearSearch(int arr[], int array_size, int searchValue) {
	for (int i = 0; i < array_size; ++i) {
		if (arr[i] == searchValue) {
			return i;
		}
	}
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int array_size = 5;
	cout << linearSearch(arr, array_size, 4);
	system("pause");
	return 0;
}