#include "BTree.h"

bool BTree::overflow(Node* node) {
	if (node->keyCount < SIZE - 1)
		return true;
	else
		return false;
}
void BTree::insertKey(Node* node, string key, Node* left, Node* right) {
	int i;
	//�������� �̿��� �ڿ��� ����
	for (i = node->keyCount; i > 0; i--) {
		//���޹��� Ű���� ����� Ű������ ũ�� ���� �ڿ� ����
		if (key > node->key[i - 1]) {
			node->key[i] = key;
			node->ptr[i] = left;
			node->ptr[i + 1] = right;
			node->keyCount++;
			return;
		}
		//�ƴϸ� Ű���� �ڷ� �о��
		else {
			node->key[i] = node->key[i - 1];
			node->ptr[i + 1] = node->ptr[i];
		}
	}
	//Ű�� ����
	node->key[i] = key;
	node->ptr[i] = left;
	node->ptr[i + 1] = right;
	node->keyCount++;
}
Node* BTree::insertNode(Node* node, string key, Node* left, Node* right) {
	if (overflow(node)) {
		insertKey(node, key, left, right);
		return root;
	}
	else {
		string middleKey;
		//��带 �ΰ��� �и��Ѵ�
		Node* splitNode = split(node);
		//�߰�Ű���� ��忡 �������� ���� ��
		if (key < node->key[node->keyCount - 1]) {
			middleKey = node->key[node->keyCount - 1];
			node->keyCount -= 1;
			insertKey(node, key, left, right);
		}
		//�߰�Ű���� ��忡 ù��° Ű�� ��
		else if (key > splitNode->key[0]) {
			int i;
			middleKey = splitNode->key[0];
			for (i = 0; i < splitNode->keyCount - 1; i++) {
				splitNode->key[i] = splitNode->key[i + 1];
				splitNode->key[i + 1] = "";
				splitNode->ptr[i] = splitNode->ptr[i + 1];
			}
			splitNode->ptr[i] = splitNode->ptr[i + 1];
			splitNode->keyCount -= 1;
			insertKey(splitNode, key, left, right);
		}
		//Ű���� �߰�Ű���� ��
		else {
			middleKey = key;
			node->ptr[node->keyCount] = left;
			splitNode->ptr[0] = right;
		}
		//�θ� ����
		setParent(node);
		setParent(splitNode);

		//�߰��� �÷������� �θ� ���°��
		if (node->parent == NULL) {
			Node* parent = new Node();
			insertKey(parent, middleKey, node, splitNode);
			setParent(parent);
			return parent;
		}
		//�θ� ���� ��
		else {
			//�и��� ��嵵 ����� �ڽ��̴�
			splitNode->parent = node->parent;
			return insertNode(node->parent, middleKey, node, splitNode);
		}
	}
}
bool BTree::underflow(Node* node) {
	if (node->keyCount < ceil((double)SIZE / (double)2) - 1)
		return true;
	else
		return false;
}
int BTree::findIndex(Node* node, string key) {
	if (node->parent != NULL) {
		for (int i = 0; i < node->parent->keyCount + 1; i++) {
			if (node->parent->ptr[i] == node)
				return i;
		}
	}
	else
		return findKey(node, key);
}
int BTree::findKey(Node* node, string key) {
	if (node->keyCount == 0)
		node->keyCount++;
	for (int i = 0; i < node->keyCount; i++) {
		if (node->key[i] == key)
			return i;
	}
	return -1;
}
int BTree::sibling(Node* node) {
	int index = findIndex(node);

	if (node->parent == NULL) {
		return -1;
	}
	else if ((node->parent->ptr[index - 1] != NULL || node->parent->ptr[index + 1] != NULL) && index > 0) {
		if (node->parent->ptr[index - 1]->keyCount > ceil((double)SIZE / (double)2) - 1)
			return index - 1;
	}
	else if (node->parent->ptr[index + 1] != NULL) {
		if (node->parent->ptr[index + 1]->keyCount > ceil((double)SIZE / (double)2) - 1)
			return index + 1;
	}
	return -1;
}
Node* BTree::keySearch(Node* root, string key) {
	int i = 0;
	Node* node = NULL;
	if (root != NULL) {
		if (root->key[i] == key)
			return root;
		else {
			for (i = 0; i < root->keyCount; i++) {
				node = keySearch(root->ptr[i], key);
				if (node != NULL)
					return node;
				if (root->key[i] == key)
					return root;
			}
			node = keySearch(root->ptr[i], key);
			if (node != NULL)
				return node;
		}
	}
	return node;
}
void BTree::redistribution(Node* node, int nodeIndex, int siblingIndex) {
	if (nodeIndex < siblingIndex) {
		node->key[node->keyCount++] = node->parent->key[nodeIndex];
		node->parent->key[nodeIndex] = node->parent->ptr[siblingIndex]->key[0];
	}
	else {
		node->parent->ptr[nodeIndex]->key[node->parent->ptr[nodeIndex]->keyCount++] = node->parent->key[nodeIndex - 1];
		node->parent->key[nodeIndex - 1] = node->parent->ptr[siblingIndex]->key[node->parent->ptr[siblingIndex]->keyCount - 1];
		node->parent->ptr[siblingIndex]->key[node->parent->ptr[siblingIndex]->keyCount - 1] = "";
		node->parent->ptr[siblingIndex]->keyCount--;
	}
}
void BTree::mergeNode(Node* node, int nodeIndex) {
	if (nodeIndex == 0) {
		node->key[node->keyCount++] = node->parent->key[nodeIndex];
		node->parent->keyCount--;
		for (int i = 0; i < node->parent->ptr[nodeIndex + 1]->keyCount; i++)
			node->key[node->keyCount++] = node->parent->ptr[nodeIndex + 1]->key[i];
		delete node->parent->ptr[nodeIndex + 1];
		node->parent->ptr[nodeIndex + 1] = NULL;
	}
	else {
		node->parent->ptr[nodeIndex - 1]->key[node->parent->ptr[nodeIndex - 1]->keyCount++] = node->parent->key[nodeIndex - 1];
		node->parent->keyCount--;
		for (int i = 0; i < node->parent->ptr[nodeIndex]->keyCount; i++)
			node->parent->ptr[nodeIndex - 1]->key[node->parent->ptr[nodeIndex - 1]->keyCount++] = node->parent->ptr[nodeIndex]->key[i];
		//delete node->parent->ptr[nodeIndex];
		node->parent->ptr[nodeIndex] = NULL;
	}
}
void BTree::deleteKey(Node* node, string key) {
	int keyIndex = findKey(node, key);

	node->key[keyIndex] = "";
	node->keyCount--;

	for (int i = keyIndex; i < node->keyCount; i++) {
		node->key[i] = node->key[i + 1];
		node->key[i + 1] = "";
	}
}
void BTree::deleteNode(Node* node, string key) {
	//Node* DN = keySearch(node, key);
	Node* cur = node;
	int i = 0, n = 0;

	do {
		n = cur->keyCount;
		i = 0;
		while (i < n && key > cur->key[i])
			i++;
		if (i <= cur->keyCount && key == cur->key[i])
			break;
	} while ((cur = cur->ptr[i]) != NULL);
	if (cur == NULL)
		cur = node;

	if (leafNode(cur)) {
		deleteKey(cur, key);

		if (underflow(cur)) {
			int siblingIndex = sibling(cur);
			int nodeIndex = findIndex(cur);

			if (siblingIndex == -1) {
				mergeNode(cur, nodeIndex);

				if (underflow(cur->parent))
					deleteNode(cur->parent);
				if (nodeIndex == 0) {
					delete cur->parent->ptr[nodeIndex + 1];
					cur->parent->ptr[nodeIndex + 1] = NULL;
				}
				else {
					if (cur->parent->key[cur->parent->keyCount] != "") {
						for (int i = 0; i < cur->parent->keyCount; i++) {
							cur->parent->key[i] = cur->parent->key[i + 1];
							cur->parent->key[i + 1] = "";
							cur->parent->ptr[cur->parent->keyCount + i] = cur->parent->ptr[cur->parent->keyCount + i + 1];
						}
					}
					//delete cur->parent->ptr[nodeIndex];
					cur->parent->ptr[nodeIndex] = NULL;
				}
			}
			else {
				redistribution(cur, nodeIndex, siblingIndex);
				if (underflow(cur->parent))
					deleteNode(cur->parent);
			}
		}
	}
	else {
		if (cur == root && cur->keyCount == 0) {
			for (int i = 0; i < SIZE; i++) {
				if (cur->ptr[i] != NULL) {
					setRoot(cur->ptr[i]);
					delete root->parent;
					root->parent = NULL;
					return;
				}
			}
		}
		else {
			if (key != "") {
				int keyIndex = findKey(cur, key);

				if (cur->ptr[keyIndex + 1] != NULL) {
					string tempKey = cur->key[keyIndex];
					cur->key[keyIndex] = cur->ptr[keyIndex + 1]->key[0];
					cur->ptr[keyIndex + 1]->key[0] = tempKey;
					deleteNode(cur->ptr[keyIndex + 1], tempKey);
				}
				else {
					if (keyIndex == 0) {
						string tempKey = cur->key[keyIndex];
						cur->key[keyIndex] = cur->ptr[keyIndex]->key[cur->ptr[keyIndex]->keyCount - 1];
						cur->ptr[keyIndex]->key[cur->ptr[keyIndex]->keyCount - 1] = tempKey;
						deleteNode(cur->ptr[keyIndex], tempKey);
					}
					else {
						string tempKey = cur->key[keyIndex];
						cur->key[keyIndex] = cur->ptr[keyIndex - 1]->key[cur->ptr[keyIndex]->keyCount - 1];
						cur->ptr[keyIndex - 1]->key[cur->ptr[keyIndex]->keyCount - 1] = tempKey;
						deleteNode(cur->ptr[keyIndex - 1], tempKey);
					}
				}
			}
			else {
				int siblingIndex = sibling(cur);
				int nodeIndex = findIndex(cur);

				if (siblingIndex == -1) {
					mergeNode(cur, nodeIndex);

					if (underflow(cur->parent))
						deleteNode(cur->parent);
					if (nodeIndex == 0) {
						delete cur->parent->ptr[nodeIndex + 1];
						cur->parent->ptr[nodeIndex + 1] = NULL;
					}
					else {
						if (cur->parent->key[cur->parent->keyCount] != "") {
							for (int i = 0; i < cur->parent->keyCount; i++) {
								cur->parent->key[i] = cur->parent->key[i + 1];
								cur->parent->ptr[cur->parent->keyCount + i] = cur->parent->ptr[cur->parent->keyCount + i + 1];
							}
						}
						delete cur->parent->ptr[nodeIndex];
						cur->parent->ptr[nodeIndex] = NULL;
					}
				}
				else {
					redistribution(cur, nodeIndex, siblingIndex);
					if (underflow(cur->parent))
						deleteNode(cur->parent);
				}
			}
		}
	}
}
void BTree::setParent(Node* node) {
	//NULL�� �ƴ� �ڽĳ����� �θ� �����Ѵ�
	for (int i = 0; i < node->keyCount + 1; i++) {
		if (node->ptr[i] != NULL)
			node->ptr[i]->parent = node;
	}
}
string BTree::middle(Node* node, string key) {
	string s[SIZE];
	//Ű���� string �迭�� ����
	for (int i = 0; i < SIZE - 1; i++)
		s[i] = node->key[i];
	s[SIZE - 1] = key;
	//����� �迭�� sorting
	sort(s, s + SIZE, less<string>());
	//�߰��� ����
	return s[SIZE / 2];
}
Node* BTree::split(Node* node) {
	Node* splitNode = NULL;
	//Ű�� ������ 2�̻��̸� ��带 �� ���� ���� �� �ִ�
	if (node->keyCount >= 2) {
		int i, j = 0;
		int size = node->keyCount;
		//���ο� ��� ����
		splitNode = new Node();
		for (i = (node->keyCount) / 2; i < node->keyCount; i++, j++) {
			//��带 ������ �۾�
			splitNode->key[j] = node->key[i];
			node->key[i] = "";
			splitNode->ptr[j] = node->ptr[i];
			size--;
			splitNode->keyCount += 1;
		}
		splitNode->ptr[j] = node->ptr[i];
		//delete node->ptr[i];
		node->ptr[i] = NULL;
		node->keyCount = size;
	}
	return splitNode;
}
bool BTree::leafNode(Node* root) {
	for (int i = 0; i < SIZE; i++) {
		if (root->ptr[i] != NULL)
			return false;
	}
	return true;
}
Node* BTree::search(Node* root, string key) {
	if (leafNode(root))
		return root;
	int i;
	for (i = 0; i < root->keyCount; i++) {
		if (key < root->key[i])
			return search(root->ptr[i], key);
	}
	return search(root->ptr[i], key);
}
void BTree::inorder(Node* root) {
	if (root == NULL)
		return;
	else {
		int i;
		for (i = 0; i < root->keyCount; i++) {
			inorder(root->ptr[i]);
			visitNode(root, i);
		}
		inorder(root->ptr[i]);
	}
}
void BTree::visitNode(Node* node, int nodeNum) {
	cout << node->key[nodeNum] << " ";
}
int BTree::height(Node* root) {
	int count = 0, cnt = 0;

	if (root == NULL)
		return 0;
	else {
		int i;
		for (i = 0; i < root->keyCount; i++) {
			cnt = height(root->ptr[i]);
			if (count < cnt)
				count = cnt;
		}
		cnt = height(root->ptr[i]);
		if (count < cnt)
			count = cnt;
	}
	return ++cnt;
}
Node* BTree::getRoot() {
	return root;
}
void BTree::setRoot(Node* root) {
	this->root = root;
}
BTree::BTree() {
	root = new Node();
}