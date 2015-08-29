// Homework 3
// Name :
// Student ID :

#include<iostream>
#include<string>
using namespace std;

// ---------- Heap class -------------
template <class T>
class HeapSort
{
public :
	HeapSort(int theCapacity = 10);	// constructor

	void Init(const T *, int);
	void ShowArray();
	void  Adjust(const int root, const int n);
	void Sort();
private :
	T* heap; // array
	int heapSize;	// number of elements in heap
	int capacity;	// size of the array heap
};

template<class T>
HeapSort<T>::HeapSort(int theCapacity)
{ // HeapSort constructor. 
	capacity = theCapacity;
	heap = new T[capacity + 1];	// heap[0] is not used
	heapSize = 0;
}


template <class T>
void HeapSort<T>::ShowArray()
{ // Show all the element in the heap
	cout << "Heap : - ";

	// print all the nodes in the heap
	for(int i = 1; i <= heapSize; i++)
		cout << heap[i] << "  ";
	cout << endl;
}

template <class T>
void  HeapSort<T>::Init(const T *es, int n)
{	// fill the heap array by the input
	// we need to create heap structure when we call Sort()
	heapSize = n;
	for(int i = 1; i <= n; i++)
		heap[i] = es[i];
}


