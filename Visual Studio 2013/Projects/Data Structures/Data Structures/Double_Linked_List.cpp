#include <iostream>
using namespace std;

typedef int Data;

class DoubleLL
{
private:
	Data data;
	DoubleLL *HeadNextNode, *TailNextNode, *Head, *Tail, *cur;
public:
	DoubleLL();
	void AddHeadDList(DoubleLL *list, Data data);
	void AddTailDList(DoubleLL *list, Data data);
	void DeleteNode(DoubleLL *list, int index);
	void InsertNode(DoubleLL *list, Data data, int index);
	void Print(DoubleLL *list);
	void RPrint(DoubleLL *list);
};
DoubleLL::DoubleLL() : data(0), HeadNextNode(NULL), Head(NULL), Tail(NULL), cur(NULL)	{}
void DoubleLL::AddHeadDList(DoubleLL *list, Data data)
{
	list = new DoubleLL;
	list->data = data;
	list->HeadNextNode = Head;

	if (Head == NULL)
		Tail = list;
	else
		Head->TailNextNode = list;
	Head = list;
}
void DoubleLL::AddTailDList(DoubleLL *list, Data data)
{
	list = new DoubleLL;
	list->data = data;
	list->TailNextNode = NULL;

	if (Head == NULL)
		Head = list;
	else
	{
		Tail->HeadNextNode = list;
		list->TailNextNode = Tail;
	}
	Tail = list;
}
void DoubleLL::DeleteNode(DoubleLL *list, int index)
{
	DoubleLL *DN = Head;

	for (int i = 0; i < index; i++)
	{
		if (DN == NULL)
			throw "노드가 존재 하지않습니다!";
		DN = DN->HeadNextNode;
	}

	DN->TailNextNode->HeadNextNode = DN->HeadNextNode;
	DN->HeadNextNode->TailNextNode = DN->TailNextNode;

	delete DN;
}
void DoubleLL::InsertNode(DoubleLL *list, Data data, int index)
{
	cur = Head;
	list = new DoubleLL;
	list->data = data;
	list->TailNextNode = NULL;
	list->HeadNextNode = NULL;

	for (int i = 0; i < index; i++)
	{
		if (cur == NULL)
			throw "노드가 존재 하지않습니다!";
		cur = cur->HeadNextNode;
	}

	list->HeadNextNode = cur->HeadNextNode;
	list->TailNextNode = cur;

	cur->HeadNextNode = list;
	list->HeadNextNode->TailNextNode = list;
}
void DoubleLL::Print(DoubleLL *list)
{
	cur = Head;
	cout << cur->data << " ";
	while (cur->HeadNextNode != NULL)
	{
		cur = cur->HeadNextNode;
		cout << cur->data << " ";
	}
	cout << endl;
}
void DoubleLL::RPrint(DoubleLL *list)
{
	cur = Tail;
	while (cur != Head)
	{
		cout << cur->data << " ";
		cur = cur->TailNextNode;
	}
	cout << cur->data << " ";
	cout << endl;
}

int main()
{
	DoubleLL list;

	list.AddHeadDList(&list, 1);
	list.AddHeadDList(&list, 2);
	list.AddHeadDList(&list, 3);
	list.AddHeadDList(&list, 4);
	list.AddHeadDList(&list, 5);
	list.AddTailDList(&list, 6);
	list.AddTailDList(&list, 7);
	list.AddTailDList(&list, 8);
	list.AddTailDList(&list, 9);
	list.AddTailDList(&list, 10);
	try
	{
		list.DeleteNode(&list, 2);
		list.InsertNode(&list, 11, 2);
		cout << "정방향 출력 : ";
		list.Print(&list);
		cout << "역방향 출력 : ";
		list.RPrint(&list);
	}
	catch (const char *s)
	{
		cout << s << endl;
	}
}