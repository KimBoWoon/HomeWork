#include "Define.h"
#include "BinarySerachTree.h"

int main() {
	BinarySerachTree BST;
	string insertKey[] = { "one", "two", "thr", "fou", "fiv", "six", "sev", "eig", "nin", "ten", "ele", "twe", "thi", "fout", "fift", "sixt", "sevt", "eigt", "nint", "twet" };
	//string insertKey[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20" };

	try {
		cout << "노드 삽입" << endl;
		for (int i = 0; i < 20; i++) {
			BST.insertNode(insertKey[i]);
			BST.inorder(BST.getRoot());
			cout << endl;
		}
		cout << "삽입 순서대로 삭제" << endl;
		for (int i = 0; i < 20; i++) {
			BST.deleteNode(insertKey[i]);
			BST.inorder(BST.getRoot());
			cout << endl;
		}
		cout << "노드 삽입" << endl;
		for (int i = 0; i < 20; i++) {
			BST.insertNode(insertKey[i]);
			BST.inorder(BST.getRoot());
			cout << endl;
		}
		cout << "삽입 순서와 반대로 삭제" << endl;
		for (int i = 19; i >= 0; i--) {
			BST.deleteNode(insertKey[i]);
			BST.inorder(BST.getRoot());
			cout << endl;
		}
	}
	catch (const char* s) {
		cout << s << endl;
	}
}