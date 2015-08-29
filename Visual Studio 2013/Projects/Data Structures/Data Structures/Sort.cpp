#include <iostream>
using namespace std;

class Sort{
private:
	void Adjust(int *arr, const int root, int n);
	void MergeTwoArea(int *arr, int left, int mid, int right);
	void swap(int *arr, int i, int j);
	int Partition(int *arr, int left, int right);
	int MedianOfThree(int *arr, int left, int right);
public:
	void BubbleSorting(int *arr, int size);
	void SelectionSorting(int *arr, int size);
	void InsertionSorting(int *arr, int size);
	void HeapSorting(int *arr, int size);
	void MergeSorting(int *arr, int left, int right);
	void QuickSorting(int *arr, int left, int right);
};
int Sort::MedianOfThree(int *arr, int left, int right) {
	int pivot[3] = { left, (left + right) / 2, right };

	if (arr[pivot[0]] > arr[pivot[1]])
		swap(pivot, 0, 1);

	if (arr[pivot[1]] > arr[pivot[2]])
		swap(pivot, 1, 2);

	if (arr[pivot[0]] > arr[pivot[1]])
		swap(pivot, 0, 1);

	return pivot[1];
}
void Sort::swap(int *arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int Sort::Partition(int *arr, int left, int right){
	int pIdx = MedianOfThree(arr, left, right);// (left + right) / 2;
	//int pIdx = right;
	//int pIdx = left;
	int pivot = arr[pIdx];    // �ǹ��� ��ġ�� ���� ����! 
	int low = left + 1;
	int high = right;
	cout << arr[pIdx] << endl;
	swap(arr, left, pIdx);    // �ǹ��� ���� �������� �̵�

	while (low <= high){    // �������� ���� ������ �ݺ�
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot <= arr[high] && high >= (left + 1))
			high--;
		if (low <= high)    // �������� ���� ���¶�� Swap ����
			swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
	}
	swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ
	
	return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}
void Sort::Adjust(int *arr, const int root, int n){
	int child, rootkey;
	int temp;

	temp = arr[root];
	rootkey = arr[root];
	child = 2 * root;
	if (n == 0)
		return;
	while (child <= n){
		if ((child < n) && (arr[child] < arr[child + 1]))
			child++;
		if (rootkey > arr[child])
			break;
		else {
			arr[child / 2] = arr[child];
			child *= 2;
		}
	}
	arr[child / 2] = temp;
}
void Sort::MergeTwoArea(int *arr, int left, int mid, int right){
	int fIdx = left;
	int rIdx = mid + 1;

	int *sortArr = new int[sizeof(int) * (right + 1)];
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right){
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];
		sIdx++;
	}

	for (; rIdx <= right; rIdx++, sIdx++)
		sortArr[sIdx] = arr[rIdx];
	for (; fIdx <= mid; fIdx++, sIdx++)
		sortArr[sIdx] = arr[fIdx];

	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];

	delete[]sortArr;
}
void Sort::BubbleSorting(int *arr, int size){
	for (int i = 0; i < size - 1; i++){
		for (int j = 0; j < (size - i) - 1; j++){
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}
}
void Sort::SelectionSorting(int *arr, int size){
	for (int i = 0; i < size; i++){
		int minidx = i;

		for (int j = i + 1; j < size; j++){
			if (arr[minidx] > arr[j])
				minidx = j;
		}
		swap(arr, i, minidx);
	}
}
void Sort::InsertionSorting(int *arr, int size){
	for (int i = 0; i < size; i++){
		int insertdata = arr[i], j;

		for (j = i - 1; j >= 0; j--){
			if (arr[j] > insertdata)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insertdata;
	}
}
void Sort::HeapSorting(int *arr, int size){
	for (int i = size / 2; i > 0; i--)
		Adjust(arr, i, size);

	for (int i = size; i > 0; i--){
		swap(arr, 0, i);
		Adjust(arr, 0, i - 1);
	}
}
void Sort::MergeSorting(int *arr, int left, int right){
	int mid;

	if (left < right){
		mid = (left + right) / 2;

		MergeSorting(arr, left, mid);
		MergeSorting(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}
void Sort::QuickSorting(int *arr, int left, int right){
	if (left <= right){
		int pivot = Partition(arr, left, right);    // �ѷ� ������
		QuickSorting(arr, left, pivot - 1);    // ���� ������ ����
		QuickSorting(arr, pivot + 1, right);    // ������ ������ ����
	}
}
int main(){
	int arr[10] = { 10, 8, 6, 5, 2, 1, 4, 3, 9, 7 };
	//int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	Sort sort;
	int size = sizeof(arr) / sizeof(int);

	//cout << "<<Bubble Sorting>>" << endl;
	//sort.BubbleSorting(arr, size);
	//cout << "<<Selection Sorting>>" << endl;
	//sort.SelectionSorting(arr, size);
	//cout << "<<Insertion Sorting>>" << endl;
	//sort.InsertionSorting(arr, size);
	//cout << "<<Heap Sorting>>" << endl;
	//sort.HeapSorting(arr, size - 1);
	//cout << "<<Merge Sorting>>" << endl;
	//sort.MergeSorting(arr, 0, size - 1);
	cout << "<<Quick Sorting>>" << endl;
	sort.QuickSorting(arr, 0, size - 1);

	for (int i = 0; i < size; i++)
		(i == size - 1) ? cout << arr[i] << endl : cout << arr[i] << " ";
}