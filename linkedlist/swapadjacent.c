// create owm linled list
// swap adjacent nodes of linked list

#include<stdio.h>
#include<stdlib.h>


struct node
{
    int value;
    struct node *next;										// pointer pointing to next node
};


void push_front( struct node **h, int a )							// add at first
{
    struct node *new = ( struct node * )malloc( sizeof( struct node ) );			//constructing new node
    new -> value = a;										// assigning value to new node
    new -> next = *h;										// new node will point first node
    *h = new;											// head will point to new node
}

void print( struct node * head )   								// print linkedlist 
{					
    struct node * current = head;

    while ( current != NULL ) 									// traversing till end of list
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

struct node *swapadjacent( struct node *head ) 							// function to swap adjacent pairs
{ 
    // If linked list is empty or there is only 
    // one node in list 
    if ( head == NULL || head -> next == NULL ) 
        return head; 
  
    // Fix the head and its next explicitly to 
    // avoid many if else in while loop 
    struct node *curr = head -> next -> next; 
    struct node *prev = head; 
    head = head -> next; 
    head -> next = prev; 
  
    // Fix remaining nodes 
    while ( curr != NULL && curr->next != NULL ) 
    { 
        prev -> next = curr -> next; 
        prev = curr; 
        struct node *next = curr -> next -> next; 
        curr -> next -> next = curr; 
        curr = next; 
    } 
      
    prev -> next = curr; 
    return head;
} 
  
int main()
{
	struct node *head = NULL;
	int n;
	printf( "Enter the number of elements\n" );
	scanf("%d",&n);
	int *arr = ( int * )malloc( sizeof( int ) * n );
	printf( "Enter the elements\n" );
	for( int i = 0; i < n; i++ )
	{
		scanf("%d",&arr[i]);
		push_back( &head, arr[ i ] );
	}	
	
	head = swapadjacent( head );								//calling function to swap adjacent nodes
	
	printf( "The list after swapping adjacent nodes is\n" );
	print(head);										// printing the list
}
