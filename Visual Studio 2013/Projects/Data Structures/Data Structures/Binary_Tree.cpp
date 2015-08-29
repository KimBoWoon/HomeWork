#include <iostream>
using namespace std;

template <typename T>
class BinaryTree
{
private:
	T data;
	BinaryTree<T> *Left, *Right, *cur;
public:
	BinaryTree();
	BinaryTree(T data);

	void AddLeftSubtree(BinaryTree<T> *root, BinaryTree<T> *sub);
	void AddRighrSubtree(BinaryTree<T> *root, BinaryTree<T> *sub);

	BinaryTree<T>* GetLeftSubtree(BinaryTree<T> *root);
	BinaryTree<T>* GetRightSubtree(BinaryTree<T> *root);

	void LeftNodePrint(BinaryTree<T> *root);
	void RightNodePrint(BinaryTree<T> *root);

	void Preorder(BinaryTree<T> *root);
	void Inorder(BinaryTree<T> *root);
	void Postorder(BinaryTree<T> *root);

	void VisitNode(BinaryTree<T> *root);
};
template <typename T>
BinaryTree<T>::BinaryTree() : data(0), Left(NULL), Right(NULL), cur(NULL)	{}
template <typename T>
BinaryTree<T>::BinaryTree(T data) : data(data), Left(NULL), Right(NULL), cur(NULL)	{}
template <typename T>
void BinaryTree<T>::AddLeftSubtree(BinaryTree<T> *root, BinaryTree<T> *sub)
{
	if (root->Left == NULL)
		root->Left = sub;
	else
		throw "Left Node에 이미 자식이 존재합니다!";
}
template <typename T>
void BinaryTree<T>::AddRighrSubtree(BinaryTree<T> *root, BinaryTree<T> *sub)
{
	if (root->Right == NULL)
		root->Right = sub;
	else
		throw "Right Node에 이미 자식이 존재합니다!";
}
template <typename T>
BinaryTree<T>* BinaryTree<T>::GetLeftSubtree(BinaryTree<T> *root)	{ return root->Left; }
template <typename T>
BinaryTree<T>* BinaryTree<T>::GetRightSubtree(BinaryTree<T> *root)	{ return root->Right; }
template <typename T>
void BinaryTree<T>::LeftNodePrint(BinaryTree<T> *root)	{	cout << root->Left->data << endl;	}
template <typename T>
void BinaryTree<T>::RightNodePrint(BinaryTree<T> *root)	{	cout << root->Right->data << endl;	}
template <typename T>
void BinaryTree<T>::Preorder(BinaryTree<T> *root)
{
	if (root == NULL)
		return;

	VisitNode(root);
	Preorder(root->Left);
	Preorder(root->Right);
}
template <typename T>
void BinaryTree<T>::Inorder(BinaryTree<T> *root)
{
	if (root == NULL)
		return;

	Inorder(root->Left);
	VisitNode(root);
	Inorder(root->Right);
}
template <typename T>
void BinaryTree<T>::Postorder(BinaryTree<T> *root)
{
	if (root == NULL)
		return;

	Postorder(root->Left);
	Postorder(root->Right);
	VisitNode(root);
}
template <typename T>
void BinaryTree<T>::VisitNode(BinaryTree<T> *root)
{
	cout << root->data << " ";
}

int main()
{
	BinaryTree<char> BT('R'), n1('A'), n2('B'), n3('C'), n4('D'), n5('E'), n6('F'), n7('G'), n8('H');

	try
	{
		BT.AddLeftSubtree(&BT, &n1);
		BT.AddRighrSubtree(&BT, &n2);
		BT.AddLeftSubtree(&n1, &n3);
		BT.AddRighrSubtree(&n1, &n4);
		BT.AddLeftSubtree(&n2, &n5);
		BT.AddRighrSubtree(&n2, &n6);
		BT.AddLeftSubtree(&n3, &n7);
		BT.AddRighrSubtree(&n3, &n8);
		cout << "Preorder" << endl;
		BT.Preorder(&BT);
		cout << endl << "Inorder" << endl;
		BT.Inorder(&BT);
		cout << endl << "Postorder" << endl;
		BT.Postorder(&BT);
		cout << endl;
	}
	catch (const char *s)
	{
		cout << s << endl;
	}
}