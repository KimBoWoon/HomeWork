#ifndef __HUFFMAN__
#define __HUFFMAN__

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PriorityQueue.h"

#define MAX_CHAR 256
#define MAX_BIT 8

typedef unsigned int UINT;
typedef unsigned char UCHAR;

typedef struct HuffmanSymbolInfo {
	UCHAR symbol;
	int frequency;
} SymbolInfo;

typedef struct HuffmanNode {
	SymbolInfo data;
	struct HuffmanNode* left;
	struct HuffmanNode* right;
} Node;

typedef struct BitBuffer {
	UCHAR* buffer;
	UINT size;
} BitBuffer;

typedef struct HuffmanCode {
	UCHAR code[MAX_CHAR];
	int size;
} HuffmanCode;

void HuffmanEncode(Node** node, UCHAR* s, BitBuffer* encode, HuffmanCode codeTable[MAX_CHAR]);
void HuffmanDecode(Node* tree, BitBuffer* endoded, UCHAR* decoded);
void buildPrefixTree(Node** tree, SymbolInfo symbolTable[MAX_CHAR]);
void buildCodeTable(Node* tree, HuffmanCode codeTable[MAX_CHAR], UCHAR code[MAX_BIT], int size);
void addBit(BitBuffer* buffer, char value);
void printBinary(BitBuffer* buffer);
void HuffmanDestroyTree(Node* Node);
void HuffmanDestroyNode(Node* Node);
Node* createNode(SymbolInfo newData);

#endif