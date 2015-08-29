// HW 1
// Name :
// Student ID :

#include<iostream>
#include<string>
using namespace std;

template <class T>
class Stack {
public:
	T *stack;
	int capacity;	// size of termArray
	int top;	// number of nonzero terms

public:
	Stack(int stackCapacity = 1000);
	// Create an empty stack whose initial capacity is stackCapacity
	~Stack();

	bool IsEmpty() const;
	// If number of elements in the stack is 0, return true else return false
	bool IsFull() const;

	T & Top() const;
	// Return top element of stack

	void Push(const T & item);
	// Insert item into the top of the stack

	void Pop();
	// Delete the top element of the stack
};

void Path(const int m, const int p, int **maze, int **mark);