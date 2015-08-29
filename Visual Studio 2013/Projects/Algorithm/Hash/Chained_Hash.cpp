#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Node
{
private:
	int key;
	int data;
	Node *NextNode;
public:
	friend class Table;

	Node(int k = 0, int d = 0);

	void SetKey(int k);
	void SetData(int d);
};
Node::Node(int k, int d) : key(k), data(d)	{}
void Node::SetKey(int k)	{ key = k; }
void Node::SetData(int d)	{ data = d; }
class Table
{
private:
	Node **table;
	int capacity;
public:
	friend class Node;

	Table(int capacity = 5);

	Node** GetTable();
	void SetTable(int k, int d);

	int HashFunc(int key);

	int Search(int k);

	void PrintTable();
};
Table::Table(int capacity)
{
	this->capacity = capacity;
	table = new Node*[capacity];
	memset(table, NULL, sizeof(int*) * capacity);
}

Node** Table::GetTable()	{ return table; }
void Table::SetTable(int k, int d)
{
	Node *n = new Node(k, d);

	if (table[HashFunc(n->key)] == NULL)
		table[HashFunc(n->key)] = n;
	else
	{
		cout << "Ãæµ¹" << endl;
		n->NextNode = table[HashFunc(n->key)];
		table[HashFunc(n->key)] = n;
	}
}

int Table::HashFunc(int key)	{ return key % capacity; }

int Table::Search(int k)
{
	Node *cur = new Node;

	for (int i = 0; i < capacity; i++)
	{
		cur = table[i];
		while (cur != NULL)
		{
			if (cur->key == k)
				return cur->data;
			else
				cur = cur->NextNode;
		}
	}
}

void Table::PrintTable()
{
	Node *cur = new Node;

	for (int i = 0; i < capacity; i++)
	{
		cur = table[i];
		cout << i << " ";
		while (cur != NULL)
		{
			cout << "k : " << cur->key << " " << "d : " << cur->data << " ";
			cur = cur->NextNode;
		}
		cout << endl;
	}
}

int main()
{
	Table t;
	string command;

	while (true)
	{
		cin >> command;

		if (command.compare("node") == 0)
		{
			int k, d;
			cin >> k >> d;
			t.SetTable(k, d);
		}
		else if (command.compare("search") == 0)
		{
			int k;
			cin >> k;
			cout << "Data : " << t.Search(k) << endl;
		}
		else if (command.compare("print") == 0)
			t.PrintTable();
		else if (command.compare("quit") == 0)
			break;
	}
}