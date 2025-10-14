#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *left, *right;
	Node () { value = 0; left = right = NULL; }
	Node (int v) { value = v; left = right = NULL; }
	Node (Node *l, int v, Node *r) { value = v; left = l; right = r; }
};
class BinarySearchTree {
public:	Node *root;
	BinarySearchTree() { root = NULL; }
	void insert(int value) {
		Node *current = root, *parent = root;
		while (current != NULL) {
			parent = current;
			if (current->value < value) current = current->right;
			else if (current->value > value) current = current->left;
			else return;
		}
		if (parent == NULL) root = new Node(value);
		else if (parent->value > value) parent->left = new Node(value);
		else if (parent->value < value) parent->right = new Node(value);
	}
	bool search(int value) {
		Node *current = root;
		while (current != NULL) {
			if (current->value == value) return true;
			if (current->value > value) current = current->left;
			else if (current->value < value) current = current->right;
		}
		return false;
	}
	void traverse_preorder(Node *current) {
		if (current == NULL) return;
		cout << current->value << " ";
		traverse_preorder(current->left);
		traverse_preorder(current->right);
	}
	void traverse_inorder(Node *current) {
		if (current == NULL) return;
		traverse_inorder(current->left);
		cout << current->value << " ";
		traverse_inorder(current->right);
	}
	void traverse_postorder(Node *current) {
		if (current == NULL) return;
		traverse_postorder(current->left);
		traverse_postorder(current->right);
		cout << current->value << " ";
	}
};

int main() {
	BinarySearchTree bst;
	int choice, value;
	cout << "Choices:\n1. Insert\n2. Search\n3. Traverse Preorder\n";
	cout << "4. Traverse Inorder\n5. Traverse Postorder\n";
	loop:
	cout << "Enter your Choice: "; cin >> choice;
	switch(choice) {
		case 1: cout << "Enter a Value to Insert: "; cin >> value;
			bst.insert(value); break;
		case 2: cout << "Enter a Value to Search: "; cin >> value;
			if (bst.search(value)) cout << value << " found\n";
			else cout << value << " not found\n";
			break;
		case 3: bst.traverse_preorder(bst.root);
			cout << endl; break;
		case 4: bst.traverse_inorder(bst.root);
			cout << endl; break;
		case 5: bst.traverse_postorder(bst.root);
			cout << endl; break;
		default: cout << "Invalid Choice\n"; return 0;
	}
	goto loop;
	return 0;
}
