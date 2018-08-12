#include <iostream>
using namespace std;

/*
Quick sort is also a divide and conquer algorith like merge sort.
Quick sort is generally better than merge short.
A pivot element is selected (either first element, last element or random element). The list is sorted
so that everything to the left of the pivot is less than the pivot (not necessarily in ascending order)
and everything to the right of the pivot is greater. Thus, the pivot is in the correct place. 
Then the same is done with the two sublists (left and right) created by the pivot until the list is sorted. 

Time Complexity: O(nlogn)

Comparison with merge sort:
	w/Arrays:
	- merge sort requires O(n) space that quick sort does not require as the array is sorted inside itself.
	- quick sort is also tail recursive

	w/Linked Lists:
	- in linked lists, items can be inserted in O(1) space and O(1) time, merge sort does not require extra space
	- random access (for example, accessing arr[c+i*4] where c is where some address of arr[c] is sorted) 
		is not allowed with linked lists as it is in arrays because the memory is not continuously stored
	- quick sort requires random access, which is costly compared to merge sort, which accessed memory sequentially

https://www.youtube.com/watch?v=MZaf_9IZCrc algorithm works according to this video (i and j are switched)
*/

//1. puts elements less than the pivot to the left of the pivot and elements greater to the right (not necessarily sorted)
//2. puts the pivot in the correct spot
//3. returns the index of the partition chich will now be in the correct spot
int partition(int arr[], int low, int high) {
	int j = low-1; //one below first element in list
	for (int i = low; i < high; ++i) {
		if (arr[i] < arr[high]) { // swap i and j+1
			++j;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	//swap j+1 with the pivot, so the pivot is in the correct spot
	int temp = arr[high];
	arr[high] = arr[j + 1];
	arr[j + 1] = temp;
	return j + 1;
}

//this creates a pivot at the last element
void quick_sort(int arr[], int low, int high) {
	if (low < high) { //there is still elements to sort
		int current_index = partition(arr, low, high); //returns index of the partition, which is now in the correct spot
		quick_sort(arr, low, current_index-1); //quick_sort on elements left of the partition
		quick_sort(arr, current_index+1, high); ///quick_sort on elements right of the partition
	}
}

int main() {
	int arr[] = { 5, 4, 3, 2, 1 };
	quick_sort(arr, 0, 4);
	for (auto i: arr) {
		cout << " " << i << " ";
	}
	system("pause");
	return 0;
}