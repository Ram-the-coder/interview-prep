/*
    Given a Binary Search Tree and a target number, 
    return true if there exist two elements in the BST such that their sum is equal to the given target.
*/

/*
    Other Solutions:
    Time Complexity: O(n)
    Space Complexity: O(n)
    1. Traverse and store the values in a hash set. For every node, check if k - val is present, if present that return true.
    2. Do inorder traversal, store in array. Now the problem reduces to finding a pair of numbers that sum to a given value in a sorted array.
         Use two pointers - l and r, pointing to the beginning and the end of the array
        1) Check if the sum of the elements pointed by ll and rr is equal to the required sum kk. If so, return a True immediately.
        2) Otherwise, if the sum of the current two elements is lesser than the required sum kk, update ll to point to the next element. This is done, because, we need to increase the sum of the current elements, which can only be done by increasing the smaller number.
        3)Otherwise, if the sum of the current two elements is larger than the required sum kk, update rr to point to the previous element. This is done, because, we need to decrease the sum of the current elements, which can only be done by reducing the larger number.
        4)Continue steps 1. to 3. till the left pointer ll crosses the right pointer rr.
        5)If the two pointers cross each other, return a False value.
*/

/*
    Solution
    Time Complexity: O(n)
    Space Complexity: O(logn)

    Logic is same as using a left and right pointer, except that we do not reduce the BST to an array, instead we do it using a BST_Iterator
*/
class BST_Iterator {
    
    stack<TreeNode*> stk;
    TreeNode* current_node;
    bool forward;
    
public:
    
    BST_Iterator(TreeNode* root, bool fwd) : current_node(root), forward(fwd) {}
    
    int next() {
        while(current_node || !stk.empty()) {
            if(current_node) {
                stk.push(current_node);
                current_node = forward ? current_node->left : current_node->right;    
            } else {
                current_node = stk.top();
                stk.pop();
                int current_val = current_node->val;
                current_node = forward ? current_node->right : current_node->left;
                return current_val;
            }
        }
        return -1;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BST_Iterator imin(root, true), imax(root, false);
        int low = imin.next(), high = imax.next();
        while(low < high) {
            if(low + high == k) return true;
            if(low + high < k) low = imin.next();
            else high = imax.next();
        }
        return false;
    }
};