#include <iostream>
using namespace std;

void bubbleSort(int *array, int size) {
	int i, j, s, t;
	for (i = 1; i <= size; i++) {
		s = 0;
		for (j = 0; j < size - i; j++) {
			if (array[j] > array[j + 1]) {
				t = array[j + 1];
				array[j + 1] = array[j];
				array[j] = t;
				s++;
			}
		}
		if (s == 0) break;
	}
}
int main() {
	int *array, size, i;
	cout << "Enter Array Size: "; cin >> size;
	array = new int[size];
	cout << "Enter Elements:";
	for (i = 0; i < size; i++) cin >> array[i];
	bubbleSort(array, size);
	cout << "Sorted Array: ";
	for (i = 0; i < size; i++) cout << array[i] << " ";
	cout << endl;
	return 0;
}
