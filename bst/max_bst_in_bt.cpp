/*
    Given a binary tree. Find the size(no. of elements) of its largest subtree that is a Binary Search Tree.

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the BST).

    Constraints:
    1 <=T <= 10
    1 <= Number of nodes <= 100000
    1 <= Data of a node <= 1000000
*/

/*
    Solution
    Time Complexity: O(n)
    Space Complexity: O(logn)
*/
void util_lbst(Node *root, int &low, int &high, int &bst_subtree_size, int &max_size) {
    if(!root) {
        bst_subtree_size = 0;
        low = high = -1; // low and high are undefined
        return;
    }
    
    int llow, lhigh, rlow, rhigh, lbst, rbst;
    util_lbst(root->left, llow, lhigh, lbst, max_size);
    util_lbst(root->right, rlow, rhigh, rbst, max_size);
    
    // if any one of the subtrees is not a bst, then this tree is not a bst
    if(lbst == -1 || rbst == -1) {
        bst_subtree_size = -1;
        return;
    }
    
    if((lhigh == -1 || lhigh < root->data) && (rlow == -1 || rlow > root->data)) {
        low = llow == -1 ? root->data : llow;
        high = rhigh == -1 ? root->data : rhigh;
        bst_subtree_size = lbst + rbst + 1;
        max_size = max(max_size, bst_subtree_size);
    } else {
        bst_subtree_size = -1;
        return;
    }
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root) {
    int max_ht = 0;
    int low, high, bst_st_h;
    util_lbst(root, low, high, bst_st_h, max_ht);
    return max_ht;
}