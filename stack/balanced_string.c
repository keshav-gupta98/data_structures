// in this we will see whether a given string is balanced or not
// we will use stack in this question which is built bty us only

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char data;
    struct stack *next;							// pointer to next element in stack
};
struct stack * push( char d, struct stack **head )			//function to add element top of stack
{
   struct stack *new = ( struct stack * )malloc( sizeof( struct stack ) );	// constructing a new node
   if(new == NULL )
   {
       printf("Stack is full\n");
   }
   else
   {
       new->data = d;					// assigning value to node
       new -> next = *head;				// new node will point to element present at top 
       *head = new;					// head will point to new node
       return new;
   }
}
char pop( struct stack **head )				// function to delete element at top of stack
{
    struct stack *temp = *head;				// constructing new node pointing to first element
    *head = temp -> next;				// head will start pointing to the next element of top 
    char t = temp -> data;				// storing the character present at top
    free(temp);						// deleting element
    return t;						// returning deleted element
}

char peek( struct stack **head )			// function to return top element
{
    struct stack *temp = *head;
    return temp -> data;
}

int isEmpty( struct stack **head)			// function will return 1 if stack is empty else 0
{
	if( *head == NULL )				// if head is pointing to null it means stack is empty
	return 1;
	else
	return 0;
}

int check_Balance( char input[] )			// function to check whether string is balanced or not
{
    struct stack *head = NULL;
    int i=0;
    
    while(input[ i ] != '\0')
    {
        if( input[ i ] == '{' || input[ i ] == '[' || input[ i ] == '(' )	
       	{
       		push( input[ i ], &head );
       	}
       	else if( isEmpty( &head ) ==1 )				// stack is empty it means there is no starting character
       	{							// if present character is closing character which means string
       		return 0;					// is not balanced
       	}
       	/*
       	now checking if present char is closing bracket and char at top of stack is a opening bracket of same kind or not
       	*/
       	else if( (input[i]==')' && peek( &head )=='(') || (input[i]== '}' && peek(&head)=='{') || (input[i]== ']' && peek(&head)=='[') )
       	{
       		pop(&head);
       	}
       	i++;
	}
	if( isEmpty(&head) ==1 )		// if stack is empty then it means each opening bracket has a matching closing bracket
	return 1;
	else
	return 0;
}

int main()
{
    char input[50];
    scanf("%s",input);
    
    int result = check_Balance( input );
    
    if( result ==1 )
    printf("YES! %s is a balanced string ",input);
    else
    printf("NO! %s is a balanced string ",input);
    return 0;
}

