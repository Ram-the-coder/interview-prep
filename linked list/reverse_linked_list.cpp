// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{   
    Node *next, *prev = NULL;
    for(Node *cur = head; cur; cur = next) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}