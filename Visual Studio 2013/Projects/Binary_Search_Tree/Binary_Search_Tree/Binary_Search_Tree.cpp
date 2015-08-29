// HW 2 : Binary Search Tree
// Name : Kim Bo Woon
// Student ID : 20113259
#include "Binary_Search_Tree.h"

template <class T>
bool BinaryST<T>::Insert(T item)
{
	cnt = 0;

	if (root == NULL)
	{
		root = new BSTNode<T>(item);
		return true;
	}
	else
	{
		BSTNode<T> *temp = root;

		while (true)
		{
			if (item.key > temp->data.key)
			{
				if (temp->rC == NULL)
				{
					temp->rC = new BSTNode<T>(item);
					return true;
				}
				else
					temp = temp->rC;
			}
			else if (item.key < temp->data.key)
			{
				if (temp->lC == NULL)
				{
					temp->lC = new BSTNode<T>(item);
					return true;
				}
				else
					temp = temp->lC;
			}
			else if (item.key == temp->data.key)
			{
				temp->data.val = item.val;
				return false;
			}
		}
	}
}

template <class T>
T BinaryST<T>::Get(T item)
{
	BSTNode<T> *temp = root;

	cnt = 0;
	while (true)
	{
		if (item.key > temp->data.key)
		{
			if (temp->rC == NULL)
				return T(-1);
			else
				temp = temp->rC;
		}
		else if (item.key < temp->data.key)
		{
			if (temp->lC == NULL)
				return T(-1);
			else
				temp = temp->lC;
		}
		else if (item.key == temp->data.key)
			return temp->data;
		else
			return T(-1);
	}
}


template <class T>
bool  BinaryST<T>::Delete(T item)
{
	BSTNode<T> *temp = root;
	BSTNode<T> *parent = root;

	cnt = 0;

	while (true)
	{
		if (root == NULL)
			return false;
		else if (item.key > temp->data.key)
		{
			if (temp->rC == NULL)
				return false;
			else
			{
				parent = temp;
				temp = temp->rC;
			}
		}
		else if (item.key < temp->data.key)
		{
			if (temp->lC == NULL)
				return false;
			else
			{
				parent = temp;
				temp = temp->lC;
			}
		}
		else if (item.key == temp->data.key)
			break;
	}
	if (root->data.key == temp->data.key)
	{
		if (root->lC == NULL && root->rC == NULL)
		{
			delete root;
			root = NULL;
		}
		else if (root->lC != NULL && root->rC == NULL)
		{
			root = root->lC;
			delete temp;
			temp = NULL;
		}
		else if (root->lC == NULL && root->rC != NULL)
		{
			root = root->rC;
			delete temp;
			temp = NULL;
		}
		else if (root->lC != NULL && root->rC != NULL)
		{
			BSTNode<T> *DN = temp->rC;
			parent = temp;

			while (true)
			{
				if (DN->lC != NULL)
				{
					parent = DN;
					DN = DN->lC;
				}
				else
					break;
			}
			temp->data = DN->data;
			if (DN->rC == NULL)
			{
				delete temp->rC->lC;
				temp->rC->lC = NULL;
			}
			else if (DN->rC != NULL)
			{
				DN->data = DN->rC->data;
				delete DN->rC;
				DN->rC = NULL;
			}
		}
	}
	else if (temp->lC == NULL && temp->rC == NULL)
	{
		if (item.key == parent->lC->data.key)
		{
			delete parent->lC;
			parent->lC = NULL;
		}
		else if (item.key == parent->rC->data.key)
		{
			delete parent->rC;
			parent->rC = NULL;
		}
	}
	else if (temp->lC != NULL && temp->rC == NULL)
	{
		if (parent == root)
		{
			parent->rC = temp->lC;
			delete temp;
			temp = NULL;
		}
		else if (temp->data.key < root->data.key)
		{
			parent->rC = temp->lC;
			delete temp;
			temp = NULL;
		}
		else if (temp->data.key > root->data.key)
		{
			parent->lC = temp->lC;
			delete temp;
			temp = NULL;
		}
	}
	else if (temp->lC == NULL && temp->rC != NULL)
	{
		if (parent == root)
		{
			parent->lC = temp->rC;
			delete temp;
			temp = NULL;
		}
		else if (temp->data.key < root->data.key)
		{
			parent->rC = temp->rC;
			delete temp;
			temp = NULL;
		}
		else if (temp->data.key > root->data.key)
		{
			parent->lC = temp->rC;
			delete temp;
			temp = NULL;
		}
	}
	else if (temp->lC != NULL && temp->rC != NULL)
	{
		BSTNode<T> *DN = temp->rC;
		parent = temp;

		while (true)
		{
			if (DN->lC != NULL)
			{
				parent = DN;
				DN = DN->lC;
			}
			else
				break;
		}
		temp->data = DN->data;
		if (DN->rC == NULL)
		{
			delete temp->rC->lC;
			temp->rC->lC = NULL;
		}
		else if (DN->rC != NULL)
		{
			DN->data = DN->rC->data;
			delete DN->rC;
			DN->rC = NULL;
		}
	}
	return true;
}

template <class T>
void  BinaryST<T>::PreOrder(BSTNode<T> *ptr)
{
	if (ptr == NULL)
		return;

	cout << ptr->data.key << "(" << ptr->data.val << ")" << " ";
	PreOrder(ptr->lC);
	PreOrder(ptr->rC);
}

template <class T>
void  BinaryST<T>::InOrder(BSTNode<T> *ptr)
{
	if (ptr == NULL)
		return;

	InOrder(ptr->lC);
	cout << ptr->data.key << "(" << ptr->data.val << ")" << " ";
	InOrder(ptr->rC);
}

template <class T>
void  BinaryST<T>::PostOrder(BSTNode<T> *ptr)
{
	if (ptr == NULL)
		return;

	PostOrder(ptr->lC);
	PostOrder(ptr->rC);
	cout << ptr->data.key << "(" << ptr->data.val << ")" << " ";
}

template <class T>
int  BinaryST<T>::Count(BSTNode<T> *ptr)
{
	if (ptr == NULL)
		return cnt;

	Count(ptr->lC);
	Count(ptr->rC);
	cnt++;

	return cnt;
}

template <class T>
int  BinaryST<T>::Height(BSTNode<T> *ptr)
{
	int leftheight = 0, rightheight = 0;

	if (ptr == NULL)
		return 0;

	leftheight = Height(ptr->lC);
	rightheight = Height(ptr->rC);

	if (leftheight > rightheight)
		return leftheight + 1;
	else
		return rightheight + 1;
}