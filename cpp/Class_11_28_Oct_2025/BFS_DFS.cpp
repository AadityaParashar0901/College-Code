#include <iostream>
using namespace std;
#define MAX 100

void bfs_iterative(int graph[MAX][MAX], int start, int n) {
	int queue[MAX], front = 0, rear = 0;
	int visited[MAX] = {0};
	queue[rear++] = start;
	visited[start] = 1;
	while (front < rear) {
		int vertex = queue[front++];
		cout << vertex << " ";
		for (int i = 0; i < n; i++) {
			if (graph[vertex][i] == 1 && visited[i] == 0) {
				queue[rear++] = i;
				visited[i] = 1;
			}
		}
	}
}
void dfs_iterative(int graph[MAX][MAX], int start, int n) {
	int stack[MAX], top = 0;
	int visited[MAX] = {0};
	stack[top++] = start;
	visited[start] = 1;
	while (top) {
		int vertex = stack[--top];
		cout << vertex << " ";
		for (int i = 0; i < n; i++) {
			if (graph[vertex][i] == 1 && visited[i] == 0) {
				stack[top++] = i;
				visited[i] = 1;
			}
		}
	}
}
int main() {
	int graph[MAX][MAX], n, start;
	cout << "Enter the Number of Vertices: ";
	cin >> n;
	cout << "Enter the Adjacency Matrix:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	cout << "Adjacency Matrix:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
	cout << "Enter the Starting Vertex: ";
	cin >> start;
	cout << "DFS Traversal: ";
	dfs_iterative(graph, start, n);
	cout << "\nBFS Traversal: ";
	bfs_iterative(graph, start, n);
	return 0;
}
