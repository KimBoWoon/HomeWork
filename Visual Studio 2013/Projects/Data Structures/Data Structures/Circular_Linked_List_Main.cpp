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

	while (cur->NextNode != NULL)
	{
		if (Tail == cur)
			break;
		cout << cur->data << " ";
		cur = cur->NextNode;
	}
	cout << cur->data;
	cout << endl;
}

int main()
{
	Circular_List<int> int_list;
	Circular_List<double> double_list;
	Circular_List<char> char_list;

	int_list.AddTailCList(&int_list, 1);
	int_list.AddTailCList(&int_list, 2);
	int_list.AddTailCList(&int_list, 3);
	int_list.AddTailCList(&int_list, 4);
	int_list.AddTailCList(&int_list, 5);
	int_list.AddHeadCList(&int_list, 6);
	int_list.AddHeadCList(&int_list, 7);
	int_list.AddHeadCList(&int_list, 8);
	int_list.AddHeadCList(&int_list, 9);
	int_list.AddHeadCList(&int_list, 10);
	int_list.PrintCList(&int_list);

	double_list.AddTailCList(&double_list, 1.1);
	double_list.AddTailCList(&double_list, 2.2);
	double_list.AddTailCList(&double_list, 3.3);
	double_list.AddTailCList(&double_list, 4.4);
	double_list.AddTailCList(&double_list, 5.5);
	double_list.AddHeadCList(&double_list, 6.6);
	double_list.AddHeadCList(&double_list, 7.7);
	double_list.AddHeadCList(&double_list, 8.8);
	double_list.AddHeadCList(&double_list, 9.9);
	double_list.AddHeadCList(&double_list, 10.10);
	double_list.PrintCList(&double_list);

	char_list.AddTailCList(&char_list, 'A');
	char_list.AddTailCList(&char_list, 'B');
	char_list.AddTailCList(&char_list, 'C');
	char_list.AddTailCList(&char_list, 'D');
	char_list.AddTailCList(&char_list, 'E');
	char_list.AddHeadCList(&char_list, 'F');
	char_list.AddHeadCList(&char_list, 'G');
	char_list.AddHeadCList(&char_list, 'H');
	char_list.AddHeadCList(&char_list, 'I');
	char_list.AddHeadCList(&char_list, 'J');
	char_list.PrintCList(&char_list);
}