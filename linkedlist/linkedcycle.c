// create your own linked list
// detect whether cycle is present or not if present return the node at which cycle starts

struct ListNode										//Definition for singly-linked list. 
{
     int val;
     struct ListNode *next;
};
 
struct ListNode* detectCycle( ListNode* A ) 
{

    ListNode *second = A;
    ListNode *first = A;
    while( second != NULL && first != NULL )						// traversing till first = second 
    {
        if( second -> next == NULL || first -> next == NULL )				// if pointer reaches end means no cycle exists
        return NULL;
        else
        {
            first = first -> next;
            second = (second -> next) -> next;
        }
        if( first == second )								// cycle found
        break;
    }
    if( first == NULL || second == NULL )					
    return NULL;
    ListNode *curr = A;
    while( curr!= first )						// the point where curr and first meet is starting point of cycle
    {
        curr = curr -> next;
        first = first -> next;
    }
    return curr;							// returning starting point of cycle
}

