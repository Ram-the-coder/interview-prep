/*
    Given a singly linked list of size N of integers. 
    The task is to check if the given linked list is palindrome or not.
    Expected Time Complexity: O(N)
    Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)
*/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* reverse_list(Node *head) {
    Node *prev = NULL;
    Node *cur = head, *next;
    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    // Find the middle of the list
    Node *slow = head, *fast = head->next;
    
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    // Reverse the second half
    // If we need to restore the list, then save the current value of the slow pointer
    // and after performing the checks, reverse the second half again as done below
    slow->next = reverse_list(slow->next);
    
    // Now traverse the first half and the reversed second half simultaneously
    // If any mismatch occurs, then its not a palindrom
    fast = head;
    slow = slow->next;
    
    while(slow) {
        if(fast->data != slow->data) return false;
        slow = slow->next;
        fast = fast->next;
    }
    
    return true;
}