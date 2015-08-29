#ifndef __STACK__
#define __STACK__

#include <iostream>
#include <memory>
using namespace std;

class Stack {
private:
	int stackPoint, stackcapacity;
	int *stack;
public:
	Stack(int capacity = 5);
	bool push(int data);
	bool pop();
	int top();
	bool empty();
	bool full();
	int size();
	int capacity();
};

#endif