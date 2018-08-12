#include <iostream>
#include <array>
using namespace std;

/*
Bubble Sort is one of the least efficient sorting algorithms.
It compares the first two items in a lists and swaps them, if necessary. Then it continues with the next two
items until the end of the list.
The worst case is the list is in complete reverse order.

Time Complexity: O(n^2)

Useful: n is small, quick
*/

void bubble_sort(int* arr, int arr_size) {
	for (int i = 0; i < arr_size; ++i) { //the last item of the list is in the right place after every iteration of i
		for (int* begin = arr; begin < arr + (arr_size-i-1); ++begin) {
			if (*begin > *(begin+1)) {
				int temp = *begin;
				*begin = *(begin+1);
				*(begin+1) = temp;
			}
		}
	}
}

int main() {
	int arr[] = { 5, 4, 3, 2, 1 };
	int* ptr = arr;
	bubble_sort(ptr, 5);
	for (auto i: arr) {
		cout << i;
	}
	system("pause");
	return 0;
}