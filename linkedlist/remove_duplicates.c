struct node* remove_duplicates(struct node *head)
{
    struct node *curr = head;
    while(curr)
    {
        struct node *temp = curr;
        while(temp->next)
        {
            if(temp->next->value == curr->value)
            {
                struct node *temp1 = temp->next;
                temp->next = temp->next->next;
                free(temp1);
            }
            else
            {
                temp = temp -> next;
            }
        }
        curr = curr -> next;
    }
    return head;
}