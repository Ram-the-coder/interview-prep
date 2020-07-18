/*
    Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(H).

    Constraints:
    1 <=T <= 100
    3 <= N <= 104
    -1000 <= Data on Node <= 1000
*/

/*
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

// This function returns the value of the maximum sum path from root to any leaf under it
// It also updates the max_sum variable to contain the value of the maximum sum path from one leaf to another in the whole tree
int util_max_path_sum(Node *root, int &max_sum) {
    if(!root) return 0;
    
    int sum_left = util_max_path_sum(root->left, max_sum);
    int sum_right = util_max_path_sum(root->right, max_sum);
    
    if(root->left && root->right) {
        // allowed to change max_sum only if root contains both sub-trees since the ends of the path need to be leaf nodes
        max_sum = max(max_sum, sum_left + root->data + sum_right);
        return max(sum_left, sum_right) + root->data;
    }
    
    if(root->left) return sum_left + root->data;
    
    if(root->right) return sum_right + root->data;
    
    return root->data;
}

int maxPathSum(Node* root)
{ 
    int max_sum = INT_MIN;
    util_max_path_sum(root, max_sum);
    return max_sum;
}