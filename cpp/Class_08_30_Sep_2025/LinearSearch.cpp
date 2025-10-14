#include <iostream>
using namespace std;

int main() {
	int arraysize, element, index;
	cout << "Enter Array Size: "; cin >> arraysize;
	int *array = new int[arraysize];
	cout << "Enter Array Elements:\n";
	for (int i = 0; i < arraysize; i++) cin >> array[i];
	cout << "Enter Element to Search: "; cin >> element;
	for (index = 0; index < arraysize; index++)
		if (array[index] == element) break;
	if (index < arraysize)
		cout << "Element found at index: " << index;
	else cout << "Element not found";
	cout << endl;
	return 0;
}
