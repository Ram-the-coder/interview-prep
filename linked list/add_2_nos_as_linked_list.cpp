/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode *cur = res;

        int a, b, sum = 0, carry = 0;

        do {
            cur->next = new ListNode();
            cur = cur->next;

            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            sum = a + b + carry;

            carry = sum / 10;
            sum %= 10;

            cur->val = sum;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
        } while(l1 || l2 || (carry > 0));
        
        ListNode *head = res->next;
        delete(res);
        return head;
    }
};