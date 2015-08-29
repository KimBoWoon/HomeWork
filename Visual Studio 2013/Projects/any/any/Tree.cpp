#include <iostream>
using namespace std;

struct tree_node{
     tree_node *left_child;

     int data;
     tree_node *right_child;
};

tree_node *root;

// 이진 트리 생성(구조체로 반환)
tree_node *create_node(int data){
     tree_node *node = new tree_node;
     node->left_child = NULL;
     node->data = data;
     node->right_child = NULL;
     return node;
}

// 중위 순회
void inorder(tree_node *ptr){
     if(ptr){

          inorder(ptr->left_child);
          cout<<ptr->data<<" ";
          inorder(ptr->right_child);
     }
}

// 전위 순회
void preorder(tree_node *ptr){
     if(ptr){
          cout<<ptr->data<<" ";
          preorder(ptr->left_child);
          preorder(ptr->right_child);
     }
}

// 후위 순회 
void postorder(tree_node *ptr){
     if(ptr){
          postorder(ptr->left_child);
          postorder(ptr->right_child);
          cout<<ptr->data<<" ";
     }
}

// 메모리 반환
void FreeEnd(tree_node *ptr){
     if(ptr){
          //재귀함수로 메모리를 해제
          FreeEnd(ptr->left_child);
          FreeEnd(ptr->right_child);
          free(ptr);
     }
}

 

void main(){
     // 이진트리 생성
     root = create_node(1);
     root->left_child = create_node(2);
     root->right_child = create_node(3);
     root->left_child->left_child = create_node(4);
     root->left_child->right_child = create_node(5);
     root->right_child->left_child = create_node(6);

     root->right_child->right_child = create_node(7);

     cout<<"중위순회: ";
     inorder(root);
	 cout<<endl;

     cout<<"전위순회: ";
     preorder(root);
	 cout<<endl;

     cout<<"후위순회: ";
     postorder(root);
	 cout<<endl;

     //메모리 반환
     FreeEnd(root);
}