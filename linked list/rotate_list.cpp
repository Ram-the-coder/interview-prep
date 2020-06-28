/*
    Given a singly linked list of size N. 
    The task is to rotate the linked list counter-clockwise by k nodes, 
    where k is a given positive integer smaller than or equal to length of the linked list.

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).
*/

// Though for this problem k <= len, this approach works even for k > len
Node* rotate(Node* head, int k)
{
    if(!head) return head;
    
    // Find the tail and the length of the list
    Node *tail;
    int len = 1;
    for(tail = head; tail->next; tail = tail->next, len++);
    
    k %= len; 
    
    if(k == 0) return head;
    
    tail->next = head; // Connect the end of the list to the start

    // Find the node where the list should end (tail)
    tail = head;
    while(--k) {
        tail = tail->next;
    }

    head = tail->next; // Update the head
    tail->next = NULL; // Break the list
    return head;
}
