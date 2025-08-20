#include <iostream>
#include <queue>
using namespace std;

class Stack {
	int stack[16], size;
public:	char name[16];
	Stack(char* n) { for (int i = 0; i < 16; i++) stack[i] = 0; size = 0; { int i = 0; do name[i] = n[i]; while (n[i++] != 0); } }
	int getSize() { return size; }
	void push(int value) { if (size < 16) stack[size++] = value; }
	int peek() { if (size > 0) return stack[size - 1]; return 0; }
	int pop() { if (size > 0) return stack[--size]; return 0; }
	void traverse() { cout << name << ": "; if (size == 0) cout << "Empty"; for (int i = 0; i < size; i++) cout << stack[i] << " "; cout << endl; }
	operator [] (int i) { if (i < size) return stack[i]; return 0; }
	friend void movePeg(Stack& , Stack& );
};
void showStacks (int totalPegs, Stack A, Stack B, Stack C) { static int i, s, j, c;
	static char space = 32, pillar = 179, block = 219;
	Stack stacks[3] = { A, B, C };
	for (i = totalPegs - 1; i >= 0; i--) {
		for (s = 0; s < 3; s++) {
			c = stacks[s][i];
			for (j = 0; j <= 2 * totalPegs; j++) {
				if (c == 0 && j == totalPegs) cout << pillar;
				else if (j > totalPegs - c && j < totalPegs + c) cout << block;
				else cout << space;
			}
		}
		cout << endl;
	}
}
void movePeg(Stack* a, Stack* b) {
	if ((a->peek() > b->peek() && b->getSize()) || a->getSize() == 0) {
		cout << "Invalid Move: " << a->name << "->" << b->name << endl;
		return;
	}
	b->push(a->pop());
}
void solve(int n, int b, int a, int e, queue<int>& sQ) { // encodes in base 3
	if (n == 1) {
		sQ.push(b * 3 + e);
		return;
	}
	solve(n - 1, b, e, a, sQ);
	sQ.push(b * 3 + e);
	solve(n - 1, a, b, e, sQ);
}
void showSolvedQueue (int c) {
	int a = c / 3, b = c % 3;
	cout << char(a + 65) << "->" << char(b + 65) << endl;
	return;
}
void solveQueue (int c, Stack* A, Stack* B, Stack* C) { // solve the current move
	int a = c / 3, b = c % 3;
	static Stack* stacks[3] = { A, B, C };
	movePeg(stacks[a], stacks[b]);
}
int main(int totalArgs, char* args[]) {
	char nameA[] = "A", nameB[] = "B", nameC[] = "C"; // just for storing names
	Stack A(nameA), B(nameB), C(nameC); queue<int> solution;
	int totalPegs = 3; // change this
	if (totalArgs > 1) totalPegs = *args[1] - 48;
	for (int i = totalPegs; i > 0; i--) A.push(i); // push pegs
	solve(totalPegs, 0, 1, 2, solution); // generate solution queue
	int moveCount = 0;
	cout << "Initial:\n"; showStacks(totalPegs, A, B, C); // show Initial State
	while (!solution.empty()) {
		cout << endl; if (solution.size() == 1) cout << "Final ";
		cout << "Move " << ++moveCount << ": "; showSolvedQueue(solution.front());
		solveQueue(solution.front(), &A, &B, &C);
		solution.pop();
		showStacks(totalPegs, A, B, C);
	};
	return 0;
}
