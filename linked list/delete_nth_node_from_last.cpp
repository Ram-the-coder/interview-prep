/*
    Given a linked list, remove the n-th node from the end of list and return its head.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ahead = head, *behind = head;
        
        // Move the ahead pointer n+1 spaces ahead
        int i;
        for(i=0; i<=n && ahead; ++i) {
            ahead = ahead->next;
        }
        
        if(i < n) return head; // Invalid node to be deleted
        
        // If i == n, the node to be deleted is the first node
        if(i == n) {
            ListNode *to_be_deleted = head;
            head = head->next;
            if(to_be_deleted) delete(to_be_deleted);
            return head;
        }
        
        // At the end of this loop, the behind pointer will be exactly before the node to be deleted
        while(ahead) {
            ahead = ahead->next;
            behind = behind->next;
        }        
        
        if(!behind->next) return head; // Invalid node to be deleted, do nothing

        ListNode *to_be_deleted = behind->next;
        behind->next = behind->next->next;
        delete(to_be_deleted);
        return head;
    }
};