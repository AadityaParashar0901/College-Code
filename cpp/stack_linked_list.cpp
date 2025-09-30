#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next;
	Node (int v) { value = v; next = NULL; }
	Node (int v, Node *n) { value = v; next = n; }
};
class Stack {
private:	Node *head; int length;
public:	Stack () { head = NULL; length = 0; }
	void push (int v) { head = new Node (v, head); length++; }
	int pop () { if (head == NULL) return 0;
		Node *tmp = head; int value = head->value; length--;
		head = head->next; delete tmp; return value; }
	int peek () { if (head == NULL) return 0;
		return head->value; }
};
int main () {
	Stack s;
	cout << "Pushing: ";
	for (int i = 1; i <= 10; i++) {
		cout << i << " ";
		s.push(i);
	}
	cout << "\nPopping: ";
	for (int i = 1; i <= 9; i++) {
		cout << s.pop() << " ";
	}
	cout << "\nLast Element: " << s.peek() << endl;
	return 0;
}
