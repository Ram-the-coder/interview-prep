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

 // TC: O(n)
 // SC: O(n) -> function call stack
class Recursive_Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        get_inorder_traversal(root, traversal);
        return traversal;
    }
    
    void get_inorder_traversal(TreeNode* root, vector<int> &traversal) {
        if(!root) return;
        if(root->left) get_inorder_traversal(root->left, traversal);
        traversal.push_back(root->val);
        if(root->right) get_inorder_traversal(root->right, traversal);
    }
};

// TC: O(n)
// SC: O(n) - user stack
class Iterative_Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> dfs;
        TreeNode* cur = root;
        while(cur || !dfs.empty()) {
            while(cur) {
                dfs.push(cur);
                cur = cur->left;
            }
            
            cur = dfs.top();
            dfs.pop();
            
            traversal.push_back(cur->val);
            
            cur = cur->right;
        }
        
        return traversal;
    }
};

// TC: O(n)
// SC: O(1)
class Morris_Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        TreeNode* cur = root;
        while(cur) {
            
            if(!cur->left) {
                traversal.push_back(cur->val);
                cur = cur->right;
                continue;
            }
            
            auto pre = cur->left;
            while(pre->right && pre->right != cur) pre = pre->right;
            if(!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                traversal.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return traversal;
    }
};