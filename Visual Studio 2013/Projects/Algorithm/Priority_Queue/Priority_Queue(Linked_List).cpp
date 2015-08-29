#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	int data;
	Node *NextNode;
public:
	friend class LinkedQueue;
	Node();
	Node(int data);
};
Node::Node() : data(0), NextNode(NULL)	{}
Node::Node(int data) : data(data), NextNode(NULL)	{}
class LinkedQueue
{
private:
	Node *Head, *Tail;
	int size;
public:
	LinkedQueue();

	void enqueue(int data);
	void dequeue();

	void show() const;
};
LinkedQueue::LinkedQueue() : Head(NULL), size(0)	{}

void LinkedQueue::enqueue(int data)
{
	if (Head == NULL)
	{
		Head = new Node(data);
		Tail = Head;
	}
	else
	{
		Tail->NextNode = new Node(data);
		Tail = Tail->NextNode;
	}
	size++;
}
void LinkedQueue::dequeue()
{
	if (Head == NULL)
		throw "노드가 존재하지 않습니다!";

	size--;

	Node *DN = Head;

	Head = Head->NextNode;

	delete DN;
}
void LinkedQueue::show() const
{
	Node *cur = Head;

	cout << "Queue Size >> " << size << endl;
	cout << "Queue >> ";
	while (true)
	{
		if (cur != NULL)
			cout << cur->data << " ";
		else
			return;

		cur = cur->NextNode;
	}
}

void main()
{
	LinkedQueue LQ;
	string command;

	cout << "추가 : en, 제거 : de, 종료 : quit" << endl;

	while (true)
	{
		try
		{
			cin >> command;

			if (command.compare("en") == 0)
			{
				int data;
				cin >> data;
				LQ.enqueue(data);
			}
			else if (command.compare("de") == 0)
				LQ.dequeue();
			else if (command.compare("quit") == 0)
				return;

			LQ.show();
			cout << endl;
		}
		catch (const char *s)
		{
			cout << s << endl;
		}
	}
}