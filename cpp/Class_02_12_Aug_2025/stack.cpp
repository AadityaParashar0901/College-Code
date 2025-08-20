#include <iostream>
using namespace std;
#define MAX_STACK_SIZE 3
class Stack {
private: int stack[MAX_STACK_SIZE], head;
public: Stack () { head = 0; }
	void info () {
		if (head == 0) cout << "Stack is empty.\n";
		else if (head >= MAX_STACK_SIZE) cout << "Stack is full.\n";
		else cout << "Stack has " << head << " elements.\n";
		return; }
	void push (int value) {
		if (head >= MAX_STACK_SIZE) {
			cout << "Overflow Error: Stack is full\n";
			return; }
		stack[head++] = value; return; }
	int pop () {
		if (head == 0) {
			cout << "Underflow Error: Stack is empty\n";
			return 0; }
		return stack[--head]; }
	void traverse () {
		if (head == 0) {
			cout << "Underflow Error: Stack is empty\n";
			return; }
		cout << "Stack (Size = " << head << "): ";
		for (int i = 0; i < head; i++) cout << stack[i] << " ";
		cout << endl; return; }
	int peek () {
		if (head == 0) {
			cout << "Underflow Error: Stack is empty\n";
			return 0; }
		return stack[head - 1]; }
};

int main() { Stack stack; int choice, value;
	while (1) { stack.info();
		cout << "1. Push\n2. Pop\n3. Traverse\n4. Peek\n";
		cout << "Other. Exit\nEnter your Choice: ";
		cin >> choice; switch (choice) {
			case 1: cout << "Enter a Value: "; cin >> value;
				stack.push(value); break;
			case 2: value = stack.pop();
				cout << "Popped Value is: " << value << endl; break;
			case 3: stack.traverse(); break;
			case 4: value = stack.peek();
				cout << "Peeked Value is: " << value << endl;
				break;
			default: return 0; }
	}
	return 0; }
