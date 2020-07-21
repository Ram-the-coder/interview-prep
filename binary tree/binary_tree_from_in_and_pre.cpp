/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

/*
    Solution
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
Node *util_build_tree(int in[], int pre[], int in_start, int in_end, int &pre_cur, const int &n, unordered_map<int, int> &in_index) {
    if(pre_cur >= n) return NULL;
    if(in_index[pre[pre_cur]] < in_start || in_index[pre[pre_cur]] > in_end) return NULL;

    Node *new_node = new Node(pre[pre_cur++]);
    new_node->left = util_build_tree(in, pre, in_start, in_index[pre[pre_cur-1]]-1, pre_cur, n, in_index);
    new_node->right = util_build_tree(in, pre, in_index[pre[pre_cur-1]]+1, in_end, pre_cur, n, in_index);
    
    return new_node;
}
Node* buildTree(int in[],int pre[], int n) {
    unordered_map<int, int> in_index;
    in_index.reserve(n);
    for(int i=0; i<n; ++i) in_index[in[i]] = i;

    int pre_cur = 0;
    Node *root = util_build_tree(in, pre, 0, n-1, pre_cur, n, in_index);
    return root;
}