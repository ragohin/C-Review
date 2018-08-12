#include <iostream>
using namespace std;

/*
Insertion sort generally runs a little fast than bubble sort even though they have the same worst case
complexity (insertion has a better average case complexity).
In insertion, start with the second element, compare it to the first and swap them is the second is smaller.
Move on to the next element, compare it to the previous and so forth until an element to the left is smaller.
Insertion inserts an element to the correct place to the left in a list.

Time Complexity: O(n)

Useful: n is small, quick operation
*/

void insertion_sort(int* arr, int arr_size) {
	for (int* element = arr+1; element < arr + arr_size; ++element) { //start with second element, move right
		int element_value = *element;
		int* element_copy = element;
		while (element_copy != arr && element_value < *(element_copy-1)) { //while an element is smaller than one of the left, move it left
			*element_copy = *(element_copy -1);
			*(element_copy-1) = element_value;
			--element_copy;
		}
	}
}

int main() {
	int arr[] = { 5, 4, 3, 2, 1 };
	insertion_sort(arr, 5);
	for (auto i: arr) {
		cout << i;
	}
	system("pause");
	return 0;
}