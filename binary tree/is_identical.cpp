/*
    Given two binary trees, the task is to find if both of them are identical or not. 
    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the Tree).
*/

/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    if(!r1 && !r2) return true;
    if(!r1 || !r2) return false;
    return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}