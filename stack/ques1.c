#include<stdio.h>
#include<stdlib.h>


struct node										// definition of linked list
{
    int value;
    struct node *next;									// pointer pointing to next node
};


void push_front( struct node **h, int a )							// add at first
{
    struct node *new = ( struct node * )malloc( sizeof( struct node ) );		//constructing new node
    new -> value = a;									// assigning value to new node
    new -> next = *h;									// new node will point first node
    *h = new;										// head will point to new node
}
void print( struct node * head )   						// print linkedlist 
{					
    struct node * current = head;

    while ( current != NULL ) 							// traversing till end of list
    {
        printf( "%d ", current -> value );
        current = current -> next;
    }
    printf( "\n" );
}


void push_back( struct node **h, int a )                					//insert at last 
{
     struct node *new = ( struct node * )malloc( sizeof( struct node ) );
        new -> value = a;
        new -> next = NULL;
    if( *h == NULL )										// if list is empty 
    {
        *h = new;
    }
    else
    {
        struct node *curr = ( struct node * )malloc( sizeof( struct node ) );
        curr = *h;
        while( curr -> next != NULL )
        {
            curr = curr -> next;
        }
        curr -> next = new;
    }
}

struct node* removeNodes(struct node* head, int x) {
struct node* curr = head;
struct node* temp;

while( curr->next!=NULL )
{
    if(curr-> next -> value> x)
    {
        temp = curr-> next;
        curr -> next == curr -> next -> next;
        free(temp);
    }
    curr = curr -> next;
}

return head;
}


int main()
{
	struct node *head = NULL;
	push_back(&head,1);
	push_back(&head,2);
	push_back(&head,3);
	push_back(&head,5);
	push_back(&head,3);
	push_back(&head,2);
	push_back(&head,8);
	head = removeNodes(head,3);
	print(head);
}
