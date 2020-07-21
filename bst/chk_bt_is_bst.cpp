
/*
    Given a binary tree. Check whether it is a BST or not.
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

bool util_is_bst(Node *root, int min, int max) {
    if(!root) return true;
    if(min >= root->data || max <= root->data) return false;
    return util_is_bst(root->left, min, root->data) && util_is_bst(root->right, root->data, max);
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    int prev = INT_MIN;
    return util_is_bst(root, INT_MIN, INT_MAX);
}