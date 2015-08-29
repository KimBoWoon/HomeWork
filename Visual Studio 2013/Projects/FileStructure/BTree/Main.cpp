#include "BTree.h"

int main(void) {
	BTree B;
	string insertKey[] = { "one", "two", "thr", "fou", "fiv", "six", "sev", "eig", "nin", "ten", "ele", "twe", "thi", "fout", "fift", "sixt", "sevt", "eigt", "nint", "twet", "tone", "ttwo", "tthr", "tfou", "tfiv", "tsix", "tsev", "teig", "tnin", "thit" };

	cout << "<<" << SIZE << " B-Tree>>" << endl;
	for (int i = 0; i < 30; i++) {
		B.setRoot(B.insertNode(B.search(B.getRoot(), insertKey[i]), insertKey[i], NULL, NULL));
		B.inorder(B.getRoot());
		cout << endl << "Height : " << B.height(B.getRoot()) << endl;
	}
	cout << "<< DELETE >>" << endl;
	for (int i = 0; i < 30; i++) {
		B.deleteNode(B.getRoot(), insertKey[i]);
		B.inorder(B.getRoot());
		cout << endl << "Height : " << B.height(B.getRoot()) << endl;
	}
	/*B.setRoot(B.insertNode(B.search(B.getRoot(), "f"), "f", NULL, NULL));
	B.setRoot(B.insertNode(B.search(B.getRoot(), "e"), "e", NULL, NULL));
	B.setRoot(B.insertNode(B.search(B.getRoot(), "b"), "b", NULL, NULL));
	B.setRoot(B.insertNode(B.search(B.getRoot(), "a"), "a", NULL, NULL));
	B.setRoot(B.insertNode(B.search(B.getRoot(), "s"), "s", NULL, NULL));
	B.setRoot(B.insertNode(B.search(B.getRoot(), "c"), "c", NULL, NULL));
	B.setRoot(B.insertNode(B.search(B.getRoot(), "t"), "t", NULL, NULL));
	B.inorder(B.getRoot());
	cout << endl << "Height : " << B.height(B.getRoot()) << endl;
	B.deleteNode(B.getRoot(), "e");
	B.inorder(B.getRoot());
	cout << endl << "Height : " << B.height(B.getRoot()) << endl;
	B.deleteNode(B.getRoot(), "a");
	B.inorder(B.getRoot());
	cout << endl << "Height : " << B.height(B.getRoot()) << endl;
	B.deleteNode(B.getRoot(), "b");
	B.inorder(B.getRoot());
	cout << endl << "Height : " << B.height(B.getRoot()) << endl;
	B.deleteNode(B.getRoot(), "s");
	B.inorder(B.getRoot());
	cout << endl << "Height : " << B.height(B.getRoot()) << endl;
	B.deleteNode(B.getRoot(), "c");
	B.inorder(B.getRoot());
	cout << endl << "Height : " << B.height(B.getRoot()) << endl;*/
}