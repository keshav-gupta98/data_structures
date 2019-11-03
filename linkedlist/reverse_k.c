// we have to reverse linked list in groups of given size
// construct own list
// e.g. {1,2,3,4,5,6,7} group size =2 output-> {2,1,4,3,6,5,7}

#include<stdio.h>
#include<stdlib.h>

struct node										// definition of linked list
{
    int value;
    struct node *next;									// pointer pointing to next node
};


void push_front( struct node **h, int a )						// add at first
{
    struct node *new = ( struct node * )malloc( sizeof( struct node ) );		//constructing new node
    new -> value = a;									// assigning value to new node
    new -> next = *h;									// new node will point first node
    *h = new;										// head will point to new node
}

void print( struct node * head )   							// print linkedlist 
{					
    struct node * current = head;

    while ( current != NULL ) 								// traversing till end of list
    {	
        printf( "%d ", current -> value );
        current = current -> next;
    }
    printf( "\n" );
}


void push_back( struct node **h, int a )                				//insert at last 
{
     struct node *new = ( struct node * )malloc( sizeof( struct node ) );
        new -> value = a;
        new -> next = NULL;
    if( *h == NULL )									// if list is empty 
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

struct node *reverse_k( struct node *head, int k )  					// function to reverse in groups
{  
    struct node* current = head;  
    struct node* next = NULL;  
    struct node* prev = NULL;  
    int count = 0;  
      
    while ( current != NULL && count < k )  
    {  
        next = current -> next;  
        current -> next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
    if ( next != NULL )  
    head -> next = reverse_k( next, k );  
    return prev;  
}

int main()
{
	struct node *head = NULL;
	int n;
	printf( "Enter the number of elements\n" );
	scanf("%d",&n);
	printf( "Enter the elements\n" );
	for( int i = 0; i < n; i++ )
	{
		int a;
		scanf( "%d",&a );
		push_back( &head, a );
	}
	int k;
	printf( "Enter the size of group\n" );	
	scanf( "%d",&k );
	head = reverse_k( head, k );								//calling function to reverse k nodes
	
	printf( "The list after reversing in group of size %d is\n",k );
	print(head);										// printing the list

}
