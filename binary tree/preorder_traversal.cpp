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
 // SC: O(n)
class Recursive_Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        get_pre(root, traversal);
        return traversal;
    }
    
    void get_pre(TreeNode* root, vector<int> &traversal) {
        if(!root) return;
        traversal.push_back(root->val);
        if(root->left) get_pre(root->left, traversal);
        if(root->right) get_pre(root->right, traversal);
    }
};


// TC: O(n)
 // SC: O(n)
class Iterative_Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if(!root) return traversal;
        
        stack<TreeNode*> dfs;
        auto cur = root;
        
        dfs.push(cur);
        
        while(!dfs.empty()) {
            cur = dfs.top();
            dfs.pop();
            traversal.push_back(cur->val);
            if(cur->right) dfs.push(cur->right);
            if(cur->left) dfs.push(cur->left);
        }
        
        return traversal;
    }
};

// TC: O(n)
 // SC: O(1)
class Morris_Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if(!root) return traversal;
        
        auto cur = root;
        
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
                traversal.push_back(cur->val);
                cur = cur->left;
            } else {
                pre->right = nullptr;
                cur = cur->right;
            }
        }
        
        return traversal;
    }
};