#include "Huffman.h"

int main() {
    //char s[] = "aaabaacdd";
    char s[] = "http://www.seanlab.net";
    char *decoded = "";
    Node *root = NULL;
    BitBuffer encode = {NULL, 0};
    HuffmanCode codeTable[MAX_CHAR] = {0};

    HuffmanEncode(&root, s, &encode, codeTable);

    decoded = (char *) calloc((strlen(s) + 1), sizeof(char));
    HuffmanDecode(root, &encode, decoded);

    printf("Original Size : %d Encoded Size : %d\n", (strlen(s) + 1) * sizeof(char) * 8, encode.size);
    printf("Original : %s\n", s);
    printf("Encoded : ");
    printBinary(&encode);
    printf("Decoded : %s\n", decoded);

    HuffmanDestroyTree(root);
    free(decoded);

    return 0;
}