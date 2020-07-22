/*
    Solution 1:
    Amortized Time Complexity: O(1)
    Space Complexity: O(logn)
*/

class BSTIterator {
    stack<TreeNode*> stk;
    TreeNode* cur;
    
public:
    BSTIterator(TreeNode* root) {
        cur = root;
        while(cur) {
            stk.push(cur);
            cur = cur->left;
        }
    }
    
    /* @return the next smallest number */
    int next() {
        while(cur || !stk.empty()) {
            if(cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                int cur_data = cur->val;
                cur = cur->right;
                return cur_data;
            }
        }
        
        return -1;
    }
    
    /* @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !stk.empty();
    }
};


/*
    Solution - 2 (Morris Traversal)
    Amortized Time Complexity: O(1) [not sure]
    Space Complexity: O(1)
*/
class BSTIterator {
    TreeNode* cur;
    
public:
    BSTIterator(TreeNode* root) : cur(root) {}
    
    /* the next smallest number */
    int next() {        
        while(cur) {
            if(!cur->left) {
                int cur_data = cur->val;
                cur = cur->right;
                return cur_data;
            }
            
            auto pre = cur->left;
            while(pre->right && pre->right != cur) pre = pre->right;
            if(!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = NULL;
                int cur_data = cur->val;
                cur = cur->right;
                return cur_data;
            }    
        }    
        
        return -1;
    }
    
    /* whether we have a next smallest number */
    bool hasNext() {
        return cur != nullptr;
    }
};
