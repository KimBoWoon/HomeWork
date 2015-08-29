#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node* nextNode;
public:
	friend class LinkedStack;
	Node(int data);
};
Node::Node(int data = -1) {
	this->data = data;
}

class LinkedStack {
private:
	Node* head, *tail;
public:
	LinkedStack();

	void push(int data);
	void pop();

	void show();
};
LinkedStack::LinkedStack() : head(NULL), tail(NULL) {}

void LinkedStack::push(int data) {
	if (head == NULL) {
		head = new Node(data);
		tail = head;
	}
	else {
		tail->nextNode = new Node(data);
		tail = tail->nextNode;
	}
}
void LinkedStack::pop() {
	if (head == NULL)
		throw "Stack Is Empty";
	else {
		Node* deleteNode = head;

		while (deleteNode != tail)
			deleteNode = deleteNode->nextNode;

		tail = deleteNode;

		delete deleteNode->nextNode;
	}
}
void LinkedStack::show() {
	Node* cur = head;

	if (head == NULL)
		throw "Stack Is Empty";

	cout << cur->data << endl;
	while (cur->nextNode != NULL) {
		cur = cur->nextNode;
		cout << cur->data << endl;
	}
}

int main() {
	LinkedStack stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	stack.show();
}