#include <iostream>
#include <string>
#include <cstring>
#include <memory>
using namespace std;

class PriorityQueue
{
private:
	int *queue, capacity, size;
public:
	PriorityQueue(int capacity = 3);
	void swap(int i, int j);

	void enqueue(int data);
	void dequeue();

	void show();
};
PriorityQueue::PriorityQueue(int capacity) : capacity(capacity), size(1)
{
	queue = new int[capacity];
	memset(queue, 0, sizeof(int) * capacity);
}
void PriorityQueue::swap(int i, int j)
{
	int temp = queue[i];
	queue[i] = queue[j];
	queue[j] = temp;
}

void PriorityQueue::enqueue(int data)
{
	if (size == capacity)
	{
		cout << "resize!!" << endl;
		int *dummy = new int[capacity];

		for (int i = 0; i < size; i++)
			dummy[i] = queue[i];

		capacity *= 2;

		delete[]queue;

		queue = new int[capacity];

		for (int i = 0; i < size; i++)
			queue[i] = dummy[i];

		delete[]dummy;
	}

	int cur = size;

	queue[size] = data;

	while (cur > 1)
	{
		if (queue[cur / 2] > queue[cur])
			swap(cur / 2, cur);

		cur = cur / 2;
	}

	size++;
}
void PriorityQueue::dequeue()
{
	if (size == 0)
	{
		cout << "저장된 원소가 없습니다!" << endl;
		return;
	}

	queue[1] = 0;
	size--;
	swap(size, 1);

	int root = queue[1];
	int child = 2;

	while (child <= size)
	{
		if ((child < size) && (queue[child] > queue[child + 1]))
			child++;
		if (root < queue[child] || queue[child] == 0)
			break;
		else
		{
			queue[child / 2] = queue[child];
			child *= 2;
		}
	}
	queue[child / 2] = root;
}

void PriorityQueue::show()
{
	cout << "Priority Queue Size >> " << size << endl;
	cout << "Priority Queue >> ";
	for (int i = 1; i < size; i++)
		(i == size - 1) ? cout << queue[i] << endl : cout << queue[i] << " ";
}
int main()
{
	PriorityQueue PQ;
	string command;

	cout << "추가 : en, 삭제 : de, 종료 : quit" << endl;

	while (true)
	{
		cin >> command;

		if (command.compare("en") == 0)
		{
			int data;
			cin >> data;
			PQ.enqueue(data);
		}
		else if (command.compare("de") == 0)
			PQ.dequeue();
		else if (command.compare("quit") == 0)
			return 0;

		PQ.show();
	}
}