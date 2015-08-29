#include <iostream>
using namespace std;

//typedef int Data;
//
//class List
//{
//private:
//	Data data;
//	List *NextNode, *Head, *Tail, *cur;
//public:
//	List();
//	void AddTailNode(List *list, Data data);
//	void InsertNode(List *list, Data data, int index);
//	void DeleteNode(List *list, int index);
//	void PrintNode(List *list);
//};

template <typename T>
class List
{
private:
	T data;
	int size;
	List<T> *NextNode, *Head, *Tail, *cur;
public:
	List();
	List(const T& data);
	List(const T& data, List<T> *list);
	void AddTailNode(List<T> *list, T data);
	void AddHeadNode(List<T> *list, T data);
	void InsertNode(List<T> *list, T data, int index);
	void DeleteNode(List<T> *list, int index);
	void DeleteAllNode(List<T> *list);
	void PrintNode(List<T> *list);
	T GetNode(List<T> *list, int index);
};

template <typename T>
List<T>::List() : size(0), data(0)	{	NextNode = Head = Tail = cur = NULL;	}
template <typename T>
List<T>::List(const T& data)
{
	this->data = data;
}
template <typename T>
List<T>::List(const T& data, List<T> *list)
{
	this->data = data;
	this->NextNode = list;
}
template <typename T>
void List<T>::AddTailNode(List<T> *list, T data)
{
	list = new List;
	list->data = data;
	list->NextNode = NULL;

	if (Head == NULL)
		Head = list;
	else
		Tail->NextNode = list;

	Tail = list;
	size++;
}
template <typename T>
void List<T>::AddHeadNode(List<T> *list, T data)
{
	list = new List(data, Head);
	/*list->data = data;
	list->NextNode = Head;*/

	Head = list;
	size++;
}
template <typename T>
void List<T>::InsertNode(List<T> *list, T data, int index)
{
	if (index > size)
	{
		cout << "index가 size를 초과했습니다!" << endl;
		return;
	}
	cur = Head;

	for (int i = 0; i < index - 1; i++)
		cur = cur->NextNode;

	list = new List;
	list->data = data;
	list->NextNode = cur->NextNode;
	cur->NextNode = list;
	size++;
}
template <typename T>
void List<T>::DeleteNode(List<T> *list, int index)
{
	if (Head == NULL || index > size)
	{
		cout << "저장된 노드가 존재하지 않습니다!" << endl;
		return;
	}

	List *Delete = new List;
	cur = Head;

	for (int i = 0; i < index - 1; i++)
		cur = cur->NextNode;

	Delete = cur->NextNode;
	cur->NextNode = Delete->NextNode;
	size--;

	delete Delete;
}
template <typename T>
void List<T>::DeleteAllNode(List<T> *list)
{
	if (Head == NULL)
	{
		cout << "저장된 노드가 존재하지 않습니다!" << endl;
		return;
	}

	while (Head->NextNode != NULL)
	{
		List<T> *Delete = Head;
		Head = Delete->NextNode;

		delete Delete;
		size--;
	}
	delete Head;
	Head = NULL;
}
template <typename T>
void List<T>::PrintNode(List<T> *list)
{
	if (Head == NULL)
	{
		cout << "저장된 노드가 존재하지 않습니다!" << endl;
		return;
	}

	cur = Head;

	cout << cur->data << " ";

	while (cur->NextNode != NULL)
	{
		cur = cur->NextNode;
		cout << cur->data << " ";
	}
	cout << endl;
}
template <typename T>
T List<T>::GetNode(List<T> *list, int index)
{
	if (index > size)
	{
		cout << "index가 size를 초과했습니다!" << endl;
		return -1;
	}

	cur = Head;

	for (int i = 0; i < index - 1; i++)
		cur = cur->NextNode;

	return cur->data;
}

int main()
{
	List<int> int_list;
	List<double> double_list;
	List<char> char_list;
	
	int_list.AddTailNode(&int_list, 1);
	int_list.AddTailNode(&int_list, 2);
	int_list.AddTailNode(&int_list, 3);
	int_list.AddTailNode(&int_list, 4);
	int_list.AddTailNode(&int_list, 5);
	int_list.AddHeadNode(&int_list, 11);
	int_list.AddHeadNode(&int_list, 12);
	int_list.AddHeadNode(&int_list, 13);
	int_list.AddHeadNode(&int_list, 14);
	int_list.AddHeadNode(&int_list, 15);
	cout << int_list.GetNode(&int_list, 2) << endl;
	int_list.PrintNode(&int_list);
	int_list.InsertNode(&int_list, 6, 2);
	int_list.PrintNode(&int_list);
	int_list.DeleteNode(&int_list, 2);
	int_list.PrintNode(&int_list);
	int_list.DeleteAllNode(&int_list);
	int_list.PrintNode(&int_list);

	double_list.AddTailNode(&double_list, 1.1);
	double_list.AddTailNode(&double_list, 2.2);
	double_list.AddTailNode(&double_list, 3.3);
	double_list.AddTailNode(&double_list, 4.4);
	double_list.AddTailNode(&double_list, 5.5);
	cout << double_list.GetNode(&double_list, 2) << endl;
	double_list.PrintNode(&double_list);
	double_list.InsertNode(&double_list, 6.6, 3);
	double_list.PrintNode(&double_list);
	double_list.DeleteNode(&double_list, 2);
	double_list.PrintNode(&double_list);
	double_list.DeleteAllNode(&double_list);
	double_list.PrintNode(&double_list);

	char_list.AddTailNode(&char_list, 'A');
	char_list.AddTailNode(&char_list, 'B');
	char_list.AddTailNode(&char_list, 'C');
	char_list.AddTailNode(&char_list, 'D');
	char_list.AddTailNode(&char_list, 'E');
	cout << char_list.GetNode(&char_list, 2) << endl;
	char_list.PrintNode(&char_list);
	char_list.InsertNode(&char_list, 'F', 4);
	char_list.PrintNode(&char_list);
	char_list.DeleteNode(&char_list, 2);
	char_list.PrintNode(&char_list);
	char_list.DeleteAllNode(&char_list);
	char_list.PrintNode(&char_list);
}