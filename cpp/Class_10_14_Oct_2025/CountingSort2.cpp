#include <iostream>
using namespace std;
void counting_sort(int *array, int size) {
	int i, j, k = 0, min = array[0], max = array[0];
	for (i = 0; i < size; i++) {
		min = (min > array[i]) ? array[i] : min;
		max = (max < array[i]) ? array[i] : max;
	}
	int *countArray = new int[max - min + 1];
	for (i = 0; i <= max - min; i++)
		countArray[i] = 0;
	for (i = 0; i < size; i++)
		countArray[array[i] - min]++;
	for (i = 0; i <= max - min; i++)
		for (j = 0; j < countArray[i]; j++)
			array[k++] = i + min;
}
int main() {
	int array_size;
	cout << "Enter Size of Array: "; cin >> array_size;
	int *array = new int[array_size];
	cout << "Enter Elements: ";
	for (int i = 0; i < array_size; i++) cin >> array[i];
	counting_sort(array, array_size);
	cout << "Sorted Array: ";
	for (int i = 0; i < array_size; i++) cout << array[i] << " ";
	cout << endl;
	return 0;
}
