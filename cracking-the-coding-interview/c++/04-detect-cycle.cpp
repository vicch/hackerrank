// Problem:
// Detect whether this is a cycle in a linked list.
// 
// Solution 1:
// Running fast and slow pointers, if they equal before fast reaches end, there
// is a cycle.
// 
// Solution 2:
// Another solution is to revert the linked list while running forward, if at
// some point it reaches the head again, there is a cycle. Problem is non-cycle
// linked list will be modified in this process, and it's more complex to
// implement.

bool has_cycle(Node* head)
{
    if (!head)
        return false;
    
    Node *fast, *slow;
    
    for (slow = head, fast = head->next; fast != NULL && fast != slow;) {
        fast = (fast ? fast->next : NULL);
        fast = (fast ? fast->next : NULL);
        slow = (slow ? slow->next : NULL);
    }
        
    return fast != NULL;
}