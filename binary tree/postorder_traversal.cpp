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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        get_post(root, traversal);
        return traversal;
    }
    
    void get_post(TreeNode* root, vector<int> &traversal) {
        if(!root) return;
        if(root->left) get_post(root->left, traversal);
        if(root->right) get_post(root->right, traversal);
        traversal.push_back(root->val);
    }
};


// TC: O(n)
// SC: O(n)
// The logic use here is that the reverse of a post order traversal is a preorder traversal with visiting of root->right before root->left
class Iterative_Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if(!root) return traversal;
        stack<TreeNode*> s;

        s.push(root);
        
        while(!s.empty()) {
            auto cur = s.top();
            s.pop();
            traversal.push_back(cur->val);
            if(cur->left) s.push(cur->left);
            if(cur->right) s.push(cur->right);
        }
        
        reverse(traversal.begin(), traversal.end());
        
        return traversal;
    }
};


// TC: O(n)
// SC: O(n) -> To store the results to finally reverse it
// The logic use here is that the reverse of a post order traversal is a preorder traversal with visiting of root->right before root->left
class Morris_Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if(!root) return traversal;
        
        auto cur = root;
        
        while(cur) {
            auto pre = cur->right;
            
            if(!pre) {
                traversal.push_back(cur->val);
                cur = cur->left;
                continue;
            }
            
            while(pre->left && pre->left != cur) pre = pre->left;
            
            if(!pre->left) {
                pre->left = cur;
                traversal.push_back(cur->val);
                cur = cur->right;
            } else {
                pre->left = nullptr;
                cur = cur->left;
            }
        }
        
        reverse(traversal.begin(), traversal.end());
        
        return traversal;
    }
};

