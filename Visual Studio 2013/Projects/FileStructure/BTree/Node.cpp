#include "Node.h"

Node::Node() : keyCount(0) {
	memset(ptr, NULL, sizeof(Node*) * SIZE);
	parent = NULL;
}