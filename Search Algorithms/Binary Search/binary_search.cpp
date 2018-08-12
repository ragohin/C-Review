#include <iostream>
using namespace std;

/*
Binary search is generally better than linear, especially for large sorted databases.
List MUST be sorted.

Binary search checks the middle element to see if it is the element being seached for. If it is, were done.
If it is not, it checks if it is larger or smaller than the one we are searching for and then splits the list
in half accordingly. It continues until the element is found or the list cannot be split.

Time Complexity: O(logn)
*/

//Here is a non recursive version
int binary_search(int arr[], int arr_size, int element) {
	int high = arr_size - 1;
	int low = 0;
	while (high>=low) {
		int current_index = (high+low)/2;
		if (arr[current_index] == element) {
			return current_index;
		}
		else if (arr[current_index] > element) {
			high = current_index-1;
		}
		else {
			low = current_index +1;
		}
	}
	return -1;
}

//Here is a recursive version
int binary_search_rec(int arr[], int low, int arr_size, int element) {
	if (arr_size > low) {
		int current_element = (low + arr_size)/2;
		if (arr[current_element] == element) {
			return current_element;
		}
		else if (arr[current_element] > element) {
			return binary_search_rec(arr, low, current_element-1, element);
		}
		return binary_search_rec(arr, current_element+1, arr_size, element);
	}
	return -1;
}


int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	cout << binary_search(arr, 5, 3);
	cout << binary_search(arr, 5, 5);
	cout << binary_search(arr, 5, 6);
	cout << binary_search_rec(arr, 0, 5, 3);
	cout << binary_search_rec(arr, 0, 5, 5);
	cout << binary_search_rec(arr, 0, 5, 6);
	system("pause");
	return 0;
}