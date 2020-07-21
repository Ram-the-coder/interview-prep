/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
    Solution
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        auto cur = root;
        while(cur) {
            if(!cur->left) {
                cur = cur->right;
                continue;
            }
            
            if(!cur->right) {
                cur->right = cur->left;
                cur->left = NULL;
                cur = cur->right;
                continue;
            }
                
            auto pred = cur->left;
            while(pred->right) pred = pred->right;
            
            pred->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
            cur = cur->right;
        }   
    }
};