#include <iostream>
#include <cmath>
using namespace std;
class Stack {
private: int stack[256], stack_size;
public: Stack () { stack_size = 0; }
	void push(int v) { if (stack_size < 256) stack[stack_size++] = v; }
	int pop() { if (stack_size > 0) return stack[--stack_size]; }
	int peek() { if (stack_size > 0) return stack[stack_size - 1]; }
	int getSize() { return stack_size; }
	void traverse() { if (stack_size == 0) cout << "Empty";
		for (int i = 0; i < stack_size; i++)
			cout << stack[i] << ((i < stack_size - 1) ? "," : ""); }
};
bool isOperator (char o) { static int i;
	static char operators[] = "+-*/^";
	for (i = 0; operators[i] != 0; i++) if (operators[i] == o) return true;
	return false; }
bool isNumber (char o) { return (o >= 48 && o <= 57); }
int evaluate_postfix (char *expression) {
	Stack operands; char c, lastChar;
	for (int i = 0; c = expression[i]; i++) {
		cout << "Input Character: " << c << ". Operands: ";
		if (isOperator(c)) {
			int b = operands.pop(), a = operands.pop();
			switch (c) {
				case '+': operands.push(a + b); break;
				case '-': operands.push(a - b); break;
				case '*': operands.push(a * b); break;
				case '/': operands.push(a / b); break;
				case '^': operands.push(pow(a, b)); break;
			}
		} else if (isNumber(c)) {
			if (isNumber(lastChar)) operands.push(operands.pop() * 10 + c - 48);
			else operands.push(c - 48);
		}
		lastChar = c; operands.traverse(); cout << endl;
	}
	return operands.pop();
}
int main() { char input_expression[256]; int i;
	cout << "Enter a Postfix Expression: "; cin.getline(input_expression, 256);
	int answer = evaluate_postfix(input_expression);
	cout << "Answer: " << answer << endl;
	return 0;
}
