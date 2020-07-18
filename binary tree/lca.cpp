/*
    Given a Binary Tree with all unique values and two nodes value n1 and n2. 
    The task is to find the lowest common ancestor of the given two nodes. 
    We may assume that either both n1 and n2 are present in the tree or none of them is present. 

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(H).
*/


/* A binary tree node

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

/*
    Solution 1
    Time Complexity: Ω(N*H)
    Space Complexity: O(H)
*/
bool checkPresence(Node *root, int val) {
    if(!root) return false;
    
    if(root->data == val) return true;
    
    return ((root->left && checkPresence(root->left, val)) || 
            (root->right && checkPresence(root->right, val)));
}

/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/
Node* lca(Node* root ,int n1 ,int n2 )
{
   // The tree with root doesn't contain both n1 and n2
   if(!checkPresence(root, n1) || !checkPresence(root, n2)) return NULL;
   
   if(root->data == n1 || root->data == n2) return root;
   
   // No children 
   if(!root->left && !root->right) return NULL; 
   
    // One child
   if(!root->left) return lca(root->right, n1, n2);
   if(!root->right) return lca(root->left, n1, n2);
 
    // Two children present  
    // Both n1 and n2 present in only one of the children
   if(checkPresence(root->left, n1) && checkPresence(root->left, n2)) return lca(root->left, n1, n2);
   if(checkPresence(root->right, n1) && checkPresence(root->right, n2)) return lca(root->right, n1, n2);
   
   // n1 and n2 are present in different children => root is the LCA 
   return root;
}


/*
    Solution 2
    Time Complexity: Ω(N)
    Space Complexity: O(H)
*/
Node* lca(Node* root ,int n1 ,int n2 )
{
    if(!root) return NULL;
   
    if(root->data == n1 || root->data == n2) return root;
   
    Node *lca_left = lca(root->left, n1, n2);
    Node *lca_right = lca(root->right, n1, n2);
    
    // Both left and right do not contain any of n1 and n2
    if(!lca_left && !lca_right) return NULL;
    
    if(!lca_left) return lca_right; // If n1 and n2 not present in left, return lca_right
    if(!lca_right) return lca_left; // If n1 and n2 not present in right, return lca_left
    return root; // If one contains n1 and the other contains n2, only then lca_left != NULL && lca_right !+ NULL. In that case root is the LCA
}