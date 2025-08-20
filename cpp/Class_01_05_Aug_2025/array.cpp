#include <iostream>
using namespace std;

#define ARRAY_MAX_SIZE 1024 // maximum array size

// error messages
char *errorMessage;
char outOfBoundError[] = "Position out of bound";
char emptyArray[] = "Array is empty";
char fullArray[] = "Array is full";

class Array {
private:
	int array[ARRAY_MAX_SIZE], current_size;
public:
	Array () {
		current_size = 0;
		for (int i = 0; i < ARRAY_MAX_SIZE; i++) array[i] = 0; }
	int getSize() { return current_size; }
	void fill(int size, int value) {
		for (int i = 0; i < size && current_size < ARRAY_MAX_SIZE; i++) {
			array[current_size++] = value;
			if (current_size >= ARRAY_MAX_SIZE) errorMessage = fullArray; }
		cout << "Filled Array with Value: " << value << endl; }
	void display() {
		if (current_size == 0) { errorMessage = emptyArray; return; }
		if (current_size == ARRAY_MAX_SIZE) errorMessage = fullArray;
		cout << "Array (Size = " << current_size << "): [";
		for (int i = 0; i < current_size; i++) {
			cout << array[i];
			if (i < current_size - 1) cout << ", "; }
		cout << "]\n"; }
	void insert(int position, int value) {
		if (position < 0 || position > current_size) { errorMessage = outOfBoundError; return; }
		if (current_size >= ARRAY_MAX_SIZE) { errorMessage = fullArray; return; }
		for (int i = current_size; i > position; i--) array[i] = array[i - 1];
		array[position] = value; current_size++;
		cout << "Value: " << value << " inserted at Position: " << position << endl; }
	void remove(int position) {
		if (position < 0 || position >= current_size) { errorMessage = outOfBoundError; return; }
		for (int i = position; i < current_size; i++) array[i] = array[i + 1];
		array[current_size--] = 0;
		cout << "Removed element from Position: " << position << endl; }
	void clear() {
		for (int i = 0; i < current_size; i++) array[i] = 0;
		current_size = 0;
		cout << "Array cleared\n"; }
};

int main() {
	class Array array;
	int choice = 0, position = 0, value = 0, size = 0;
	while (1) {
		errorMessage = NULL;
		cout << "The array has " << array.getSize() << " elements.\n";
		cout << "Select your choice:\n";
		cout << "1. Fill Array\n";
		cout << "2. Display Array\n";
		cout << "3. Insert Element\n";
		cout << "4. Delete Element\n";
		cout << "5. Clear Array\n";
		cout << "Other. Exit\n";
		cin >> choice;
		switch (choice) {
			case 1: cout << "Enter Size, Value: "; cin >> size >> value;
				array.fill(size, value); break;
			case 2: array.display(); break;
			case 3: cout << "Enter Position, Value: "; cin >> position >> value;
				array.insert(position, value); break;
			case 4: cout << "Enter Position: "; cin >> position;
				array.remove(position); break;
			case 5: array.clear(); break;
			default: return 0; }
		if (errorMessage) cout << errorMessage << endl;
		cout << "\n\n"; }
	return 0; }
