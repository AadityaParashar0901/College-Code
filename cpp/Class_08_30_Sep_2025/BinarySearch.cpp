#include <iostream>
using namespace std;

int main() {
	int arraySize, low = 0, element, mid;
	cout << "Enter Array Size: "; cin >> arraySize;
	int *array = new int[arraySize], high = arraySize - 1;
	cout << "Enter Elements:\n";
	for (int i = 0; i < arraySize; i++) cin >> array[i];
	cout << "Enter Element to Search: "; cin >> element;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (array[mid] == element) break;
		if (array[mid] < element) low = mid + 1;
		if (array[mid] > element) high = mid - 1;
	}
	if (low <= high) cout << "Element found at index: " << mid;
	else cout << "Element not found";
	cout << endl;
	return 0;
}
