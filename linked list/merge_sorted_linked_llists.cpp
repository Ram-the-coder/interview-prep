/*
  Given two sorted linked lists consisting of N and M nodes respectively. 
  The task is to merge both of the list (in-place) and return head of the merged list.
  Expected Time Complexity : O(n+m)
  Expected Auxilliary Space : O(1)
*/

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
   Node *new_head; // The head of the merged linked list
   Node *cur, *a_cur = head_A, *b_cur = head_B;
   
   if(head_A->data < head_B->data) {
       cur = new_head = head_A;
       a_cur = a_cur->next;
   } else {
       cur = new_head = head_B;
       b_cur = b_cur->next;
   }
   
   while(a_cur && b_cur) {
       if(a_cur->data < b_cur->data) {
           cur->next = a_cur;
           a_cur = a_cur->next;
       } else {
           cur->next = b_cur;
           b_cur = b_cur->next;
       }
       cur = cur->next;
   }
   
   cur->next = a_cur ? a_cur : b_cur;
   return new_head;
}  