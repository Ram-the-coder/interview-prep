int find_diameter(Node *node, int &height) {
    if(!node) return height = 0;
    int ht_left, ht_right; 
    int diameter_left = find_diameter(node->left, ht_left);
    int diameter_right = find_diameter(node->right, ht_right);
    int diameter_with_root = ht_left + 1 + ht_right;
    height = max(ht_left, ht_right) + 1;
    return max(diameter_left, max(diameter_right, diameter_with_root));
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    int ht;
    return find_diameter(node, ht);
}