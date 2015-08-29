// Lab 005 
// Name :
// Student ID :

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

template <class T>
class Queue
{// A finite ordered list with zero or more elements.
private:
	T* queue;	// array for queue elements
	int front,// one counterclockwise from front
		rear, 	// array position of rear element
		capacity;	// capacity of queue array

public:
	Queue(int queueCapacity = 4);
	// Create an empty queue whose initial capacity is queueCapacity

	bool IsEmpty() const;
	// if number of elements in the queue is equal to 0, return  true else return false.

	void Push(const T& item);
	// Insert item into the rear of the queue

	void Pop();
	// Delete the front element of the queue

	void Show();
	// show the elements from the front to rear

	void Internal() { cout << "rear=" << rear << ", " << "front=" << front << endl; }
	// show the front and rear value.

};