#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
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
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder( root -> left );
        printf( "%d ", root -> data );
        inorder( root -> right );
    }
}
int min(struct node *n)
{
    while( n -> left != NULL )
    {
        n = n -> left;
    }
    return n -> data;
}
int max(struct node *n)
{
    while( n -> right != NULL )
    {
        n = n -> right;
    }
    return n -> data;
}
void postorder(struct node *root)
{
	postorder( root -> left );
	postorder( root -> right );
	printf( "%d",root -> data );
}
struct node *delmin(struct node *root)
{
	struct node *curr = root;
	if(curr -> left == NULL)
	{
		root = root -> right;
		return root;
	}
	if( curr -> left -> left == NULL)
	{
		root -> left = root -> left -> right;
		return root;
	}
	while( curr -> left -> left != NULL )
	{
		curr = curr -> left;
	}
	curr -> left = curr -> left -> right;
	return root;	
}
struct node *delmax(struct node *root)
{
	struct node *curr = root;
	if( curr -> right == NULL )
	{
		root = root -> left;
		return root;
	}
	if( curr -> right -> right == NULL )
	{
		root -> right = root-> right -> left;
		return root;
	}
	while( curr -> right -> right != NULL )
	{
		curr = curr -> right;
	}
	curr -> right = curr -> right -> left;
	return root;
}
int height(struct node *root)
{
    if( root == NULL )
    return 0;
    return 1 + max( height( root -> left ) , height( root -> right ) );
}
int diam(struct node *root)
{
    return 1 + height( root -> left ) + height( root -> right );
}
int main()
{
	struct node *root = NULL;
	root = insert(root,19);
	insert(root,15);
	insert(root,17);
	insert(root,18);
	insert(root,4);
	insert(root,21);
	insert(root,5);
	insert(root,6);
	insert(root,90);
	insert(root,-67);
	insert(root,-23);
	insert(root,-21);
	insert(root,-4);
	insert(root,45);
	insert(root,23);
	inorder( root );
	printf("\n%d %d \n",min(root),max(root));
	root  = delmin(root);
	root = delmax(root);
	inorder(root);
	return 0;
}