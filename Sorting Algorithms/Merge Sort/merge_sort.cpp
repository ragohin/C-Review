#include <iostream>
using namespace std;

/*
Merge Sort is a divide and conquer algorithm.
Merge sort divides the list into two halfs (starting with the left half) recursively until the list size is one.
The list then creates sublists of the same size by comparing first elements of each sublist and adding the smallest
one to a sublist. This continutes until one sublist is left, the final list.

https://www.geeksforgeeks.org/merge-sort/ this graphic demonstrates the order well.
Time Complexity: O(nlogn)
*/

void merge(int arr[], int left, int middle, int right) {
	int a_size = middle-left-1;
	int b_size = right-middle;
	int* a = new int[a_size]; //create temp arrays of the size of the two halfs
	int* b = new int[b_size];

	//read in left and right half into temp arrays
	for (int i = 0; i < a_size; ++i) {
		a[i] = arr[left + i];
	}
	for (int i = 0; i < b_size; ++i) {
		b[i] = arr[middle + i + 1];
	}

	//read these two halfs back into the main array
	int a_index = 0; //initial index of left half
	int b_index = 0; //initial index of right half
	int merge_index = left; //the merged list will begin at left half's first index

	while (a_index < a_size && b_index < b_size) {
		if (a[a_index] < b[b_index]) {
			arr[merge_index] = a[a_index];
			++a_index;
			++merge_index;
		}
		else {
			arr[merge_index] = b[b_index];
			++b_index;
			++merge_index;
		}
	}
	//finish reading in left half if right ends early
	while (a_index < a_size) {
		arr[merge_index] = a[a_index];
		++a_index;
		++merge_index;
	}
	//finish reading in right half if left ends early
	while (a_index < a_size) {
		arr[merge_index] = b[b_index];
		++b_index;
		++merge_index;
	}
	delete [] a;
	delete [] b;
}

void merge_sort(int arr[], int left, int right) {
	int middle = (left+right)/2;
	if (left < right) {
		merge_sort(arr, left, middle);
		merge_sort(arr, middle, right);
	}
	merge(arr, left, middle, right);
}






int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int arr_size = 5;
	merge_sort(arr, 0, arr_size-1);
	for (auto i: arr) {
		cout << i;
	}
	system("pause");
	return 0;
}