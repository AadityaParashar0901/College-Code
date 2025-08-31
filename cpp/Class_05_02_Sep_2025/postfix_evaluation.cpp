#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Stack {
private: int stack[256], stack_size;
public: Stack () { stack_size = 0; }
	void push(int v) { stack[stack_size++] = v; }
	int pop() { return stack[--stack_size]; }
	int peek() { return stack[stack_size - 1]; }
	int getSize() { return stack_size; }
	void traverse() { if (stack_size == 0) cout << "Empty"; for (int i = 0; i < stack_size; i++) cout << stack[i] << ((i < stack_size - 1) ? "," : ""); }
};
enum TokenType {
	OPERATOR,
	OPERAND
};
struct Token {
	enum TokenType type; int value;
	Token (TokenType t, int v) {
		type = t; value = v;
	}
};
bool isOperator (char o) { static int i;
	static char operators[] = "+-*/^";
	for (i = 0; operators[i] != 0; i++) if (operators[i] == o) return true;
	return false; }
bool isNumber (char o) { return (o >= 48 && o <= 57); }
vector<Token> parse (char *string) { int v = 0, i = 0; static char c;
	vector<Token> tokens;
	TokenType lastType;
	while (c = string[i++]) {
		if (isOperator(c)) {
			if (v > 0) { tokens.push_back( {OPERAND, v} ); v = 0; }
			tokens.push_back({OPERATOR, int(c)} );
			lastType = OPERATOR;
		} else if (isNumber(c)) {
			v = v * 10 + c - 48;
			lastType = OPERAND;
		} else if (c == 32) {
			if (v > 0) { tokens.push_back( {OPERAND, v} ); v = 0; }
		} else {
			cout << "Invalid Character at Position: " << i << endl; return tokens;
		}
	}
	if (v > 0) tokens.push_back({OPERAND, v});
	return tokens;
}
int interpret (vector<Token> tokens) {
	Stack operands;
	for (int i = 0; i < tokens.size(); i++) {
		cout << "At Position: " << i << ": "; operands.traverse(); cout << ", Current Token: " << tokens[i].type << ":" << tokens[i].value << endl;
		if (tokens[i].type == OPERATOR) {
			switch (char(tokens[i].value)) {
				case '+': operands.push(operands.pop() + operands.pop()); break;
				case '-': operands.push(operands.pop() - operands.pop()); break;
				case '*': operands.push(operands.pop() * operands.pop()); break;
				case '/': operands.push(operands.pop() / operands.pop()); break;
				case '^': operands.push(pow(operands.pop(), operands.pop())); break;
			}
		} else {
			operands.push(tokens[i].value);
		}
	}
	return operands.pop();
}
int main() { char input_expression[256]; int i;
	cout << "Enter a Postfix Expression: "; cin.getline(input_expression, 256);
	vector<Token> tokens = parse(input_expression);
	for (i = 0; i < tokens.size() - 1; i++) {
		cout << tokens[i].type << ":" << tokens[i].value << ",";
	} cout << tokens[i].type << ":" << tokens[i].value << endl;
	int answer = interpret(tokens);
	cout << "Answer: " << answer << endl;
	return 0;
}
