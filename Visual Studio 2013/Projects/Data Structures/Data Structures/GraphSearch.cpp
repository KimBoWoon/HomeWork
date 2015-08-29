#include <iostream>
#include <queue>
using namespace std;

#define SIZE 7

class GraphSearch{
public:
	void DFS(int arr[SIZE][SIZE], int *mark, int size, int v);
	void BFS(int arr[SIZE][SIZE], int *mark, int size, int v);
};
void GraphSearch::DFS(int arr[SIZE][SIZE], int *mark, int size, int v) {
	cout << v << ' ';
	mark[v] = 1;
	for (int i = 0; i < size; i++) {
		if (arr[v][i] && !mark[i])
			DFS(arr, mark, size, i);
	}
}
void GraphSearch::BFS(int arr[SIZE][SIZE], int *mark, int size, int v) {
	queue<int> q;

	q.push(v);
	mark[v] = 1;
	while (true)
	{
		for (int i = 0; i < size; i++) {
			if (arr[v][i] && !mark[i]) {
				q.push(i);
				mark[i] = 1;
			}
		}
		q.pop();
		cout << v << " ";
		if (q.empty())
			return;
		v = q.front();
	}
}
int main() {
	/*int arr[SIZE][SIZE] = {
		0, 1, 0, 1, 0,
		1, 0, 0, 0, 1,
		0, 0, 0, 0, 1,
		1, 0, 0, 0, 1,
		0, 1, 1, 1, 0
	};*/
	int arr[SIZE][SIZE] = {
		0, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 0, 0,
		0, 0, 0, 1, 0, 1, 0,
		0, 0, 0, 0, 1, 0, 1,
		0, 0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 0, 0, 0,
	};
	int mark[SIZE] = { 0 };
	GraphSearch GS;

	//cout << "<<±íÀÌ ¿ì¼± Å½»ö(DFS)>>" << endl;
	//GS.DFS(arr, mark, SIZE, 0);
	//cout << endl;
	cout << "<<³Êºñ ¿ì¼± Å½»ö(BFS)>>" << endl;
	GS.BFS(arr, mark, SIZE, 0);
	cout << endl;
}