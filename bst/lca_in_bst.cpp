/*
    Given a Binary Search Tree (with all values unique) and two node values. 
    Find the Lowest Common Ancestors of the two nodes in the BST.
*/

/*
    Solution 1
    Time Complexity: O(logn)
    Space Complexity: O(logn) without tail call optimization, O(1) with tail call optimization
*/
Node* LCA(Node *root, int n1, int n2)
{
    if(n1 == root->data || n2 == root->data) return root;
    if(n1 < root->data && n2 > root->data) return root;
    if(n1 > root->data && n2 < root->data) return root;
    return (n1 < root->data) ? LCA(root->left, n1, n2) : LCA(root->right, n1, n2);
}

/*
    Solution 1
    Time Complexity: O(logn)
    Space Complexity: O(1)
*/
Node* LCA(Node *root, int n1, int n2)
{
    while(root) {
        if(n1 == root->data || n2 == root->data) return root;
        if(n1 < root->data && n2 > root->data) return root;
        if(n1 > root->data && n2 < root->data) return root;
        root = (n1 < root->data) ? root->left : root->right;
    }
    
    return NULL;
}