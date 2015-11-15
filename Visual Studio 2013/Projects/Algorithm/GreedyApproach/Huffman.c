#include "Huffman.h"

Node* createNode(SymbolInfo newData) {
	Node* newNode = (Node*)calloc(1, sizeof(Node));
	newNode->data = newData;

	return newNode;
}

void buildPrefixTree(Node** tree, SymbolInfo symbolTable[MAX_CHAR]) {
	int i = 0;
	PQNode result;
	PriorityQueue* PQ = PQ_Create(0);

	for (i = 0; i < MAX_CHAR; i++) {
		if (symbolTable[i].frequency > 0) {
			Node* node = createNode(symbolTable[i]);
			PQNode newNode;

			newNode.Priority = symbolTable[i].frequency;
			newNode.Data = node;
			PQ_Enqueue(PQ, newNode);
		}
	}

	while (PQ->UsedSize > 1) {
		SymbolInfo newData = { 0, 0 };
		Node* bitNode = createNode(newData);
		Node* left;
		Node* right;

		PQNode qLeft;
		PQNode qRight;
		PQNode newNode;

		PQ_Dequeue(PQ, &qLeft);
		PQ_Dequeue(PQ, &qRight);

		left = (Node*)qLeft.Data;
		right = (Node*)qRight.Data;

		bitNode->data.symbol = 0;
		bitNode->data.frequency = left->data.frequency + right->data.frequency;

		bitNode->left = left;
		bitNode->right = right;

		newNode.Priority = bitNode->data.frequency;
		newNode.Data = bitNode;

		PQ_Enqueue(PQ, newNode);
	}

	PQ_Dequeue(PQ, &result);
	*tree = (Node*)result.Data;
}

void buildCodeTable(Node* tree, HuffmanCode codeTable[MAX_CHAR], UCHAR code[MAX_BIT], int size) {
	if (tree == NULL)
		return;

	if (tree->left != NULL) {
		code[size] = 0;
		buildCodeTable(tree->left, codeTable, code, size + 1);
	}
	if (tree->right != NULL) {
		code[size] = 1;
		buildCodeTable(tree->right, codeTable, code, size + 1);
	}
	if (tree->left == NULL && tree->right == NULL) {
		int i;

		for (i = 0; i < size; i++)
			codeTable[tree->data.symbol].code[i] = code[i];

		codeTable[tree->data.symbol].size = size;
	}
}

void addBit(BitBuffer* buffer, char value) {
	UCHAR mask = 0x80;

	if (buffer->size % 8 == 0) {
		buffer->buffer = realloc(buffer->buffer, sizeof(UCHAR) * ((buffer->size / 8) + 1));
		buffer->buffer[buffer->size / 8] = 0x00;
	}

	mask >>= buffer->size % 8;

	if (value == 1)
		buffer->buffer[buffer->size / 8] |= mask;
	else
		buffer->buffer[buffer->size / 8] &= ~mask;

	buffer->size++;
}

void HuffmanEncode(Node** tree, UCHAR* s, BitBuffer* encode, HuffmanCode codeTable[MAX_CHAR]) {
	int i = 0, j = 0;
	SymbolInfo symbolTable[MAX_CHAR];
	UCHAR temporary[MAX_BIT];

	for (i = 0; i < MAX_CHAR; i++) {
		symbolTable[i].symbol = i;
		symbolTable[i].frequency = 0;
	}

	for (i = 0; s[i] != '\0'; i++)
		symbolTable[s[i]].frequency++;

	buildPrefixTree(tree, symbolTable);

	buildCodeTable(*tree, codeTable, temporary, 0);

	for (i = 0; s[i] != '\0'; i++) {
		int cnt = codeTable[s[i]].size;

		for (j = 0; j < cnt; j++)
			addBit(encode, codeTable[s[i]].code[j]);
	}
}

void HuffmanDecode(Node* tree, BitBuffer* encoded, UCHAR* decoded) {
	UINT i;
	int index = 0;
	Node* cur = tree;

	for (i = 0; i <= encoded->size; i++) {
		UCHAR mask = 0x80;

		if (cur->left == NULL && cur->right == NULL) {
			decoded[index++] = cur->data.symbol;
			cur = tree;
		}

		mask >>= i % 8;

		if ((encoded->buffer[i / 8] & mask) != mask)
			cur = cur->left;
		else
			cur = cur->right;
	}
	decoded[index] = '\0';
}

void HuffmanDestroyNode(Node* Node) {
	free(Node);
}

void HuffmanDestroyTree(Node* Node) {
	if (Node == NULL)
		return;

	HuffmanDestroyTree(Node->left);
	HuffmanDestroyTree(Node->right);
	HuffmanDestroyNode(Node);
}

void printBinary(BitBuffer* buffer) {
	UINT i;

	for (i = 0; i < buffer->size; i++) {
		UCHAR mask = 0x80;
		mask >>= i % 8;
		printf("%d", (buffer->buffer[i / 8] & mask) == mask);
	}
	printf("\n");
}