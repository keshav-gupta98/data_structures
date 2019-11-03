// create own linkedlist

#include<stdio.h>
#include<stdlib.h>


struct node										// definition of linked list
{
    int value;
    struct node *next;									// pointer pointing to next node
};

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


void push_front( struct node **h, int a )							// add at first
{
    struct node *new = ( struct node * )malloc( sizeof( struct node ) );		//constructing new node
    new -> value = a;									// assigning value to new node
    new -> next = *h;									// new node will point first node
    *h = new;										// head will point to new node
}

int find( struct node **head, int a )						// find whether value exixts or not will return index
{
    int search = 0;
    struct node *new = ( struct node * )malloc( sizeof( struct node ) );	// constructing new node
    new = *head;								
    while( new )								// traversing till end of list
    {
        if( new -> value == a )
        return search;
    	new = new -> next;
    	search++;
    }
    return search;								// return index
}




void pop_back( struct node **h )				                 	//remove from last
{
    if( *h == NULL )
    {
        printf( "No element to delete" );
    }
    else
    {
        struct node *curr = ( struct node * )malloc( sizeof( struct node ) );
        curr = *h;
        while( curr -> next -> next != NULL )
        {
            curr = curr -> next;
        }
        struct node *curr1 = ( struct node * )malloc( sizeof( struct node ) );
        curr1 = curr -> next;
        free( curr1 );
        curr -> next = NULL;
    }
}


void pop_front( struct node **h )						          	// remove from first
{
    if( *h == NULL )
    {
        printf( "No element" );
    }
    else
    {
        struct node *curr = ( struct node * )malloc( sizeof( struct node ) );
        curr = *h;
        *h= curr -> next;
        free( curr );
    }
}


void delete( struct node **head, int pos )				         	// remove at specific position
{
    int i = 0;
    pos = pos - 1;
    if( pos == 0 )
    {
        pop_front( head );
    }
    else
    {
        struct node *curr = ( struct node * )malloc( sizeof( struct node ) );
        curr = *head;
        while( curr -> next != NULL && i < pos - 1 )
        {
            curr = curr -> next;
            i++;
        }
        struct node *temp = ( struct node * )malloc( sizeof( struct node ) );
        temp = curr -> next;
        curr -> next = temp -> next;
        free( temp );
    }
}


void insert( struct node **h, int val, int pos )				    	// insert at specific position
{
    int i = 0;
    pos = pos - 1;
    if( pos == 0 )
    {
        push_front( h, val );
    }
    else
    {
        struct node *new = ( struct node * )malloc( sizeof( struct node ) );
        struct node *curr = ( struct node * )malloc( sizeof( struct node ) );
        new -> value = val;
        curr = *h;
        while( curr && i < pos - 1 )
        {
            curr = curr -> next;
            i++;
        }
        new -> next = curr -> next;
        curr -> next = new;
    }
}


void reverse( struct node **head)						//to reverse elements of linkedlist
{
	struct node *n;
	struct node *p = NULL;
	struct node *curr = *head;
	while( curr )
	{
		n = curr -> next;
		curr -> next = p;
		p = curr;
		curr = n;
	}
	*head = p;
}

// find       -   to find the index of element
// reverse    -   to reverse the linkedlist
// insert     -   to insert at specific position
// delete     -   remove at specific position
// pop_front  -   remove from front
// pop_back   -   remove from last
// push_front -   add at begining
// push_back  -   add at last
// print      -   to print linked list
