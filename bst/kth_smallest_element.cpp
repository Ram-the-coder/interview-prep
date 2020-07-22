/*
    Solution 1
    Time Complexity: O(n)
    Space Complexity: O(logn)
*/
int util_kth_smallest(Node *root, int &k) {
    if(!root) return -1;
    
    int chk_left = util_kth_smallest(root->left, k);
    if(chk_left != -1) return chk_left;
    
    if(k == 1) return root->data;
    
    return util_kth_smallest(root->right, --k);
}

// Return the Kth smallest element in the given BST 
int KthSmallestElement(Node *root, int K)
{
    return util_kth_smallest(root, K);
}

/*
    Other solutions:
    1. The space complexity can be improved to O(1) by using Morris Traversal
    2. The time complexity can be improved to O(h) by storing the lCount of the element when building the tree itself.
        lCount of a node = No. of elements in left subtree
        If lCount = k, then its the kth element
        https://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/
*/