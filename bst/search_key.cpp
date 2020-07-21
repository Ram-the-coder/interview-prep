/*
    Given the root node of a binary search tree (BST) and a value. 
    You need to find the node in the BST that the node's value equals the given value. 
    Return the subtree rooted with that node. 
    If such node doesn't exist, you should return NULL.
*/

// SOlution
// TC: O(logn)
// SC: O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && root->val != val)
            root = (val > root->val) ? root->right : root->left;
        return root;
    }
};