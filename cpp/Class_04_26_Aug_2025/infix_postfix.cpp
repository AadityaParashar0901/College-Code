#include <iostream>
using namespace std;

bool isOpeningParenthesis (char o) {
	return (o == '(' || o == '[' || o == '{');
}

bool isClosingParenthesis (char o) {
	return (o == ')' || o == ']' || o == '}');
}

bool isOperator (char o) {
	switch (o) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case '[':
		case '{':
		case ')':
		case ']':
		case '}': return true;
	}
	return false;
}

int precedence (char o, bool isFirst) {
	switch (o) {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		case '(':
		case '[':
		case '{': return (isFirst == true) ? 4 : 0;
	}
	return 0;
}

int main () {
	char input_expression[256], output_expression[256], stack[256];
	int stack_size = 0, o = 0;
	cout << "Enter Input Infix Expression: "; cin >> input_expression;
	for (int i = 0; input_expression[i] != 0; i++) {
		if (isOperator(input_expression[i])) {
			if (isClosingParenthesis(input_expression[i])) {
				while (stack_size) {
					if (isOpeningParenthesis(stack[--stack_size])) break;
					output_expression[o++] = stack[stack_size];
				}
			} else if (precedence(input_expression[i], true) <= precedence(stack[stack_size - 1], false)) {
				while (stack_size) {
					if (isOpeningParenthesis(stack[stack_size - 1]) || precedence(input_expression[i], true) > precedence(stack[stack_size - 1], false)) break;
					output_expression[o++] = stack[--stack_size];
				}
				stack[stack_size++] = input_expression[i];
			} else {
				stack[stack_size++] = input_expression[i];
			}
		} else {
			output_expression[o++] = input_expression[i];
		}
		stack[stack_size] = 0; output_expression[o] = 0; cout << input_expression[i] << " | " << stack << " | " << output_expression << endl;
	}
	while (stack_size) output_expression[o++] = stack[--stack_size]; output_expression[o] = 0;
	cout << "Postfix Expression: " << output_expression << endl;
	return 0;
}
