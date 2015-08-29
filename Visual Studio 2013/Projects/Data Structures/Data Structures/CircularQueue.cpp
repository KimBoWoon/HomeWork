#include <iostream>
#include <memory>
#include <string>
using namespace std;

template <typename T>
class Circular_Queue
{
private:
	T *queue;
	int size, front, rear, capacity;
public:
	Circular_Queue(int capacity = 5);
	void enqueue(T data);
	void dequeue();
	void show();
};
template <typename T>
Circular_Queue<T>::Circular_Queue(int capacity) : size(0), front(0), rear(0), capacity(capacity)
{
	queue = new T[capacity];
	memset(queue, -1, sizeof(T) * capacity);
}
template <typename T>
void Circular_Queue<T>::enqueue(T data)
{
	if (front == (rear + 1) % capacity)
		throw "Queue is Full";
	size++;
	rear = (rear + 1) % capacity;
	queue[rear] = data;
}
template <typename T>
void Circular_Queue<T>::dequeue()
{
	if (front == rear)
		throw "Queue is empty. Cannot delete";
	size--;
	front = (front + 1) % capacity;
	queue[front] = -1;
}
template <typename T>
void Circular_Queue<T>::show()
{
	int f = front, r = rear;
	cout << "Size : " << size << endl;
	cout << "Queue : ";
	for (; f != r; f %= capacity)
		cout << queue[++f %= capacity] << " ";
	cout << endl;
}
int main()
{
	Circular_Queue<int> cq(10);
	string command;

	while (true)
	{
		try
		{
			cout << "queue > ";
			cin >> command;

			if (command.compare("en") == 0)
			{
				int dummy;
				cin >> dummy;
				cq.enqueue(dummy);
			}
			else if (command.compare("de") == 0)
				cq.dequeue();

			cq.show();
		}
		catch (const char* s)
		{
			cout << s << endl;
		}
	}
}