
struct node *LCA(struct node *root,int val1,int val2)
{
    if( root == NULL )
    return NULL;
    if( root -> data == val1 || root -> data == val2 )
    return root;
    struct node *x = LCA( root -> left ,val1 ,val2);
    struct node *y = LCA( root -> right ,val1 ,val2);
    if( x && y )
    {
        return root;
    }
    else if( x )
    return x;
    else if( y )
    return y;
    else
    return NULL;
}
