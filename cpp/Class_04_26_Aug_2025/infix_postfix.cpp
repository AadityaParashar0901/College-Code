#include <iostream>
using namespace std;
class StackChar {
private: char stack[256]; int stack_size;
public:	StackChar() { stack_size = 0; }
	void push(char c) { if (stack_size < 256) stack[stack_size++] = c; }
	char pop() { if (stack_size > 0) return stack[--stack_size]; else return 0; }
	char peek() { if (stack_size > 0) return stack[stack_size - 1]; else return 0; }
	int getSize() { return stack_size; }
	void traverse() { static int i; for (i = 0; i < stack_size; i++) cout << stack[i] << ((i < stack_size - 1) ? " " : ""); }
};
bool isOpeningParenthesis (char o) { return (o == '(' || o == '[' || o == '{'); }
bool isClosingParenthesis (char o) { return (o == ')' || o == ']' || o == '}'); }
char getClosingParenthesis (char o) { switch (o) {
		case '(': return ')';
		case '[': return ']';
		case '{': return '}';
	}
	return 0; }
int precedence (char o, bool isRightAssociative) { switch (o) {
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		case '^': return 3 + isRightAssociative;
		case '(': case '[': case '{': return (isRightAssociative == true) ? 4 : 0;
		case ')': case ']': case '}': return -1;
	}
	return 0; }
bool isOperator (char o) { return precedence(o, true); }
int main () { StackChar stack, parenthesis;
	char input_expression[256], output_expression[256], c; int output_index = 0;
	cout << "Enter Input Infix Expression: "; cin >> input_expression;
	for (int i = 0; c = input_expression[i]; i++) {
		if (isOperator(c)) {
			if (isClosingParenthesis(c)) {
				if (parenthesis.pop() != c) { cout << "Invalid Expression at Position " << i + 1 << endl; return 0; }
				while (stack.getSize()) {
					if (isOpeningParenthesis(stack.peek())) break;
					output_expression[output_index++] = stack.pop(); }
				stack.pop(); }
			else if (precedence(c, true) <= precedence(stack.peek(), false)) {
				while (stack.getSize()) {
					if (isOpeningParenthesis(stack.peek()) || precedence(c, true) > precedence(stack.peek(), false)) break;
					output_expression[output_index++] = stack.pop(); }
				stack.push(c); }
			else stack.push(c); }
		else output_expression[output_index++] = input_expression[i];
		if (isOpeningParenthesis(c)) parenthesis.push(getClosingParenthesis(c));
		output_expression[output_index] = 0;
		cout << input_expression[i] << " | "; stack.traverse();
		cout << " | " << output_expression << endl; }
	while (stack.getSize()) {
		if (isOpeningParenthesis(stack.peek())) { cout << "Missing Parenthesis\n"; return 0; }
		output_expression[output_index++] = stack.pop(); }
	output_expression[output_index] = 0;
	cout << "Postfix Expression: " << output_expression << endl;
	return 0; }
