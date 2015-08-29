#include "Define.h"
#include "AVLTree.h"

int main() {
	AVLTree BST;
	string insertKey[] = { "one", "two", "thr", "fou", "fiv", "six", "sev", "eig", "nin", "ten", "ele", "twe", "thi", "fout", "fift", "sixt", "sevt", "eigt", "nint", "twet" , "tone", "ttwo", "tthr", "tfou", "tfiv", "tsix", "tsev", "teig", "tnin", "thit" };
	//string insertKey[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20" };

	try {
		cout << "³ëµå »ðÀÔ" << endl;
		for (int i = 0; i < 30; i++) {
			cout << "Insert Key >> " << insertKey[i] << endl;
			BST.insertNode(insertKey[i]);
			BST.inorder(BST.getRoot());
			cout << endl << "-------------------------------------" << endl;
		}
	}
	catch (const char* s) {
		cout << s << endl;
	}
}