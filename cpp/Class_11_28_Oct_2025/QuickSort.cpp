#include <iostream>
using namespace std;
void quick_sort(int *array, int low, int high) {
	if (low >= high) return;
	int mid = low + (high - low) / 2;
	int *left = new int[high - low + 1], l_i = 0;
	int *right = new int[high - low + 1], r_i = 0;
	for (int i = low; i <= high; i++) { // partition
		if (i == mid) continue;
		if (array[i] <= array[mid]) left[l_i++] = array[i];
		else right[r_i++] = array[i];
	}
	int i = low, mid_element = array[mid];
	for (int j = 0; j < l_i; j++) array[i++] = left[j];
	mid = i;
	array[i++] = mid_element;
	for (int j = 0; j < r_i; j++) array[i++] = right[j];
	delete [] left;
	delete [] right;
	quick_sort(array, low, mid - 1);
	quick_sort(array, mid + 1, high);
}
int main() {
	int array_size;
	cout << "Enter Size of Array: "; cin >> array_size;
	int *array = new int[array_size];
	cout << "Enter Elements: ";
	for (int i = 0; i < array_size; i++) cin >> array[i];
	quick_sort(array, 0, array_size - 1);
	cout << "Sorted Array: ";
	for (int i = 0; i < array_size; i++) cout << array[i] << " ";
	cout << endl;
	return 0;
}
