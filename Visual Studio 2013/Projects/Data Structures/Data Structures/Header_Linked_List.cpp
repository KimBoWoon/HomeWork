#include <iostream>
using namespace std;

typedef int Data;

class HeaderLList
{
private:
	Data data;
	HeaderLList *NextNode, *Head, *Tail, *cur;
public:
	HeaderLList();
	HeaderLList(Data data);
	HeaderLList(Data data, HeaderLList *list);

	void InitHL(HeaderLList *list);
	void AddTailNode(HeaderLList *list, Data data);
	void InsertNode(HeaderLList *list, Data data, int index);
	void DeleteNode(HeaderLList *list, Data index);
	void PrintNode(HeaderLList *list);
};
HeaderLList::HeaderLList() : data(0)	{}
HeaderLList::HeaderLList(Data data)
{
	this->data = data;
}
HeaderLList::HeaderLList(Data data, HeaderLList *list)
{
	this->data = data;
	this->NextNode = list;
}

void HeaderLList::InitHL(HeaderLList *list)
{
	list = new HeaderLList;
	list->data = -1;
	list->NextNode = NULL;
	Head = list;
	Tail = list;
}
void HeaderLList::AddTailNode(HeaderLList *list, Data data)
{
	list = new HeaderLList;
	list->data = data;
	list->NextNode = NULL;

	if (Head->NextNode == NULL)
		Head->NextNode = list;
	else
		Tail->NextNode = list;
	Tail = list;
}
void HeaderLList::InsertNode(HeaderLList *list, Data data, int index)
{
	list = new HeaderLList;
	list->data = data;
	list->NextNode = NULL;

	cur = Head;

	for (int i = 0; i < index; i++)
		cur = cur->NextNode;

	list->NextNode = cur->NextNode;
	cur->NextNode = list;
}
void HeaderLList::DeleteNode(HeaderLList *list, Data index)
{
	cur = Head;

	for (int i = 0; i < index; i++)
		cur = cur->NextNode;

	HeaderLList *DN = cur->NextNode;
	cur->NextNode = DN->NextNode;
	delete DN;
}
void HeaderLList::PrintNode(HeaderLList *list)
{
	cur = Head;
	//cout << cur->data << " ";
	while (cur->NextNode != NULL)
	{
		cur = cur->NextNode;
		cout << cur->data << " ";
	}
	cout << endl;
}

int main()
{
	HeaderLList list;

	list.InitHL(&list);
	list.AddTailNode(&list, 1);
	list.AddTailNode(&list, 2);
	list.AddTailNode(&list, 3);
	list.AddTailNode(&list, 4);
	list.AddTailNode(&list, 5);
	list.DeleteNode(&list, 2);
	list.InsertNode(&list, 6, 2);
	list.PrintNode(&list);
}