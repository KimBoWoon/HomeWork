//#include <iostream>
//using namespace std;
//
//#define SIZE 5
//#define M 999999999
//
//class ShortestPath {
//private:
//	void FloydPrint(int i, int j, int key[SIZE][SIZE]);
//public:
//	void Dijkstras(int arr[SIZE][SIZE], int v);
//	void BellmanFord(int arr[SIZE][SIZE], int v);
//	void Floyd(int arr[SIZE][SIZE], int start, int end);
//};
//void ShortestPath::Dijkstras(int arr[SIZE][SIZE], int v) {
//	int d[SIZE], p[SIZE] = { 0 };
//	int min = M, f;
//
//	for (int i = 0; i < SIZE; i++)
//		d[i] = M;
//
//	d[v] = 0;
//
//	for (int i = 0; i < SIZE; i++) {
//		f = 0;
//		min = M;
//		for (int j = 0; j < SIZE; j++) {
//			if (d[j] < min & p[j] == 0) {
//				min = d[j];
//				f = j;
//			}
//		}
//		p[f] = 1;
//		for (int j = 0; j < SIZE; j++) {
//			if (d[f] + arr[f][j] < d[j])
//				d[j] = d[f] + arr[f][j];
//		}
//	}
//	for (int i = 0; i < SIZE; i++)
//		(i == SIZE - 1) ? cout << d[i] << endl : cout << d[i] << " ";
//}
//void ShortestPath::BellmanFord(int arr[SIZE][SIZE], int v) {
//	cout << "¸ô¶ó º´½Å¾Æ" << endl;
//}
//void ShortestPath::Floyd(int arr[SIZE][SIZE], int start, int end) {
//	int key[SIZE][SIZE] = { 0 }, c[SIZE][SIZE] = { 0 };
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int j = 0; j < SIZE; j++)
//			key[i][j] = -1;
//	}
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int j = 0; j < SIZE; j++)
//			c[i][j] = arr[i][j];
//	}
//	for (int k = 0; k < SIZE; k++)
//	{
//		for (int i = 0; i < SIZE; i++)
//		{
//			for (int j = 0; j < SIZE; j++)
//			{
//				if (c[i][j] > c[i][k] + c[k][j])
//				{
//					key[i][j] = k;
//					c[i][j] = c[i][k] + c[k][j];
//				}
//			}
//		}
//	}
//	/*cout << "arr" << endl;
//	for (int i = 0; i < SIZE; i++)
//	{
//	for (int j = 0; j < SIZE; j++)
//	cout << arr[i][j] << "	";
//	cout << endl;
//	}
//	cout << "key" << endl;
//	for (int i = 0; i < SIZE; i++)
//	{
//	for (int j = 0; j < SIZE; j++)
//	cout << key[i][j] << "	";
//	cout << endl;
//	}
//	cout << "c" << endl;
//	for (int i = 0; i < SIZE; i++)
//	{
//	for (int j = 0; j < SIZE; j++)
//	cout << c[i][j] << "	";
//	cout << endl;
//	}*/
//	cout << start;
//	FloydPrint(start, end, key);
//	cout << endl;
//}
//void ShortestPath::FloydPrint(int i, int j, int key[SIZE][SIZE]) {
//	if (i == j)
//		return;
//	if (key[i][j] == -1)  // no intermediate vertices on path
//		cout << " -> " << j;
//	else { // kay[i][j] is an intermediate vertex on the path
//		FloydPrint(i, key[i][j], key);
//		FloydPrint(key[i][j], j, key);
//	}
//}
//
//int main() {
//	/*int arr[SIZE][SIZE] = {
//		0, 3, M, 2, M,
//		M, 0, 4, M, 6,
//		M, M, 0, 7, 3,
//		M, M, M, 0, 5,
//		4, M, M, M, 0
//		};*/
//	/*int arr[SIZE][SIZE] = {
//		0, 6, 2, 16, M, M, 14,
//		M, 0, M, 5, 4, M, M,
//		M, 7, 0, M, 3, 8, M,
//		M, M, M, 0, M, M, 3,
//		M, M, M, 4, 0, M, 10,
//		M, M, M, M, M, 0, 1,
//		M, M, M, M, M, M, 0,
//		};*/
//	//int arr[SIZE][SIZE] = {
//	//	0, 7, 5, 1, M, M, M, M,
//	//	M, 0, M, M, 4, M, M, M,
//	//	M, 7, 0, M, 9, 9, M, M,
//	//	M, 5, M, 0, M, M, 16, M,
//	//	M, M, M, 4, 0, M, M, 1,
//	//	M, M, M, M, M, 0, 1, M,
//	//	2, M, M, M, M, M, 0, 4,
//	//	M, M, M, M, M, 2, 4, 0
//	//};
//	int arr[SIZE][SIZE] = {
//		0, 5, 10, 8, 7,
//		5, 0, 5, 3, 6,
//		10, 5, 0, 1, 3,
//		8, 3, 1, 0, 1,
//		7, 6, 3, 1, 0
//	};
//	ShortestPath SP;
//
//	cout << "<<Dijkstras>>" << endl;
//	SP.Dijkstras(arr, 4);
//	cout << "<<BellmanFord>>" << endl;
//	SP.BellmanFord(arr, 0);
//	cout << "<<Floyd>>" << endl;
//	SP.Floyd(arr, 0, 4);
//}