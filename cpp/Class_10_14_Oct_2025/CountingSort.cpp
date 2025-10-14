#include <iostream>
using namespace std;
int *counting_sort(int *array, int size) {
	int i, min = array[0], max = array[0];
	for (i = 0; i < size; i++) {
		min = (min > array[i]) ? array[i] : min;
		max = (max < array[i]) ? array[i] : max;
	}
	int *countArray = new int[max - min + 1];
	for (i = 0; i <= max - min; i++)
		countArray[i] = 0;
	for (i = 0; i < size; i++)
		countArray[array[i] - min]++;
	for (i = 1; i <= max - min; i++)
		countArray[i] += countArray[i - 1];
	int *outputArray = new int[size];
	for (i = size - 1; i >= 0; i--)
		outputArray[--countArray[array[i] - min]] = array[i];
	return outputArray;
}
int main() {
	int array_size;
	cout << "Enter Size of Array: "; cin >> array_size;
	int *array = new int[array_size];
	cout << "Enter Elements: ";
	for (int i = 0; i < array_size; i++) cin >> array[i];
	array = counting_sort(array, array_size);
	cout << "Sorted Array: ";
	for (int i = 0; i < array_size; i++) cout << array[i] << " ";
	cout << endl;
	return 0;
}
