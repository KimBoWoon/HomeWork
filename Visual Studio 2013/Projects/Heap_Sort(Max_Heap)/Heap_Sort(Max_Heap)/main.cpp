// Homework 3
// Name :
// Student ID :

#include "hw3.h"
//#include "lab.hpp"

template <class T>
void  HeapSort<T>::Adjust(const int root, int n)
{ // adjust binary tree with root "root" to satisfy heap property.
	// The left and right subtrees of "root" already satisfy the heap
	// property. No node index is > n.

	// cerr << "NEED TO IMPLEMENT" << endl;
	int child, rootkey;
	int temp;

	temp = heap[root];
	rootkey = heap[root];
	child = 2 * root;

	while (child <= n)
	{
		if ((child < n) && (heap[child] < heap[child + 1]))
			child++;
		if (rootkey > heap[child])
			break;
		else
		{
			heap[child / 2] = heap[child];
			child *= 2;
		}
	}
	heap[child / 2] = temp;
}

template <class T>
void  HeapSort<T>::Sort()
{ // sort heap[1:n] into nondecreasing order
	// cerr << "NEED TO IMPLEMENT" << endl;
	for (int i = heapSize / 2; i > 0; i--)
		Adjust(i, heapSize);
	ShowArray();
	for (int i = heapSize - 1; i > 0; i--)
	{
		int temp = heap[1];
		heap[1] = heap[i + 1];
		heap[i + 1] = temp;
		Adjust(1, i);
		ShowArray();
	}
}

int main()
{
	HeapSort<int> hsort(256);	// heap sort instance
	string command;

	while(1)
	{
		cerr << "HeapSort > ";
		cin >> command;

		if(command.compare("quit") == 0)
		{
			break;
		}
		else if(command.compare("init") == 0)
		{
			int intarr[1024];
			int i = 1;
			int item;
			while(1)
			{
				cin >> item;
				if(item == -1)
					break;
				intarr[i++] = item;
			}
			hsort.Init(intarr, i - 1);
		}
		else if(command.compare("sort") == 0)
		{
			hsort.Sort();
		}
		
		// show the array
		hsort.ShowArray();
	}
	cerr << endl;

	return 1;
}