#include "Circular_Linked_List.h"

template <typename T>
Circular_List<T>::Circular_List() : data(0), Tail(NULL), cur(NULL)	{}
template <typename T>
void Circular_List<T>::AddTailCList(Circular_List<T> *list, T data)
{
	list = new Circular_List;
	list->data = data;
	list->NextNode = NULL;

	if (Tail == NULL)
	{
		Tail = list;
		Tail->NextNode = list;
	}
	else
	{
		list->NextNode = Tail->NextNode;
		Tail->NextNode = list;
	}
	Tail = list;
}
template <typename T>
void Circular_List<T>::AddHeadCList(Circular_List<T> *list, T data)
{
	list = new Circular_List;
	list->data = data;
	list->NextNode = NULL;

	if (Tail == NULL)
	{
		Tail = list;
		Tail->NextNode = list;
	}
	else
	{
		list->NextNode = Tail->NextNode;
		Tail->NextNode = list;
	}
}
template <typename T>
void Circular_List<T>::PrintCList(Circular_List<T> *list)
{
	cur = Tail->NextNode;

	while (1)
	{
		if (Tail == cur)
			break;
		cout << cur->data << " ";
		cur = cur->NextNode;
	}
	cout << cur->data;
	cout << endl;
}