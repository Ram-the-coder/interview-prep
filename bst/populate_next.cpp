/*
    You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 

    The binary tree has the following definition:
    struct Node {
        int val;
        Node *left;
        Node *right;
        Node *next;
    }
    
    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

    Initially, all next pointers are set to NULL.
*/

/*
    Solution 1
    TC: O(nlogn)
    SC: O(logn)
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        for(Node *ld=root->left, *rd=root->right; ld && rd; ld = ld->right, rd = rd->left) {
            ld->next = rd;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

/*
    Solution 2
    TC: O(n)
    SC: O(logn)
*/
class Solution {    
public:
    Node* connect(Node* root, Node *next = NULL) {
        if(!root) return NULL;
        if(next) root->next = next;
        connect(root->left, root->right);
        connect(root->right, next ? next->left : NULL);
        return root;
    }
};

/*
    Solution 3
    TC: O(n)
    SC: O(1)
*/
class Solution {    
public:
    Node* connect(Node* root) {
        Node *level = root;
        while(level) {
            Node *cur = level;
            while(cur) {
                if(cur->left) cur->left->next = cur->right;
                if(cur->right && cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            level = level->left;
        }
        return root;
    }
};