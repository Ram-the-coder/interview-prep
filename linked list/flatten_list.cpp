/*
  Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
  (i) a next pointer to the next node,
  (ii) a bottom pointer to a linked list where this node is head. (Assume this list is already sorteed)

  You have to flatten the linked list to a single linked list which should be sorted.

  Note: The flattened list will be printed using the bottom pointer instead of next pointer.

  Expected Time Complexity: O(N*M)
  Expected Auxiliary Space: O(1)
*/

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

// The same algorithm as used in merge_sorted_linked_lists.cpp
Node *merge(Node *head_A, Node *head_B) {
    Node *res = new Node(-1);
    Node *cur = res;
    Node *cur_a = head_A, *cur_b = head_B;
    while(cur_a && cur_b) {
        if(cur_a->data < cur_b->data) {
            cur->bottom = cur_a;
            cur_a = cur_a->bottom;
        } else {
            cur->bottom = cur_b;
            cur_b = cur_b->bottom;
        }
        cur = cur->bottom;
    }
    
    cur->bottom = cur_a ? cur_a : cur_b;
    
    cur = res->bottom;
    delete(res);
    return cur;
}

/*  Function which returns the  root of the flattened linked list. */
Node *flatten(Node *root)
{
   while(root->next) {
       Node *next_to_next = root->next->next;
       root = merge(root, root->next);
       root->next = next_to_next;
   }
   
   return root;
}