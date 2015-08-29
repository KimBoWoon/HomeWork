#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* 2-3 tree 이므로 크기는 2
** 크기 조절 가능하다
*/
#define SIZE 2

struct Node
{
	int key[SIZE];
	struct Node* ptr[SIZE + 1];
	struct Node* parent;
	int capa;
};
typedef struct Node NODE;
typedef NODE		*TREE;


//오버플로우 체크
bool chk_overflow(TREE node)
{
	if (node->capa >= SIZE)
		return true;
	else
		return false;
}
//리프노드인지 체크
bool chk_leafnode(TREE root)
{
	for (int i = 0; i < SIZE + 1; i++)
		if (root->ptr[i] != NULL)
			return false;
	return true;
}
//노드가 부모노드에서 몇번째에 있는지 확인
int find_index(TREE node)
{
	if (node->parent != NULL)
	{
		int i;
		for (i = 0; i < node->parent->capa + 1; i++)
		{
			if (node->parent->ptr[i] == node)
				return i;
		}
	}
	return -1;
}
//형재노드에 여유가 있는지 체크
int chk_bro(TREE node)
{
	//부모가 없으면 형제도 없다.
	if (node->parent == NULL)
		return -1;
	else
	{
		int tmp = find_index(node);
		//노드 바로 왼쪽 형제가 존재할때
		if (tmp - 1 >= 0)
		{
			//여유가 있다면 index반환
			if (node->parent->ptr[tmp - 1]->capa < SIZE)
				return tmp - 1;
		}
		//노드 바로 오른쪽 형제가 존재할때
		else if (tmp + 1 < SIZE + 1)
		{
			//여유가 있다면 index 반환
			if (node->parent->ptr[tmp + 1]->capa < SIZE)
				return tmp + 1;
		}
		return -1;
	}
}

// 주어진 노드의 자식들에 있어
// 부모가 누구인지 확실히 하기 ㅋ
void set_parent(TREE node)
{
	for (int i = 0; i < node->capa + 1; i++)
	{
		if (node->ptr[i] != NULL)
			node->ptr[i]->parent = node;
	}
}
// 노드 생성
TREE make_node(void)
{
	TREE tmp;
	tmp = (TREE)malloc(sizeof(NODE));
	tmp->capa = 0;
	tmp->parent = NULL;
	for (int i = 0; i < SIZE + 1; i++)
		tmp->ptr[i] = NULL;
	return tmp;
}
// 노드 삭제
void delete_node(TREE tmp)
{
	free(tmp);
}
// 노드 출력
void print_node(TREE node)
{
	int i;
	printf("{");
	for (i = 0; i < node->capa; i++)
	{
		printf("%x, (%d), ", node->ptr[i], node->key[i]);
	}
	printf("%x} capa:%d\n", node->ptr[i], node->capa);
}
//노드에 값 삽입
void input_node(TREE node, int item, TREE left, TREE right)
{
	int i;
	for (i = node->capa; i > 0; i--)
	{
		if (item > node->key[i - 1])
		{
			node->key[i] = item;
			node->ptr[i] = left;
			node->ptr[i + 1] = right;
			node->capa += 1;
			return;
		}
		else
		{
			node->key[i] = node->key[i - 1];
			node->ptr[i + 1] = node->ptr[i];
		}
	}
	node->key[i] = item;
	node->ptr[i] = left;
	node->ptr[i + 1] = right;
	node->capa += 1;
	return;
}
//주어진 노드를 반으로 분리하여
//뒤에 절반을 다시 노드로 리턴
TREE sep_node(TREE node)
{
	TREE tmp = NULL;
	if (node->capa >= 2)
	{
		int i, j = 0;
		int tmp_capa = node->capa;
		tmp = make_node();
		for (i = (node->capa) / 2; i < node->capa; i++, j++)
		{
			tmp->key[j] = node->key[i];
			tmp->ptr[j] = node->ptr[i];
			tmp_capa--;
			tmp->capa += 1;
		}
		tmp->ptr[j] = node->ptr[i];
		node->capa = tmp_capa;
	}
	return tmp;
}
//재분배 함수
void insert_redistribute(TREE node, int item, TREE left, TREE right)
{
	int bro_index = chk_bro(node);
	int node_index = find_index(node);
	TREE bro = node->parent->ptr[bro_index];
	//여유있는 형제가 왼쪽일 경우
	if (bro_index < node_index)
	{
		//item이 parent로 가야할경우
		if (item < node->key[0])
		{
			input_node(bro, node->parent->key[node_index - 1],
				bro->ptr[bro->capa], left);
			node->parent->key[node_index - 1] = item;
			node->ptr[0] = right;
			set_parent(node);
			set_parent(bro);
		}
		else
		{
			int i;
			input_node(bro, node->parent->key[node_index - 1],
				bro->ptr[bro->capa], node->ptr[0]);
			node->parent->key[node_index - 1] = node->key[0];
			for (i = 0; i<node->capa - 1; i++)
			{
				node->key[i] = node->key[i + 1];
				node->ptr[i] = node->ptr[i + 1];
			}
			node->ptr[i] = node->ptr[i + 1];
			node->capa -= 1;
			input_node(node, item, left, right);
			set_parent(node);
			set_parent(bro);
		}
	}
	//여유있는 형제노드가 오른쪽일 경우
	else
	{
		//item이 parent로 가야하는 경우
		if (item > node->key[node->capa - 1])
		{
			input_node(bro, node->parent->key[node_index],
				right, bro->ptr[0]);
			node->parent->key[node_index] = item;
			node->ptr[node->capa] = left;
			set_parent(node);
			set_parent(bro);
		}
		else
		{
			input_node(bro, node->parent->key[node_index],
				node->ptr[node->capa], bro->ptr[0]);
			node->parent->key[node_index] = node->key[node->capa - 1];
			node->capa -= 1;
			input_node(node, item, left, right);
			set_parent(node);
			set_parent(bro);
		}
	}
}

//트리에 값삽입 함수, 최상위 루트를 리턴
//parmeter
//root: 최상위 루트
//node: 삽입할 노드(find_node함수를 이용)
//item: 삽입할 값
//left: 값의 왼쪽 포인터 (사용할땐 NULL로)
//right: 값의 오른쪽 포인터 (사용할땐 NULL)

TREE insert_item(TREE root, TREE node, int item, TREE left, TREE right)
{
	//오버플로우가 아니면 그냥 넣기
	if (!chk_overflow(node))
	{
		input_node(node, item, left, right);
		return root;
	}
	//재분배
	else if (chk_bro(node) != -1)
	{
		insert_redistribute(node, item, left, right);
		return root;
	}
	else
	{
		int middle;
		//형제노드 생성
		TREE bro = sep_node(node);

		//올려 보낼 중간값 처리
		if (item < node->key[node->capa - 1])
		{
			middle = node->key[node->capa - 1];
			node->capa -= 1;
			input_node(node, item, left, right);
		}
		else if (item > bro->key[0])
		{
			int i;
			middle = bro->key[0];
			for (i = 0; i < bro->capa - 1; i++)
			{
				bro->key[i] = bro->key[i + 1];
				bro->ptr[i] = bro->ptr[i + 1];
			}
			bro->ptr[i] = bro->ptr[i + 1];
			bro->capa -= 1;
			input_node(bro, item, left, right);
		}
		else
		{
			middle = item;
			node->ptr[node->capa] = left;
			bro->ptr[0] = right;
		}

		// 분리된 노드들의 parent 포인터 처리
		set_parent(node);
		set_parent(bro);

		//중간값 올려보낼시 부모가 없는경우와 있는경우
		if (node->parent == NULL)
		{
			TREE paren = make_node();
			input_node(paren, middle, node, bro);
			set_parent(paren);
			return paren;
		}
		else
		{
			bro->parent = node->parent;
			return insert_item(root, node->parent, middle, node, bro);
		}
	}
}

//(삽입용) 넣어야 할 노드 찾기
TREE find_node(TREE root, int item)
{
	if (chk_leafnode(root))
		return root;
	else
	{
		int i;
		for (i = 0; i < root->capa; i++)
		{
			if (item < root->key[i])
			{
				return find_node(root->ptr[i], item);
			}
		}
		return find_node(root->ptr[i], item);
	}
}
//트리 출력 (레벨)
void print_tree(TREE root, int level)
{
	if (root != NULL)
	{
		int i;
		for (i = 0; i < root->capa; i++)
		{
			print_tree(root->ptr[i], level + 1);
			for (int j = 0; j < level; j++)
				printf("|  ");
			printf("+[%d]\n", root->key[i]);
		}
		print_tree(root->ptr[i], level + 1);
	}
}
//트리 삭제
void delete_tree(TREE root)
{
	if (root != NULL)
	{
		int i;
		for (i = 0; i < root->capa; i++)
		{
			delete_tree(root->ptr[i]);
		}
		free(root);
	}
}

int main(void)
{
	TREE tmp = make_node();
	int arr[20] = { 14, 7, 9, 13, 1, 8, 18, 19, 2, 5, 3, 11, 20, 4, 6, 10, 12, 16, 15, 17 };

	for (int i = 0; i < 20; i++)
	{
		printf("input: %d\n", i);
		tmp = insert_item(tmp, find_node(tmp, i), i, NULL, NULL);
		print_tree(tmp, 0);
		Sleep(150);
		system("cls");
	}
	print_tree(tmp, 0);
	delete_tree(tmp);

	return 0;
}