/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/***** Solution 1 *****/
void find_height(Node *root, int cur_ht, int &max_ht) {
    max_ht = max(max_ht, cur_ht);
    if(root->left) find_height(root->left, cur_ht+1, max_ht);
    if(root->right) find_height(root->right, cur_ht+1, max_ht);
}


// return the Height of the given Binary Tree
int height(Node* root)
{
   // Your code here
   int max_ht = 0;
   find_height(root, 1, max_ht);
   return max_ht;
}


/***** Solution 2 *****/
int height(Node *root) {
    if(!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}