// Lab 005 
// Name : Kim Bo Woon
// Student ID : 20113259

#include "Circular_Queue.h"

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if (capacity < 1)
		throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}
template <class T>
inline bool Queue<T>::IsEmpty() const {
	// NEED TO IMPLEMENT
	if (front == rear)
		return true;
	else
		return false;
}
template <class T>
void Queue<T>::Push(const T& item)
{
	// Add x at rear of queue

	// NEED TO IMPLEMENT
	// if queue full, throw the following message
	if (front == (rear + 1) % capacity)
		throw "Queue is Full";
	rear = (rear + 1) % capacity;
	queue[rear] = item;
}
template <class T>
void Queue<T>::Pop()
{	// Delete front element from queue

	// NEED TO IMPLEMENT

	// if queue is empty, throw the following message
	if (IsEmpty())
		throw "Queue is empty. Cannot delete";
	front = (front + 1) % capacity;
	queue[front] = 0;
}
template <class T>
void Queue<T>::Show()
{
	// Show the elements from the front to read
	// NEED TO IMPLEMENT
	int f = front, r = rear;
	cout << "Queue : ";
	for (; f != r; f %= capacity)
		cout << queue[++f %= capacity] << " ";
	cout << endl;
}