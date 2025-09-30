#include <iostream>
using namespace std;
struct Node {
	int value;
	Node *next;
	Node () { value = 0; next = NULL; }
	Node (int v) { value = v; next = NULL; }
	Node (int v, Node *n) { value = v; next = n; }
};
class Queue {
	Node *head;
public:	Queue () { head = NULL; }
	void enqueue (int v) {
		Node *tmp = head, *prev = head;
		while (tmp != NULL) { prev = tmp; tmp = tmp->next; }
		if (prev == NULL) head = new Node (v);
		else prev->next = new Node (v);
	}
	int dequeue () {
		Node *tmp = head;
		if (tmp == NULL) {
			cout << "Underflow";
			return 0;
		}
		head = head->next;
		int v = tmp->value;
		delete tmp;
		return v;
	}
	int peek () {
		if (head == NULL) { cout << "Underflow"; return 0; }
		return head->value;
	}
	void traverse () {
		Node *tmp = head;
		while (tmp != NULL) {
			cout << tmp->value;
			if (tmp->next != NULL) cout << ",";
			tmp = tmp->next;
		}
		cout << endl;
	}
};
int main() {
	Queue queue;
	int choice, value;
	cout << "Choices:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Traverse\n5. Exit\n";
	loop:
	cout << "Enter Choice: "; cin >> choice;
	switch (choice) {
		case 1: cout << "Enter Value: "; cin >> value;
			queue.enqueue(value); break;
		case 2: cout << "Value: " << queue.dequeue() << endl;
			break;
		case 3: cout << "Peek: " << queue.peek() << endl;
			break;
		case 4: cout << "Queue: "; queue.traverse(); break;
		case 5: return 0;
		default: cout << "Invalid Choice\n";
	}
	cout << endl;
	goto loop;
	return 0;
}
