#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

template <typename T>
class stack
{
public:
	friend ostream& operator<< (ostream& os, const stack<T> &s);

	stack();
	stack(long value);
	~stack();

	bool push(const T& pushvalue);
	bool pop(T& popvalue);
	bool peek(T& peekvalue) const;

	bool isempty() const;
	bool isfull()const;

private:
	T* elements;
	long size;
	long top;

	void setsize(long _size);
	long getsize();

	void allocatememory();
	const static long default_stack_size = 256;
};
template <class T>
stack<T>::stack()
{
	size = default_stack_size;
	allocatememory();
	top = -1;
}
template <typename T>
stack<T>::stack(long value)
{
	if (val < 0)
		value *= -1;
	else if (val == 0)
		value = defult_stack_size;

	size = value;
	allocatememory();
	top = -1;
}
template <typename T>
stack<T>::~stack()
{
	delete[] elements;
}

template <typename T>
bool stack<T>::push(const T& pushvalue)
{
	if (!isfull())
	{
		elements[++top] = pushvalue;
		return true;
	}
	else
		false;
}

template <typename T>
bool stack<T>::pop(T& popvalue)
{
	if (!isempty())
	{
		popvalue = elements[top--];
		return true;
	}
	else
		false;
}

template <typename T>
bool stack<T>::peek(T& peekvalue) const
{
	if (!isempty())
	{
		peekvalue = elements[top];
		return true;
	}
	else
		false;
}


template <typename T>
bool stack<T>::isempty() const
{
	return top < 0;
}
template <typename T>
bool stack<T>::isfull()const
{
	return top + 1 >= size;
}

template <typename T>
long stack<T>::getsize()
{
	return size;
}
template <typename T>
void stack<T>::setsize(long _size)
{
	size = _size;
}
template <typename T>
void stack<T>::allocatememory()
{
	elements = new T[size];

	if (elements == NULL)
	{
		cout << "stack memory allocation error" << endl;
		exit(1);
	}
}

template <typename T>
ostream& operator<< (ostream& os, const stack<T> &s)
{
	cout << "contents of stack: ";

	int t = s.top;
	while (t > -1)
		cout << s.elements[t--] << " ";
	cout << endl;

	return os;
}