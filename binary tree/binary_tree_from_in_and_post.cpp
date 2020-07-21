/*
    Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. 
    The task is to construct the binary tree from these traversals.
*/

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays

/*
    Solution 1
    Time Complexity: O(n*logn)
    Space Complexity: O(n)
*/
Node *buildTree(int in[], int post[], int n) {
    Node *root = new Node(post[n-1]);
    unordered_map<int, int> index;
    index.reserve(n);
    for(int i=0; i<n; ++i) index[in[i]] = i;
    for(int i=n-2; i>=0; --i) {
        Node *cur = root;
        while(1) {
            if(index[post[i]] == index[cur->data]) break;
            if(index[post[i]] > index[cur->data]) {
                if(!cur->right) {
                    cur->right = new Node(post[i]);
                    break;
                }
                cur = cur->right;
            } else {
                if(!cur->left) {
                    cur->left = new Node(post[i]);
                    break;
                }
                cur = cur->left;
            }
        }
    }
    return root;
}

/*
    Solution 2
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

Node *util_build_tree(int in[], int post[], int in_start, int in_end, int &post_cur, unordered_map<int, int> &in_index) {
    if(in_start > in_end || post_cur < 0) return NULL;
    if(in_index[post[post_cur]] < in_start || in_index[post[post_cur]] > in_end) return NULL;

    Node *new_node = new Node(post[post_cur--]);
    new_node->right = util_build_tree(in, post, in_index[post[post_cur+1]]+1, in_end, post_cur, in_index);
    new_node->left = util_build_tree(in, post, in_start, in_index[post[post_cur+1]]-1, post_cur, in_index);

    return new_node;    
}

Node *buildTree(int in[], int post[], int n) {
    unordered_map<int, int> index;
    index.reserve(n);
    for(int i=0; i<n; ++i) index[in[i]] = i;
    
    int post_cur = n-1;
    Node *root = util_build_tree(in, post, 0, n-1, post_cur, index);
    return root;
}