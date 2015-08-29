#include <iostream>
using namespace std;

struct tree_node{
     tree_node *left_child;

     int data;
     tree_node *right_child;
};

tree_node *root;

// ���� Ʈ�� ����(����ü�� ��ȯ)
tree_node *create_node(int data){
     tree_node *node = new tree_node;
     node->left_child = NULL;
     node->data = data;
     node->right_child = NULL;
     return node;
}

// ���� ��ȸ
void inorder(tree_node *ptr){
     if(ptr){

          inorder(ptr->left_child);
          cout<<ptr->data<<" ";
          inorder(ptr->right_child);
     }
}

// ���� ��ȸ
void preorder(tree_node *ptr){
     if(ptr){
          cout<<ptr->data<<" ";
          preorder(ptr->left_child);
          preorder(ptr->right_child);
     }
}

// ���� ��ȸ 
void postorder(tree_node *ptr){
     if(ptr){
          postorder(ptr->left_child);
          postorder(ptr->right_child);
          cout<<ptr->data<<" ";
     }
}

// �޸� ��ȯ
void FreeEnd(tree_node *ptr){
     if(ptr){
          //����Լ��� �޸𸮸� ����
          FreeEnd(ptr->left_child);
          FreeEnd(ptr->right_child);
          free(ptr);
     }
}

 

void main(){
     // ����Ʈ�� ����
     root = create_node(1);
     root->left_child = create_node(2);
     root->right_child = create_node(3);
     root->left_child->left_child = create_node(4);
     root->left_child->right_child = create_node(5);
     root->right_child->left_child = create_node(6);

     root->right_child->right_child = create_node(7);

     cout<<"������ȸ: ";
     inorder(root);
	 cout<<endl;

     cout<<"������ȸ: ";
     preorder(root);
	 cout<<endl;

     cout<<"������ȸ: ";
     postorder(root);
	 cout<<endl;

     //�޸� ��ȯ
     FreeEnd(root);
}