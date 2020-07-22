/*
    Solution - Same logic as kth smallest element
    Time Complexity: O(n)
    Space Complexity: O(h) [can be optimized to O(1) using morris traversal]
*/

int util_kth_largest(Node *root, int &k) {
    if(!root) return -1;
    
    int kth_largest_in_right_subtree = util_kth_largest(root->right, k);
    if(kth_largest_in_right_subtree != -1) return kth_largest_in_right_subtree;
    
    if(k == 1) return root->data;
    
    return util_kth_largest(root->left, --k);
}

// return the Kth largest element in the given BST rooted at 'root'
int kthLargest(Node *root, int K)
{
    return util_kth_largest(root, K);
}