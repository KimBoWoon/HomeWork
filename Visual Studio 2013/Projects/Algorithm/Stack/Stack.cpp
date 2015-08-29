#include "Stack.h"

Stack::Stack(int capacity) : stackPoint(-1), stackcapacity(capacity) {
	stack = new int[capacity];
	memset(stack, 0, sizeof(int) * capacity);
}
bool Stack::push(int data) {
	if (!(full())) {
		stack[++stackPoint] = data;
		return true;
	}
	else
		throw "Stack Is Full";
}
bool Stack::pop() {
	if (!(empty())) {
		stack[stackPoint--] = 0;
		return true;
	}
	else
		throw "Stack Is Empty";
}
int Stack::top() {
	return stack[stackPoint];
}
bool Stack::empty() {
	if (stackPoint == -1)
		return true;
	return false;
}
bool Stack::full() {
	if (stackPoint == (stackcapacity - 1))
		return true;
	return false;
}
int Stack::size() {
	return stackPoint;
}
int Stack::capacity() {
	return stackcapacity;
}