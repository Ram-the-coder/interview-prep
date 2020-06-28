/*
    You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.

    Solution logic: Floyd's hare and tortoise cycle detecting algorithm
*/

void removeLoop(Node* head)
{
    if(!head) return;

    Node *slow = head, *fast = head, *fast_prev = NULL;
    
    // Check whether a cycle exists
    do {
        if(!fast) return; // There exists an end to the list, i.e. no loop exists
        
        slow = slow->next;

        fast = fast_prev = fast->next;
        if(fast) fast = fast->next;
        else return; 
        
    } while(slow != fast);
    

    // Find the entry point to the cycle
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast_prev = fast;
        fast = fast->next;
    }
    
    fast_prev->next = NULL;
}