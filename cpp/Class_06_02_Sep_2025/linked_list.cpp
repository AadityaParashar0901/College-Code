#include <iostream>
using namespace std;
struct Node {
	int value;
	Node *next;
	Node (int v) { value = v; next = NULL; }
	Node (int v, Node *n) { value = v; next = n; }
};
class SinglyLinkedList {
private:
	Node *head;
public:
	SinglyLinkedList () { head = NULL; }
	void create (int count, int value) {
		Node *tmp = head = new Node (value);
		for (int i = 1; i < count; i++) tmp = tmp->next = new Node (value); }
	int size () { Node *tmp = head; int l = 0;
		for (; tmp != NULL; l++) tmp = tmp->next;
		return l; }
	void insert_beginning (int value) { head = new Node (value, head); }
	void insert_position (int position, int value) { Node *tmp = head; // 1 <= position <= length + 1
		for (int i = 1; i < position - 1 && tmp != NULL; i++) tmp = tmp->next;
		if (tmp == NULL) return; tmp->next = new Node (value, tmp->next); }
	void insert_end (int value) {
		if (head == NULL) return insert_beginning (value);
		Node *tmp;
		for (tmp = head; tmp->next != NULL; ) tmp = tmp->next;
		tmp->next = new Node (value); }
	void delete_beginning () {
		if (head == NULL) return;
		Node *tmp = head; head = head->next;
		delete tmp; }
	void delete_position (int position) {
		if (head == NULL) return;
		Node *tmp = head;
		for (int i = 1; i < position - 1 && tmp != NULL; i++) tmp = tmp->next;
		Node *tmp2 = tmp->next; tmp->next = tmp->next->next;
		delete tmp2; }
	void delete_end () {
		if (head == NULL) return;
		Node *tmp, *prev = NULL;
		for (tmp = head; tmp->next != NULL; ) { prev = tmp; tmp = tmp->next; }
		delete tmp; if (prev != NULL) prev->next = NULL; }
	void traverse () {
		if (head == NULL) return;
		Node *tmp = head;
		while (tmp != NULL) cout << tmp->value << (((tmp = tmp->next) == NULL) ? "\n" : ","); }
	int search (int value) {
		if (head == NULL) return 0;
		Node *tmp = head; int p = 2;
		for (; tmp != NULL && tmp->value != value; p++) tmp = tmp->next;
		if (tmp == NULL) return 0;
		return p; }
	void reverse () {
		if (head == NULL) return;
		Node *tmp = head, *tmp2 = NULL, *prev = NULL;
		while (tmp != NULL) {
			tmp2 = tmp->next; tmp->next = prev;
			prev = tmp; tmp = tmp2; }
		head = prev; }
	void clear () {
		if (head == NULL) return;
		Node *tmp = head, *current = NULL;
		while (tmp != NULL) {
			current = tmp; tmp = tmp->next;
			delete current; }
		head = NULL; }
};
int main() {
	SinglyLinkedList list; int choice, position, value;
	cout << "1. Create Linked List\n";
	cout << "2. Count Number of Nodes\n";
	cout << "3. Insert Value at Beginning\n";
	cout << "4. Insert Value at Position\n";
	cout << "5. Insert Value at End\n";
	cout << "6. Delete Value from Beginning\n";
	cout << "7. Delete Value from Position\n";
	cout << "8. Delete Value from End\n";
	cout << "9. Traverse List\n";
	cout << "10. Search in List\n";
	cout << "11. Reverse List\n";
	cout << "12. Clear List\n";
	do {
		cout << "Enter Choice: "; cin >> choice;
		switch (choice) {
			case 1: cout << "Enter Number of Nodes to Create: "; cin >> position;
				cout << "Enter Value to Fill with: "; cin >> value;
				list.create(position, value); break;
			case 2: cout << list.size() << endl; break;
			case 3: cout << "Enter Value to Insert: "; cin >> value;
				list.insert_beginning(value); break;
			case 4: cout << "Enter Position to Insert at: "; cin >> position;
				cout << "Enter Value to Insert: "; cin >> value;
				list.insert_position(position, value); break;
			case 5: cout << "Enter Value to Insert: "; cin >> value;
				list.insert_end(value); break;
			case 6: list.delete_beginning(); break;
			case 7: cout << "Enter Position to Delete from: "; cin >> position;
				list.delete_position(position); break;
			case 8: list.delete_end(); break;
			case 9: list.traverse(); break;
			case 10: cout << "Enter Value to Search: "; cin >> value;
				cout << "Position of " << value << " is " << list.search(value) << endl; break;
			case 11: list.reverse(); break;
			case 12: list.clear(); break;
			default: cout << "Invalid Choice\nExiting";
		}
		cout << endl;
	} while (choice >= 0 && choice <= 12);
	return 0;
}
