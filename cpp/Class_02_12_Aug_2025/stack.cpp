#include <iostream>
using namespace std;

#define MAX_STACK_SIZE 5

class Stack {
private:
	int stack[MAX_STACK_SIZE];
	int head;
public:
	Stack () { head = 0; }
	void push (int value) {
		if (head >= MAX_STACK_SIZE) {
			cout << "Overflow Error: Stack is full\n";
			return;
		}
		stack[head++] = value;
	}
	int pop () {
		if (head == 0) {
			cout << "Underflow Error: Stack is empty\n";
			return 0;
		}
		return stack[--head];
	}
	int top () {
		if (head == 0) {
			cout << "Underflow Error: Stack is empty\n";
			return 0;
		}
		return stack[head - 1];
	}
};

int main() {
	Stack stack;
	stack.push(5); stack.push(4); stack.push(3); stack.push(2); stack.push(1);
	stack.push(6);
	for (int i = 0; i < 5; i++) {
		cout << "Stack: " << stack.pop() << endl;
	}
	stack.pop();
	return 0;
}
