 #include<stdio.h>
 #include<stdlib.h>


int max(int a ,int b)
{
    if(a>b)
    return a;
    return b;
}


struct AVL
{
    int value;
    int height;
    struct AVL *left;
    struct AVL *right;
};


struct AVL* newNode(int key)
{
    struct AVL* new = (struct AVL*)malloc(sizeof(struct AVL*));
    new -> value = key;
    new ->left = NULL;
    new -> right = NULL;
    new ->height = 1;
    return new;
}


int findHeight(struct AVL* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->height;
}


struct AVL* leftrotate(struct AVL* root)
{
    struct AVL *y = root->right;  
    struct AVL *T2 = y->left;  
    
    y->left = root;  
    root->right = T2;  
    
    root->height = max(findHeight(root->left),findHeight(root->right)) + 1;  
    y->height = max(findHeight(y->left),findHeight(y->right)) + 1;  
  
    return y;  
}

struct AVL* rightrotate(struct AVL* root)
{  
    struct AVL *x = root->left;  
    struct AVL *T2 = x->right;  
    
    x->right = root;  
    root->left = T2;  
  
    root->height = max(findHeight(root->left), 
                    findHeight(root->right)) + 1;  
    x->height = max(findHeight(x->left), 
                    findHeight(x->right)) + 1;  
    
    return x;  
}  
int balance(struct AVL* node)
{
    if(node == NULL)
    return 0;
    return findHeight(node -> left) - findHeight(node -> right);
}
struct AVL* insert( struct AVL *node, int key )
{
    if( node == NULL )
    return newNode( key );
    if( node -> value > key )
    {
        node -> left = insert( node -> left , key );
    }
    else
    if( node -> value < key )
    {
        node -> right = insert( node -> right , key );
    }
    else
    {
        return node;
    }
    node -> height = 1 + max( findHeight( node -> left ), findHeight( node -> right ) );
    int diff = balance(node);

    if( diff > 1 && key < node -> left -> value )
    return rightrotate( node );

    if( diff < -1 && key > node ->right -> value )
    return leftrotate(node);

    if(diff > 1 && key > node -> left -> value)
    {
        node -> left = leftrotate(node-> left);
        return rightrotate(node);
    }

    if(diff < -1 && key < node -> right -> value)
    {
        node -> right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
void preOrder(struct AVL *root)  
{  
    if(root != NULL)  
    {  
        printf("%d",root->value);  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
int main()  
{  
    struct AVL *root = NULL;  
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);
    preOrder(root);  
}      

