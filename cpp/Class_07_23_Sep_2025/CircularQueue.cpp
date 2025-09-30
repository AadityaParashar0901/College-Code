#include <iostream>
using namespace std;
class Queue {
	int *queue, queue_size, front, rear;
public:	Queue (int size) {
		queue = new int[++size];
		for (int i = 0; i < size; i++)
			queue[i] = 0;
		queue_size = size;
		front = 0;
		rear = 0;
	}
	void enqueue (int value) {
		if ((rear + 1) % queue_size == front) { cout << "Overflow\n"; return; }
		queue[rear] = value;
		rear = (rear + 1) % queue_size;
		return;
	}
	int dequeue () {
		if (front == rear) { cout << "Underflow"; return 0; }
		int tmp = queue[front];
		queue[front++] = 0;
		front %= queue_size;
		return tmp;
	}
	int peek () {
		if (front == rear) { cout << "Underflow"; return 0; }
		return queue[front];
	}
	void traverse () {
		if (front == rear) cout << "Empty";
		for (int i = front; i != rear; i = (i + 1) % queue_size) cout << queue[i] << " ";
		cout << endl;
	}
};
int main () {
	Queue queue(3);
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
