#include <iostream>
using namespace std;
void insertion_sort(int *array, int size) {
	for (int i = 1; i < size; i++) {
		int j, k = array[i];
		for (j = i - 1; j >= 0; j--) {
			if (array[j] > k) array[j + 1] = array[j];
			else break;
		}
		array[++j] = k;
	}
}
int main() {
	int array_size;
	cout << "Enter Size of Array: "; cin >> array_size;
	int *array = new int[array_size];
	cout << "Enter Elements: ";
	for (int i = 0; i < array_size; i++) cin >> array[i];
	insertion_sort(array, array_size);
	cout << "Sorted Array: ";
	for (int i = 0; i < array_size; i++) cout << array[i] << " ";
	cout << endl;
	return 0;
}
