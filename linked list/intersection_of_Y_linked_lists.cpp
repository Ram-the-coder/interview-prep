/*
    Write a program to find the node at which the intersection of two singly linked lists begins.
    Expected Time Complexity: O(n)
    Expected Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Find the length of list a and list b
        int len_a = 0, len_b = 0;
        for(auto cur = headA; cur; cur = cur->next, ++len_a);
        for(auto cur = headB; cur; cur = cur->next, ++len_b);
        
        // Move the cur pointer of the longer list ahead so that there exists equal number of
        // elements to the right of both lists' cur pointer
        auto cur_a = headA, cur_b = headB;
        
        if(len_a >= len_b) {
            for(int i=0; i<len_a - len_b; ++i)    
                cur_a = cur_a->next;
        } else {
            for(int i=0; i<len_b - len_a; ++i)    
                cur_b = cur_b->next;
        }
        
        // Keep moving the cur pointers one step, till they intersect
        while(cur_a != cur_b) {
            cur_a = cur_a->next;
            cur_b = cur_b->next;
        }
        
        return cur_a;
    }
};