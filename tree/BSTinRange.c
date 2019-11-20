#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node* root= NULL;


struct node *insert(struct node *root , int key )
{
    
    if(root == NULL)
    {
        struct node *ret = (struct node *)malloc(sizeof(struct node));
        ret -> data = key;
        ret -> left = NULL;
        ret -> right = NULL;
        return ret;
    }
    if( root -> data == key){}
    if( root -> data > key )
    {
        root -> left = insert( root -> left , key );
    }
    else if( root -> data < key )
    {
        root -> right = insert( root -> right , key );
    }
    return root;
}
void Print(struct node *node, int k1 , int k2)
{
    if(node==NULL)
    return;
    if(k1<node->data)
    Print(node->left,k1,k2);
    if(k1<=node->data&&k2>=node->data)
    {
        printf("%d ",node->data);
    }
    if(k2>node->data)
    Print(node->right,  k1,  k2);
}

