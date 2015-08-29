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
		
		//전달받은 키값이 자식의 키값보다 크면 오른쪽에 자식 생성
		if (p[1]->key < key)
			p[1]->right = newNode;
		//전달받은 키값이 자식의 키값보다 작으면 왼쪽에 자식 생성
		else if (p[1]->key > key)
			p[1]->left = newNode;
		//같은 키값이 있으면 예외출력
		else if (p[1]->key == key)
			throw "이미 삽입된 키입니다!";
	}
	//재균형 알고리즘
	rebalance(&newNode);
}
void AVLTree::deleteNode(string key) {
	Node* cur = root;
	Node* returnPoint[2] = { cur, cur };
	Node** DN = serachNode(key, returnPoint);

	if (DN[1]->key != key)
		throw "존재하지 않는 키값입니다!";

	//루트노드의 제거
	if (key == root->key) {
		//루트의 자식이 없을경우
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//루트의 왼쪽에 자식이 있을경우
		else if (root->left != NULL && root->right == NULL) {
			root = root->left;
			delete DN[0];
			DN[0] = NULL;
		}
		//루트의 오른쪽에 자식이 있을경우
		else if (root->left == NULL && root->right != NULL) {
			root = root->right;
			delete DN[0];
			DN[0] = NULL;
		}
		//루트의 왼쪽 오른쪽 모두 자식이 있을경우
		else {
			string changeKey;
			Node* cur = root;
			Node* serachPoint[2] = { cur, cur };
			Node** point = serachNode(key, serachPoint);
			int leftHeight = height(point[1]->left);
			int rightHeight = height(point[1]->right);
			int leftNodeCount = nodeCount(point[1]->left);
			int rightNodeCount = nodeCount(point[1]->right);

			//깊이가 깊은쪽
			if (leftHeight > rightHeight)
				changeKey = maxNode(point[1]->left);
			else if (leftHeight < rightHeight)
				changeKey = minNode(point[1]->right);
			//노드의 갯수가 많은 쪽
			else if (leftNodeCount > rightNodeCount)
				changeKey = maxNode(point[1]->left);
			else if (leftNodeCount < rightNodeCount)
				changeKey = minNode(point[1]->right);
			//둘다 같으면 왼쪽에서 가져온다
			else
				changeKey = maxNode(point[1]->left);

			//교환하는 노드를 지우고
			deleteNode(changeKey);
			//키값을 교환한다
			DN[1]->key = changeKey;
		}
	}
	//삭제하려는 대상의 자식이 없을경우
	else if (DN[1]->left == NULL && DN[1]->right == NULL) {
		delete DN[1];
		//댕글링 포인터를 피한다
		if (key < DN[0]->key)
			DN[0]->left = NULL;
		else if (key > DN[0]->key)
			DN[0]->right = NULL;
	}
	//삭제하려는 대상의 왼쪽에 자식이 있을경우
	else if (DN[1]->left != NULL && DN[1]->right == NULL) {
		//키값이 부모의 키값보다 크면 왼쪽 자식을 부모의 오른쪽에 삽입한다
		if (key > DN[0]->key) {
			DN[0]->right = DN[1]->left;
			delete DN[1];
			DN[1] = NULL;
		}
		//키값이 부모의 키값보다 크면 왼쪽 자식을 부모의 왼쪽에 삽입한다
		else if (key < DN[0]->key) {
			DN[0]->left = DN[1]->left;
			delete DN[1];
			DN[1] = NULL;
		}
	}
	//삭제하려는 대상의 오른쪽에 자식이 있을경우
	else if (DN[1]->left == NULL && DN[1]->right != NULL) {
		//키값이 부모의 키값보다 크면 오른쪽 자식을 부모의 오른쪽에 삽입한다
		if (key > DN[0]->key) {
			DN[0]->right = DN[1]->right;
			delete DN[1];
			DN[1] = NULL;
		}
		//키값이 부모의 키값보다 크면 오른쪽 자식을 부모의 왼쪽에 삽입한다
		else if (key < DN[0]->key) {
			DN[0]->left = DN[1]->right;
			delete DN[1];
			DN[1] = NULL;
		}
	}
	//삭제하려는 대상의 왼쪽 오른쪽 자식이 있는경우
	else if (DN[1]->left != NULL && DN[1]->right != NULL) {
		string changeKey;
		Node* cur = root;
		Node* serachPoint[2] = { cur, cur };
		Node** point = serachNode(key, serachPoint);
		int leftHeight = height(point[1]->left);
		int rightHeight = height(point[1]->right);
		int leftNodeCount = nodeCount(point[1]->left);
		int rightNodeCount = nodeCount(point[1]->right);

		//깊이가 깊은쪽
		if (leftHeight > rightHeight)
			changeKey = maxNode(point[1]->left);
		else if (leftHeight < rightHeight)
			changeKey = minNode(point[1]->right);
		//노드의 갯수가 많은 쪽
		else if (leftNodeCount > rightNodeCount)
			changeKey = maxNode(point[1]->left);
		else if (leftNodeCount < rightNodeCount)
			changeKey = minNode(point[1]->right);
		//둘다 같으면 왼쪽에서 가져온다
		else
			changeKey = maxNode(point[1]->left);

		//교환하는 노드를 지우고
		deleteNode(changeKey);
		//키값을 교환한다
		DN[1]->key = changeKey;
	}
	rebalance(&root);
}
Node** AVLTree::serachNode(string key, Node* returnPoint[2]) {
	if (root == NULL)
		throw "루트노드가 존재하지 않습니다!";

	while (true) {
		//키값이 전달받은 키값보다 작으면 왼쪽으로 이동
		if (returnPoint[1]->key > key) {
			if (returnPoint[1]->left == NULL)
				return returnPoint;
			returnPoint[0] = returnPoint[1];
			returnPoint[1] = returnPoint[1]->left;
		}
		//키값이 전달받은 키값보다 크면 오른쪽으로 이동
		else if (returnPoint[1]->key < key) {
			if (returnPoint[1]->right == NULL)
				return returnPoint;
			returnPoint[0] = returnPoint[1];
			returnPoint[1] = returnPoint[1]->right;
		}
		//키값이 같으면 반환
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

	//높이 측정
	leftHeight = height(root->left);
	rightHeight = height(root->right);

	//제일 깊은 높이를 반환
	return (leftHeight > rightHeight) ? ++leftHeight : ++rightHeight;
}
int AVLTree::nodeCount(Node* root) {
	int count = 0;

	if (root == NULL)
		return 0;

	//방문하는 노드마다 카운트를 더해준다
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
		throw "루트노드가 존재하지 않습니다!";

	if (getHeightDiff(*rebalanceNode) > 1 || getHeightDiff(*rebalanceNode) < -1) {
		cout << "재균형이 필요함" << endl;
		//왼쪽 서브트리가 불균형일경우
		if (heightDiff > 1) {
			//왼쪽 서브트리의 왼쪽 자식이 있으면 LL회전
			if (getHeightDiff((*rebalanceNode)->left) > 0) {
				cout << "LL 회전" << endl;
				LL(rebalanceNode);
				//루트노드가 변경되었을때
				if (root == returnPoint[1])
					root = *rebalanceNode;
				//부모의 오른쪽 자식으로 붙어야할 경우
				else if (returnPoint[0]->right->key == (*rebalanceNode)->key || 
					returnPoint[0]->right->key == (*rebalanceNode)->left->key || 
					returnPoint[0]->right->key == (*rebalanceNode)->right->key)
					returnPoint[0]->right = *rebalanceNode;
				//부모의 왼쪽 자식으로 붙어야할 경우
				else
					returnPoint[0]->left = *rebalanceNode;
			}
			//왼쪽 서브트리의 오른쪽 자식이 있으면 LR회전
			else {
				cout << "LR 회전" << endl;
				LR(rebalanceNode);
				//루트노드가 변경되었을때
				if (root == returnPoint[1])
					root = *rebalanceNode;
				//부모의 왼쪽 자식으로 붙어야할 경우
				else if (returnPoint[0]->left->key == (*rebalanceNode)->key || 
					returnPoint[0]->left->key == (*rebalanceNode)->left->key || 
					returnPoint[0]->left->key == (*rebalanceNode)->right->key)
					returnPoint[0]->left = *rebalanceNode;
				//부모의 오른쪽 자식으로 붙어야할 경우
				else
					returnPoint[0]->right = *rebalanceNode;
			}
		}
		//오른쪽 서브트리가 불균형일경우
		else if (heightDiff < -1) {
			//오른쪽 서브트리의 오른쪽 자식이 있으면 RR회전
			if (getHeightDiff((*rebalanceNode)->right) < 0) {
				cout << "RR 회전" << endl;
				RR(rebalanceNode);
				//루트노드가 변경되었을때
				if (root == returnPoint[1])
					root = *rebalanceNode;
				//부모의 오른쪽 자식으로 붙어야할 경우
				else if (returnPoint[0]->right->key == (*rebalanceNode)->key || 
					returnPoint[0]->right->key == (*rebalanceNode)->left->key || 
					returnPoint[0]->right->key == (*rebalanceNode)->right->key)
					returnPoint[0]->right = *rebalanceNode;
				//부모의 왼쪽 자식으로 붙어야할 경우
				else
					returnPoint[0]->left = *rebalanceNode;
			}
			//오른쪽 서브트리의 왼쪽 자식이 있으면 RL회전
			else {
				cout << "RL 회전" << endl;
				RL(rebalanceNode);
				//루트노드가 변경되었을때
				if (root == returnPoint[1])
					root = *rebalanceNode;
				//부모의 왼쪽 자식으로 붙어야할 경우
				else if (returnPoint[0]->left->key == (*rebalanceNode)->key || 
					returnPoint[0]->left->key == (*rebalanceNode)->left->key || 
					returnPoint[0]->left->key == (*rebalanceNode)->right->key)
					returnPoint[0]->left = *rebalanceNode;
				//부모의 오른쪽 자식으로 붙어야할 경우
				else
					returnPoint[0]->right = *rebalanceNode;
			}
		}
	}
	else {
		//rebalanceNode가 루트노드라면 재균형이 필요없는 경우다
		if (*rebalanceNode == root) {
			cout << "재균형이 필요없음" << endl;
			return;
		}
		//부모노드를 매개변수로 넘겨주어 재귀호출
		rebalance(&returnPoint[0]);
	}
}
void AVLTree::LL(Node** root) {
	//부모와 자식노드 저장
	Node* parent = *root;
	Node* child = (*root)->left;

	//루트를 왼쪽 자식으로 바꾸고
	*root = (*root)->left;
	//루트의 오른쪽 자식을 부모의 왼쪽 자식으로 넣는다
	parent->left = (*root)->right;
	//부모를 루트의 오른쪽 자식으로 넣는다
	(*root)->right = parent;
}
void AVLTree::RR(Node** root) {
	//부모와 자식노드 저장
	Node* parent = *root;
	Node* child = (*root)->right;

	//루트를 오른쪽 자식으로 바꾸고
	*root = (*root)->right;
	//루트의 왼쪽 자식을 부모의 오른쪽 자식으로 넣는다
	parent->right = (*root)->left;
	//부모를 루트의 왼쪽 자식으로 넣는다
	(*root)->left = parent;
}
void AVLTree::LR(Node** root) {
	//부분 RR회전
	RR(&(*root)->left);
	//LL회전
	LL(root);
}
void AVLTree::RL(Node** root) {
	//부분 LL회전
	LL(&(*root)->right);
	//RR회전
	RR(root);
}