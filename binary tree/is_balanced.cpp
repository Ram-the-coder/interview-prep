bool util_is_balanced(Node *root, int &height) {
    if(!root) {
        height = 0;
        return true;
    }
    int ht_left, ht_right;
    bool left_balance = util_is_balanced(root->left, ht_left);
    bool right_balance = util_is_balanced(root->right, ht_right);
    height = max(ht_left, ht_right) + 1;
    return left_balance && right_balance && (abs(ht_left - ht_right) <= 1);
}

// This function should return tree if passed  tree 
// is balanced, else false. 
bool isBalanced(Node *root)
{
    int ht;
    return util_is_balanced(root, ht);
}