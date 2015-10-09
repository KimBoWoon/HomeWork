#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
#include <Windows.h>
using namespace std;

typedef unsigned __int64 UINT64;

int maxSubsequenceSum(int a[], int n, int start, int end, UINT64 &computeCount);

int main() {
	ifstream in;
	ofstream out;
	//time_t start_time, finish_time;
	int testCase;
	UINT64 computeCount = 0;
	LARGE_INTEGER start_time, finish_time, liFrequency;

	in.open("input.txt");
	out.open("n^2 output.dat");
	in >> testCase;

	QueryPerformanceFrequency(&liFrequency);
	int* arr = NULL;

	arr = new int[testCase];
	//memset(arr, 0, sizeof(arr) * testCase);

	for (int i = 0; i < testCase; i++)
		in >> arr[i];

	//start_time = clock();
	for (int i = 10000; i < 100001; i += 10000) {
		QueryPerformanceCounter(&start_time);
		cout << "MAX : " << maxSubsequenceSum(arr, i, 0, i - 1, computeCount) << endl;
		QueryPerformanceCounter(&finish_time);

		cout << i << endl;
		cout << "Compute Count : " << computeCount << endl;
		printf("Time : %f\n", (double)(finish_time.QuadPart - start_time.QuadPart) / (double)liFrequency.QuadPart);
		//out << i << endl;
		/*out << "Comoute Count >> " << computeCount << endl;
		out << "Time >> " << (double)((double)finish_time.QuadPart - (double)start_time.QuadPart) / (double)liFrequency.QuadPart << endl;*/
		//out << computeCount << endl;
		out << i << " ";
		out << (double)((double)finish_time.QuadPart - (double)start_time.QuadPart) / (double)liFrequency.QuadPart << endl;
		computeCount = 0;
	}
	for (int i = 200000; i < 1000001; i += 100000) {
		QueryPerformanceCounter(&start_time);
		cout << "MAX : " << maxSubsequenceSum(arr, i, 0, i - 1, computeCount) << endl;
		QueryPerformanceCounter(&finish_time);

		cout << i << endl;
		cout << "Compute Count : " << computeCount << endl;
		printf("Time : %f\n", (double)(finish_time.QuadPart - start_time.QuadPart) / (double)liFrequency.QuadPart);
		//out << i << endl;
		/*out << "Comoute Count >> " << computeCount << endl;
		out << "Time >> " << (double)((double)finish_time.QuadPart - (double)start_time.QuadPart) / (double)liFrequency.QuadPart << endl;*/
		//out << computeCount << endl;
		out << i << " ";
		out << (double)((double)finish_time.QuadPart - (double)start_time.QuadPart) / (double)liFrequency.QuadPart << endl;
		computeCount = 0;
	}
	//finish_time = clock();
	//cout << "Start Time : " << start_time << endl;
	//cout << "Finish Time : " << finish_time << endl;
	//cout << (double)(((double)finish_time - start_time) / CLOCKS_PER_SEC) << endl;
	out.close();
	in.close();
}
// O(n^3)
//int maxSubsequenceSum(int a[], int n, int start, int end, UINT64 &computeCount) {
//	int i, j, k;
//	int maxSum = 0;
//
//	start = end = -1;
//
//	for (i = 0; i < n; i++) {
//		for (j = i; j < n; j++) {
//			int thisSum = 0;
//
//			for (k = i; k <= j; k++) {
//				thisSum += a[k];
//				computeCount++;
//			}
//			if (thisSum > maxSum) {
//				maxSum = thisSum;
//				start = i;
//				end = j;
//			}
//		}
//	}
//	return maxSum;
//}
// O(n^2)
int maxSubsequenceSum(int a[], int n, int start, int end, UINT64 &computeCount) {
	int i, j, k;
	int maxSum = 0;

	start = end = -1;

	for (i = 0; i < n; i++) {
		int thisSum = 0;

		for (j = i; j < n; j++) {
			thisSum += a[j];
			computeCount++;

			if (thisSum > maxSum) {
				maxSum = thisSum;
				start = i;
				end = j;
			}
		}
	}
	return maxSum;
}
// O(n)
//int maxSubsequenceSum(int a[], int n, int start, int end, UINT64 &computeCount) {
//	int i, j;
//	int maxSum = 0, thisSum = 0;
//
//	start = end = -1;
//
//	for (i = 0, j = 0; j < n; j++) {
//		thisSum += a[j];
//		computeCount++;
//
//		if (thisSum > maxSum) {
//			maxSum = thisSum;
//			start = i;
//			end = j;
//		}
//		else if (thisSum < 0) {
//			i = j + 1;
//			thisSum = 0;
//		}
//	}
//	return maxSum;
//}
// O(n log n)
//int maxSubsequenceSum(int a[], int n, int start, int end, UINT64 &computeCount) {
//	if (start == end){
//		return a[start] > 0 ? a[start] : 0;
//	}
//
//	int center = (start + end) / 2;
//	int maxLeftSum = maxSubsequenceSum(a, n, start, center, computeCount);
//	int maxRightSum = maxSubsequenceSum(a, n, center + 1, end, computeCount);
//
//	int maxLeftCenterSum = 0;
//	int maxRightCenterSum = 0;
//	int leftCenterSum = 0;
//	int rightCenterSum = 0;
//
//	for (int i = center; i >= start; --i)
//	{
//		leftCenterSum += a[i]; // basic operation
//		computeCount++;
//		if (leftCenterSum > maxLeftCenterSum)
//			maxLeftCenterSum = leftCenterSum;
//	}
//
//	for (int i = center + 1; i <= end; ++i)
//	{
//		rightCenterSum += a[i]; // basic operation
//		computeCount++;
//		if (rightCenterSum > maxRightCenterSum)
//			maxRightCenterSum = rightCenterSum;
//	}
//
//	int max = maxLeftSum;
//	if (maxRightSum > max)
//		max = maxRightSum;
//	if (maxLeftCenterSum + maxRightCenterSum > max)
//		max = maxLeftCenterSum + maxRightCenterSum;
//
//	return max;
//}