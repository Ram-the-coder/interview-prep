/*
    There is BST given with root node with key part as integer only. 
    You need to find the inorder successor and predecessor of a given key. 
    In case, if the either of predecessor or successor is not found print -1.

    Constraints:
    1<=T<=100
    1<=n<=100
    1<=data of node<=100
    1<=key<=100

    Example:
    Input:
    2
    6
    50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
    65
    6
    50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
    100

    Output:
    60 70
    80 -1
*/



/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

/*
    Solution 1
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
void inorder(Node *root, vector<Node*> &traversal) {
    if(!root) return;
    inorder(root->left, traversal);
    traversal.push_back(root);
    inorder(root->right, traversal);
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    vector<Node*> inorder_traversal;
    inorder(root, inorder_traversal);
    
    // Finding predecessor
    int low = 0, high = inorder_traversal.size()-1, mid;
    while(low <= high) {
        mid = (high + low) / 2;
        if(key <= inorder_traversal[mid]->key) {
            high = mid - 1;
            continue;
        }
        
        pre = inorder_traversal[mid];
        low = mid + 1;
    }
    
    // Finding successor
    low = 0; 
    high = inorder_traversal.size()-1;
    
    while(low <= high) {
        mid = (high + low) / 2;
        if(key >= inorder_traversal[mid]->key) {
            low = mid + 1;
            continue;
        }
        
        suc = inorder_traversal[mid];
        high = mid - 1;
    }
}


/*
    Soluution 2
    Time Complexity: O(logn)
    Space Complexity: O(logn) [tail end recursive stack space]
*/
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if(!root) return;
    
    if(root->key == key) {
        if(root->left) {
            pre = root->left;
            while(pre->right) pre = pre->right;
        }
        
        if(root->right) {
            suc = root->right;
            while(suc->left) suc = suc->left;
        }
        
        return;
    }
    
    if(key < root->key) {
        suc = root;
        return findPreSuc(root->left, pre, suc, key);
    }
    
    pre = root;
    return findPreSuc(root->right, pre, suc, key);
}