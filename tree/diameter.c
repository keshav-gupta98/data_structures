/*The diameter of a tree (sometimes called the width) is the number of nodes on the longest path 
between two end nodes. */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *insert(struct node *root , int data)
{
    if(root == NULL)
    {
       struct node* node = (struct node*)malloc(sizeof(struct node)); 
        node->data = data; 
        node->left = NULL; 
        node->right = NULL; 
        return(node);
    }
    else if(root->data == data)
    {}
    else if(root->data>data)
    {
        root->left = insert(root->left, data);
    }
    else 
    {
        root->right = insert(root->right,data);
    }
    return root;
}
int max(int a, int b)
{
    if(a>b)
    return a;
    return b;
}
int height(struct node *root)
{
    if(root == NULL)
    return 0;
    return 1+max(height(root->right),height(root->left));
}
int diam(struct node *root)
{
    if(root == NULL)
    return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diam(root->left);
    int rd = diam(root->right);
    return max(1+lh+rh,max(ld,rd));
}
int main() {
    int n;
    scanf("%d",&n);
    struct node *root = NULL;
    for(int i = 0 ; i  < n  ; i++)
    {
        int val;
        scanf("%d",&val);
        root = insert(root,val);
    }
    printf("%d",diam(root));
    return 0;
}