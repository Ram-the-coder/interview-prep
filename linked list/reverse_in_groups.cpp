/*
    Given a linked list of size N. 
    The task is to reverse every k nodes (where k is an input to the function) in the linked list.

    Expected Time Complexity : O(n)
    Expected Auxilliary Space : O(1)

    Example:
    Input:
    2
    8
    1 2 2 4 5 6 7 8
    4
    5
    1 2 3 4 5
    3

    Output:
    4 2 2 1 8 7 6 5
    3 2 1 5 4
*/

/*
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

struct node* reverseList(struct node *head, int k)
{   
    node *next, *prev = NULL;
    for(node *cur = head; cur && k; cur = next, --k) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}

struct node *reverse (struct node *head, int k)
{ 
    struct node *prev = NULL;
    for(auto cur = head; cur; ) {
        // Find the value of the next_cur, i.e. the element that is k elements ahead of cur
        auto next_cur = cur;
        int i;
        for(next_cur = cur, i = 0; i < k && next_cur; ++i, next_cur = next_cur->next);
        
        // Reverse k elements starting from cur
        auto head_of_reversed_list = reverseList(cur, k);
        // Attach the reversed list to the existing list
        if(!prev) head = head_of_reversed_list;
        else prev->next = head_of_reversed_list;
        
        // Update prev, cur
        prev = cur; // After the reversal, cur becomes the tail of the reversed list, thus the prev element to the next list
        cur = next_cur;
    }
    
    return head;
}
