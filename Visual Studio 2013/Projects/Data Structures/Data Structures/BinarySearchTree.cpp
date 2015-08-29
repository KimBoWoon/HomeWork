#include <iostream>
#include <string>
using namespace std;

int cnt = 0;

struct Item
{
	int key;
	string val;
	Item(int k, string v = 0)	{ key = k; val = v; };
	Item()	{};
};
class Node
{
private:
	Item data;
	Node *left, *right;
public:
	friend class BinarySearchTree;
	Node();
	Node(Item item);
};
Node::Node() : data(0), left(NULL), right(NULL)	{}
Node::Node(Item item) : data(item), left(NULL), right(NULL)	{}

class BinarySearchTree
{
private:
	Node *root;
public:
	BinarySearchTree();

	void Insert(Item item);

	int Count(Node *root);

	void PreOrder(Node *root);
	void InOrder(Node *root);
	void PostOrder(Node *root);
	void VisitNode(Node *node);
	void Show();
};
BinarySearchTree::BinarySearchTree() : root(NULL)	{}
void BinarySearchTree::Insert(Item item)
{
	cnt = 0;

	if (root == NULL)
		root = new Node(item);
	else
	{
		Node *temp = root;

		while (true)
		{
			if (item.key > temp->data.key)
			{
				if (temp->right == NULL)
				{
					temp->right = new Node(item);
					return;
				}
				else
					temp = temp->right;
			}
			else if (item.key < temp->data.key)
			{
				if (temp->left == NULL)
				{
					temp->left = new Node(item);
					return;
				}
				else
					temp = temp->left;
			}
		}
	}
}
int BinarySearchTree::Count(Node *root)
{
	if (root == NULL)
		return cnt;

	Count(root->left);
	Count(root->right);
	cnt++;

	return cnt;
}
void BinarySearchTree::PreOrder(Node *root)
{
	if (root == NULL)
		return;

	VisitNode(root);
	PreOrder(root->left);
	PreOrder(root->right);
}
void BinarySearchTree::InOrder(Node *root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	VisitNode(root);
	InOrder(root->right);
}
void BinarySearchTree::PostOrder(Node *root)
{
	if (root == NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	VisitNode(root);
}
void BinarySearchTree::VisitNode(Node *node)
{
	cout << node->data.key << "(" << node->data.val << ")" << " ";
}
void BinarySearchTree::Show()
{
	cout << "Pre  Order : ";
	PreOrder(root);
	cout << endl << "In   Order : ";
	InOrder(root);
	cout << endl << "Post Order : ";
	PostOrder(root);
	cout << endl << "Count : ";
	cout << Count(root) << endl;
}

int main()
{
	BinarySearchTree bst;

	while (1) {
		cerr << "BST > ";
		string command;
		cin >> command;

		if (command.compare("quit") == 0)
			break;
		else if (command.compare("ins") == 0) 
		{
			int key;
			string val;
			cin >> key >> val;
			bst.Insert(Item(key, val));
		}

		bst.Show();
	}
	cerr << endl;

	return 1;
}