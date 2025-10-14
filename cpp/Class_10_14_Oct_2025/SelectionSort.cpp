#include <iostream>
using namespace std;
void selection_sort(int *array, int size) {
	int min;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) min = (array[min] > array[j]) ? j : min;
		int tmp = array[min];
		array[min] = array[i];
		array[i] = tmp;
	}
}
int main() {
	int array_size;
	cout << "Enter Size of Array: "; cin >> array_size;
	int *array = new int[array_size];
	cout << "Enter Elements: ";
	for (int i = 0; i < array_size; i++) cin >> array[i];
	selection_sort(array, array_size);
	cout << "Sorted Array: ";
	for (int i = 0; i < array_size; i++) cout << array[i] << " ";
	cout << endl;
	return 0;
}
