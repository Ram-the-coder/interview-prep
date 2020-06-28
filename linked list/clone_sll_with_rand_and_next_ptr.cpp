/* 
    Solution 1:
    Time Complexity: O(n)
    Extra Space Complexity: O(n)
*/

Node *copyList(Node *head) {
    Node *res = new Node(-1);
    unordered_map<Node*, Node*> umap;
    
    // Create copy list with mapping of original node index to copy node index
    for(Node *cur = head, *rcur = res; cur; cur = cur->next, rcur = rcur->next) {
        rcur->next = new Node(cur->data);
        umap[cur] = rcur->next;
    }
    
    // Use the mapping to set arbitrary links
    for(Node *cur = head, *rcur = res->next; cur; cur = cur->next, rcur = rcur->next) {
        rcur->arb = umap[cur->arb] ? umap[cur->arb] : NULL;
    }
    
    return res->next;
}

/*
    Solution 2:
    Time Complexity: O(n)
    Extra Space Complexity: O(1)
*/

Node *copyList(Node *head) {
    // Create the copy node in between the current node and the next node
    for(Node *cur = head; cur; cur = cur->next->next) {
        Node *next = cur->next;
        cur->next = new Node(cur->data);
        cur->next->next = next;
    }
    
    for(Node *cur = head; cur; cur = cur->next->next) {
        cur->next->arb = cur->arb ? cur->arb->next : NULL;
    }
    
    // Delink the two lists
    Node *head_of_copy = head->next;
    for(Node *cur = head, *ccur = head_of_copy; cur; cur = cur->next, ccur = ccur->next) {
        cur->next = ccur->next;
        ccur->next = ccur->next ? ccur->next->next : NULL;
    }
    
    return head_of_copy;   
}