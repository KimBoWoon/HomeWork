#include "Define.h"
#include "AVLTree.h"

AVLTree::AVLTree() : root(NULL) {}
void AVLTree::insertNode(string key) {
	Node* cur = root;
	Node* newNode = new Node(key);
	Node* returnPoint[2] = { cur, cur };

	if (root == NULL)
		root = newNode;
	else {
		Node** p = serachNode(key, returnPoint);
		
		//���޹��� Ű���� �ڽ��� Ű������ ũ�� �����ʿ� �ڽ� ����
		if (p[1]->key < key)
			p[1]->right = newNode;
		//���޹��� Ű���� �ڽ��� Ű������ ������ ���ʿ� �ڽ� ����
		else if (p[1]->key > key)
			p[1]->left = newNode;
		//���� Ű���� ������ �������
		else if (p[1]->key == key)
			throw "�̹� ���Ե� Ű�Դϴ�!";
	}
	//����� �˰���
	rebalance(&newNode);
}
void AVLTree::deleteNode(string key) {
	Node* cur = root;
	Node* returnPoint[2] = { cur, cur };
	Node** DN = serachNode(key, returnPoint);

	if (DN[1]->key != key)
		throw "�������� �ʴ� Ű���Դϴ�!";

	//��Ʈ����� ����
	if (key == root->key) {
		//��Ʈ�� �ڽ��� �������
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//��Ʈ�� ���ʿ� �ڽ��� �������
		else if (root->left != NULL && root->right == NULL) {
			root = root->left;
			delete DN[0];
			DN[0] = NULL;
		}
		//��Ʈ�� �����ʿ� �ڽ��� �������
		else if (root->left == NULL && root->right != NULL) {
			root = root->right;
			delete DN[0];
			DN[0] = NULL;
		}
		//��Ʈ�� ���� ������ ��� �ڽ��� �������
		else {
			string changeKey;
			Node* cur = root;
			Node* serachPoint[2] = { cur, cur };
			Node** point = serachNode(key, serachPoint);
			int leftHeight = height(point[1]->left);
			int rightHeight = height(point[1]->right);
			int leftNodeCount = nodeCount(point[1]->left);
			int rightNodeCount = nodeCount(point[1]->right);

			//���̰� ������
			if (leftHeight > rightHeight)
				changeKey = maxNode(point[1]->left);
			else if (leftHeight < rightHeight)
				changeKey = minNode(point[1]->right);
			//����� ������ ���� ��
			else if (leftNodeCount > rightNodeCount)
				changeKey = maxNode(point[1]->left);
			else if (leftNodeCount < rightNodeCount)
				changeKey = minNode(point[1]->right);
			//�Ѵ� ������ ���ʿ��� �����´�
			else
				changeKey = maxNode(point[1]->left);

			//��ȯ�ϴ� ��带 �����
			deleteNode(changeKey);
			//Ű���� ��ȯ�Ѵ�
			DN[1]->key = changeKey;
		}
	}
	//�����Ϸ��� ����� �ڽ��� �������
	else if (DN[1]->left == NULL && DN[1]->right == NULL) {
		delete DN[1];
		//��۸� �����͸� ���Ѵ�
		if (key < DN[0]->key)
			DN[0]->left = NULL;
		else if (key > DN[0]->key)
			DN[0]->right = NULL;
	}
	//�����Ϸ��� ����� ���ʿ� �ڽ��� �������
	else if (DN[1]->left != NULL && DN[1]->right == NULL) {
		//Ű���� �θ��� Ű������ ũ�� ���� �ڽ��� �θ��� �����ʿ� �����Ѵ�
		if (key > DN[0]->key) {
			DN[0]->right = DN[1]->left;
			delete DN[1];
			DN[1] = NULL;
		}
		//Ű���� �θ��� Ű������ ũ�� ���� �ڽ��� �θ��� ���ʿ� �����Ѵ�
		else if (key < DN[0]->key) {
			DN[0]->left = DN[1]->left;
			delete DN[1];
			DN[1] = NULL;
		}
	}
	//�����Ϸ��� ����� �����ʿ� �ڽ��� �������
	else if (DN[1]->left == NULL && DN[1]->right != NULL) {
		//Ű���� �θ��� Ű������ ũ�� ������ �ڽ��� �θ��� �����ʿ� �����Ѵ�
		if (key > DN[0]->key) {
			DN[0]->right = DN[1]->right;
			delete DN[1];
			DN[1] = NULL;
		}
		//Ű���� �θ��� Ű������ ũ�� ������ �ڽ��� �θ��� ���ʿ� �����Ѵ�
		else if (key < DN[0]->key) {
			DN[0]->left = DN[1]->right;
			delete DN[1];
			DN[1] = NULL;
		}
	}
	//�����Ϸ��� ����� ���� ������ �ڽ��� �ִ°��
	else if (DN[1]->left != NULL && DN[1]->right != NULL) {
		string changeKey;
		Node* cur = root;
		Node* serachPoint[2] = { cur, cur };
		Node** point = serachNode(key, serachPoint);
		int leftHeight = height(point[1]->left);
		int rightHeight = height(point[1]->right);
		int leftNodeCount = nodeCount(point[1]->left);
		int rightNodeCount = nodeCount(point[1]->right);

		//���̰� ������
		if (leftHeight > rightHeight)
			changeKey = maxNode(point[1]->left);
		else if (leftHeight < rightHeight)
			changeKey = minNode(point[1]->right);
		//����� ������ ���� ��
		else if (leftNodeCount > rightNodeCount)
			changeKey = maxNode(point[1]->left);
		else if (leftNodeCount < rightNodeCount)
			changeKey = minNode(point[1]->right);
		//�Ѵ� ������ ���ʿ��� �����´�
		else
			changeKey = maxNode(point[1]->left);

		//��ȯ�ϴ� ��带 �����
		deleteNode(changeKey);
		//Ű���� ��ȯ�Ѵ�
		DN[1]->key = changeKey;
	}
	rebalance(&root);
}
Node** AVLTree::serachNode(string key, Node* returnPoint[2]) {
	if (root == NULL)
		throw "��Ʈ��尡 �������� �ʽ��ϴ�!";

	while (true) {
		//Ű���� ���޹��� Ű������ ������ �������� �̵�
		if (returnPoint[1]->key > key) {
			if (returnPoint[1]->left == NULL)
				return returnPoint;
			returnPoint[0] = returnPoint[1];
			returnPoint[1] = returnPoint[1]->left;
		}
		//Ű���� ���޹��� Ű������ ũ�� ���������� �̵�
		else if (returnPoint[1]->key < key) {
			if (returnPoint[1]->right == NULL)
				return returnPoint;
			returnPoint[0] = returnPoint[1];
			returnPoint[1] = returnPoint[1]->right;
		}
		//Ű���� ������ ��ȯ
		else if (returnPoint[1]->key == key)
			return returnPoint;
	}
}
void AVLTree::inorder(Node* root) {
	if (root == NULL)
		return;

	inorder(root->left);
	visitNode(root);
	inorder(root->right);
}
Node* AVLTree::getRoot() {
	return root;
}
void AVLTree::visitNode(Node* root) {
	cout << root->key << " ";
}
int AVLTree::height(Node* root) {
	int leftHeight = 0, rightHeight = 0;

	if (root == NULL)
		return 0;

	//���� ����
	leftHeight = height(root->left);
	rightHeight = height(root->right);

	//���� ���� ���̸� ��ȯ
	return (leftHeight > rightHeight) ? ++leftHeight : ++rightHeight;
}
int AVLTree::nodeCount(Node* root) {
	int count = 0;

	if (root == NULL)
		return 0;

	//�湮�ϴ� ��帶�� ī��Ʈ�� �����ش�
	count += nodeCount(root->left);
	count += nodeCount(root->right);

	return ++count;
}
string AVLTree::maxNode(Node* root) {
	Node* cur = root;

	while (cur->right != NULL)
		cur = cur->right;

	return cur->key;
}
string AVLTree::minNode(Node* root) {
	Node* cur = root;

	while (cur->left != NULL)
		cur = cur->left;

	return cur->key;
}
int AVLTree::getHeightDiff(Node* root)
{
	int leftHeight;
	int rightHeight;

	if (root == NULL)
		return 0;

	leftHeight = height(root->left);
	rightHeight = height(root->right);

	return leftHeight - rightHeight;
}
void AVLTree::rebalance(Node** rebalanceNode) {
	Node* cur = root;
	Node* returnPoint[2] = { cur, cur };
	Node** p = serachNode((*rebalanceNode)->key, returnPoint);
	int heightDiff = getHeightDiff(*rebalanceNode);

	if (root == NULL)
		throw "��Ʈ��尡 �������� �ʽ��ϴ�!";

	if (getHeightDiff(*rebalanceNode) > 1 || getHeightDiff(*rebalanceNode) < -1) {
		cout << "������� �ʿ���" << endl;
		//���� ����Ʈ���� �ұ����ϰ��
		if (heightDiff > 1) {
			//���� ����Ʈ���� ���� �ڽ��� ������ LLȸ��
			if (getHeightDiff((*rebalanceNode)->left) > 0) {
				cout << "LL ȸ��" << endl;
				LL(rebalanceNode);
				//��Ʈ��尡 ����Ǿ�����
				if (root == returnPoint[1])
					root = *rebalanceNode;
				//�θ��� ������ �ڽ����� �پ���� ���
				else if (returnPoint[0]->right->key == (*rebalanceNode)->key || 
					returnPoint[0]->right->key == (*rebalanceNode)->left->key || 
					returnPoint[0]->right->key == (*rebalanceNode)->right->key)
					returnPoint[0]->right = *rebalanceNode;
				//�θ��� ���� �ڽ����� �پ���� ���
				else
					returnPoint[0]->left = *rebalanceNode;
			}
			//���� ����Ʈ���� ������ �ڽ��� ������ LRȸ��
			else {
				cout << "LR ȸ��" << endl;
				LR(rebalanceNode);
				//��Ʈ��尡 ����Ǿ�����
				if (root == returnPoint[1])
					root = *rebalanceNode;
				//�θ��� ���� �ڽ����� �پ���� ���
				else if (returnPoint[0]->left->key == (*rebalanceNode)->key || 
					returnPoint[0]->left->key == (*rebalanceNode)->left->key || 
					returnPoint[0]->left->key == (*rebalanceNode)->right->key)
					returnPoint[0]->left = *rebalanceNode;
				//�θ��� ������ �ڽ����� �پ���� ���
				else
					returnPoint[0]->right = *rebalanceNode;
			}
		}
		//������ ����Ʈ���� �ұ����ϰ��
		else if (heightDiff < -1) {
			//������ ����Ʈ���� ������ �ڽ��� ������ RRȸ��
			if (getHeightDiff((*rebalanceNode)->right) < 0) {
				cout << "RR ȸ��" << endl;
				RR(rebalanceNode);
				//��Ʈ��尡 ����Ǿ�����
				if (root == returnPoint[1])
					root = *rebalanceNode;
				//�θ��� ������ �ڽ����� �پ���� ���
				else if (returnPoint[0]->right->key == (*rebalanceNode)->key || 
					returnPoint[0]->right->key == (*rebalanceNode)->left->key || 
					returnPoint[0]->right->key == (*rebalanceNode)->right->key)
					returnPoint[0]->right = *rebalanceNode;
				//�θ��� ���� �ڽ����� �پ���� ���
				else
					returnPoint[0]->left = *rebalanceNode;
			}
			//������ ����Ʈ���� ���� �ڽ��� ������ RLȸ��
			else {
				cout << "RL ȸ��" << endl;
				RL(rebalanceNode);
				//��Ʈ��尡 ����Ǿ�����
				if (root == returnPoint[1])
					root = *rebalanceNode;
				//�θ��� ���� �ڽ����� �پ���� ���
				else if (returnPoint[0]->left->key == (*rebalanceNode)->key || 
					returnPoint[0]->left->key == (*rebalanceNode)->left->key || 
					returnPoint[0]->left->key == (*rebalanceNode)->right->key)
					returnPoint[0]->left = *rebalanceNode;
				//�θ��� ������ �ڽ����� �پ���� ���
				else
					returnPoint[0]->right = *rebalanceNode;
			}
		}
	}
	else {
		//rebalanceNode�� ��Ʈ����� ������� �ʿ���� ����
		if (*rebalanceNode == root) {
			cout << "������� �ʿ����" << endl;
			return;
		}
		//�θ��带 �Ű������� �Ѱ��־� ���ȣ��
		rebalance(&returnPoint[0]);
	}
}
void AVLTree::LL(Node** root) {
	//�θ�� �ڽĳ�� ����
	Node* parent = *root;
	Node* child = (*root)->left;

	//��Ʈ�� ���� �ڽ����� �ٲٰ�
	*root = (*root)->left;
	//��Ʈ�� ������ �ڽ��� �θ��� ���� �ڽ����� �ִ´�
	parent->left = (*root)->right;
	//�θ� ��Ʈ�� ������ �ڽ����� �ִ´�
	(*root)->right = parent;
}
void AVLTree::RR(Node** root) {
	//�θ�� �ڽĳ�� ����
	Node* parent = *root;
	Node* child = (*root)->right;

	//��Ʈ�� ������ �ڽ����� �ٲٰ�
	*root = (*root)->right;
	//��Ʈ�� ���� �ڽ��� �θ��� ������ �ڽ����� �ִ´�
	parent->right = (*root)->left;
	//�θ� ��Ʈ�� ���� �ڽ����� �ִ´�
	(*root)->left = parent;
}
void AVLTree::LR(Node** root) {
	//�κ� RRȸ��
	RR(&(*root)->left);
	//LLȸ��
	LL(root);
}
void AVLTree::RL(Node** root) {
	//�κ� LLȸ��
	LL(&(*root)->right);
	//RRȸ��
	RR(root);
}