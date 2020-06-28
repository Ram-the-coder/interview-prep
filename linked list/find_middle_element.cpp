/* Method 1: 2 passes */
int getMiddle(Node *head)
{
   if(!head) return -1;
   int len = 0, cur_len;
   Node *cur;
   for(cur = head; cur; cur = cur->next, ++len);
   for(cur = head, cur_len = 0; cur_len < len/2 && cur; cur = cur->next, ++cur_len);
   return cur->data;
}

/* Method 1: 1 pass - using slow and fast pointers*/
int getMiddle(Node *head)
{
   if(!head) return -1;
   int len = 0, cur_len;
   Node *slow, *fast;
   for(slow = head, fast = head; fast && fast->next; ) {
       slow = slow->next;
       fast = fast->next->next;
   }
   return slow->data;
}