#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template <typename T>
class Vector
{
private:
	T* arr;
	int len;
public:
	Vector();
	Vector(int size);
	~Vector();
	void resize(int i);
	size_t size();
	T& operator[] (int i);
	T operator[] (int i) const;
};

template <typename T>
Vector<T>::Vector() : arr(NULL), len(0)	{}
template <typename T>
Vector<T>::Vector(int size) : len(size)
{
	arr=new T[len];
	memset(arr, 0, len*sizeof(T));
}
template <typename T>
Vector<T>::~Vector()
{
	if(arr!=NULL)
		delete []arr;
	arr=NULL;
}
template <typename T>
void Vector<T>::resize(int size)
{
	Vector v(len);
	for(int i=0;i<len;i++)
		v.arr[i]=arr[i];
	if(arr!=NULL)
		delete []arr;
	arr=NULL;
	len=size;
	arr=new T[len];
	memset(arr, 0, len*sizeof(T));
	for(int i=0;i<v.len;i++)
		arr[i]=v.arr[i];
}
template <typename T>
size_t Vector<T>::size()	{	return len;	}
template <typename T>
T& Vector<T>::operator[] (int i)
{
	if(i<0 || i>len-1)
	{
		cout<<"肋给等 立辟!"<<endl;
		exit(1);
	}
	return arr[i];
}
template <typename T>
T Vector<T>::operator[] (int i) const
{
	if(i<0 || i>len-1)
	{
		cout<<"肋给等 立辟!"<<endl;
		exit(1);
	}
	return arr[i];
}

void main()
{
	Vector<int> arr1(10);
	Vector<double> arr2(5);
	Vector<char> arr3;

	for(size_t i=0;i<arr2.size();i++)
		arr2[i]=i+0.5;
	for(size_t i=0;i<arr2.size();i++)
		cout<<arr2[i]<<" ";
	cout<<endl;
	arr2.resize(10);
	for(size_t i=0;i<arr2.size();i++)
		cout<<arr2[i]<<" ";
	cout<<endl;

	arr3.resize(26);

	for(size_t i=0;i<arr1.size();i++)
		arr1[i]=i;
	for(size_t i=0;i<arr2.size();i++)
		arr2[i]=i+0.5;
	for(size_t i=0;i<arr3.size();i++)
		arr3[i]=i+65;

	for(size_t i=0;i<arr1.size();i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
	for(size_t i=0;i<arr2.size();i++)
		cout<<arr2[i]<<" ";
	cout<<endl;
	for(size_t i=0;i<arr3.size();i++)
		cout<<arr3[i]<<" ";

	cout<<endl;
}