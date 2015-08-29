#include <iostream>
using namespace std;

template <typename T>
class Circular_List
{
private:
	T data;
	Circular_List<T> *NextNode, *Tail, *cur;
public:
	Circular_List();
	void AddTailCList(Circular_List<T> *list, T data);
	void AddHeadCList(Circular_List<T> *list, T data);
	void PrintCList(Circular_List<T> *list);
};