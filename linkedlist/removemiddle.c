// we have a list of size n
// we have to remove element at n/2+1 index if elements are present else at (n+1)/2
 


void remove_middle( struct node **head )						// function to remove middle element
{
	struct node *first = *head;
	struct node *second = *head;
	
	// if elements are even list will traverse till second last else till third last
	while( ( second -> next -> next != NULL ) && ( second -> next -> next -> next != NULL ) )	
	{
		second =second -> next -> next;
		first = first -> next;
	}	
			
	// we have to delete the next element of first 
	struct node *temp = first -> next;			
	first -> next = temp -> next;
	free( temp );
}


