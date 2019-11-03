
void swapnodes( struct node **head,int a, int b)
{
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	struct node *x = (struct node *)malloc(sizeof(struct node));
	struct node *y = (struct node *)malloc(sizeof(struct node));
	struct node *prevX = (struct node *)malloc(sizeof(struct node));
	struct node *prevY = (struct node *)malloc(sizeof(struct node));
	curr = *head;
	prevX= NULL;
	x = *head;
	prevY = NULL;
	y = *head;
	while(x!=NULL && x-> value !=a)
	{
		prevX = x;
		x = x -> next;
	}
	while(y!=NULL && y->value != b)
	{
		prevY = y;
		y = y -> next;
	}
	if(prevX==NULL)
	{
		struct node *a1= y ->next;
		y ->next = x->next;
		x -> next = a1;
		*head = y;
		prevY -> next = x;
	}
	else if(prevY==NULL)
	{
		struct node *a1 = x ->next;
		x -> next = y -> next;
		y -> next = a1;
		*head = x;
		prevX -> next = y;
	}
	else if( prevX!=NULL && prevY!=NULL )
	{
		struct node *a1 = x -> next;
		x -> next = y -> next;
		y -> next = a1;
		prevX -> next = y;
		prevY -> next = x;
	}
}
