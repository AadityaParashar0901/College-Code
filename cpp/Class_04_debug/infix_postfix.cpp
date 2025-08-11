#include <iostream>
#include <stack>
using namespace std;

int main() {
	char outputExpression[256]; int o = 0, constantsCount = 0;
	stack<char> operators;
	char expression[256], lastChar = 0;
	for (int i = 0; i < 256; i++) outputExpression[i] = 0;
	cout << "Enter an expression: "; cin >> expression;
	for (int i = 0; expression[i] != 0; i++) {
		cout << "Current character: " << expression[i] << endl;
		switch (expression[i]) {
			case '+':
			case '-':
			case '*':
			case '/':
				operators.push(expression[i]); cout << "Pushing operator " << expression[i] << " to stack.\n"; break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': if (lastChar >= '0' && lastChar <= '9') {
				} else {
					constantsCount++;
					if (o > 0) outputExpression[o++] = ' ';
				}
				outputExpression[o++] = expression[i];
				break;
		}
		lastChar = expression[i];
		cout << expression << endl;
		for (int j = 0; j < i; j++) cout << ' '; cout << "^\n";
		cout << outputExpression << endl;
		for (int j = 0; j < o - 1; j++) cout << ' '; cout << "^\n";
		cout << "ConstantsCount = " << constantsCount << endl;
		if (constantsCount >= 2 && operators.size() >= 1) {
			outputExpression[o++] = ' ';
			outputExpression[o++] = operators.top();
			constantsCount = 1;
			operators.pop();
		}
	}
	cout << "Final Expression: " << outputExpression << endl;
	return 0;
}
