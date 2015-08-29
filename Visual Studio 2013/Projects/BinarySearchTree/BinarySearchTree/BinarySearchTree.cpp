#include <iostream>
#include <string>
using namespace std;

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

	void PreOrder(Node *root);
	void InOrder(Node *root);
	void PostOrder(Node *root);
	void VisitNode(Node *node);
	void Show();
};
BinarySearchTree::BinarySearchTree() : root(NULL)	{}
void BinarySearchTree::Insert(Item item)
{
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
	cout << endl;
}

int main()
{
	BinarySearchTree bst;
	// a binary search tree of type Item

	while (1) {
		cerr << "BST > ";
		string command;
		cin >> command;

		//	cout << command << " ";
		if (command.compare("quit") == 0) {
			break;
		}
		else if (command.compare("ins") == 0) {
			int key;
			string val;
			cin >> key >> val;
			bst.Insert(Item(key, val));
		}

		// show the current binary search tree
		bst.Show();
	}
	cerr << endl;

	return 1;
}