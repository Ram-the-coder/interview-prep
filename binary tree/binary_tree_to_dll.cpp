/*
    Solution 1
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
void util_bt_to_DLL(Node *root, Node* &dll) {
    if(!root) return;

    util_bt_to_DLL(root->left, dll);

    Node *next_node = newNode(root->data);
    next_node->left = dll;
    dll->right = next_node;
    dll = next_node;

    util_bt_to_DLL(root->right, dll);
}

Node *bToDLL(Node *root)
{
    Node *dll_head = newNode(0);
    Node *dll_head_pointer = dll_head;

    util_bt_to_DLL(root, dll_head_pointer);

    Node *to_be_deleted = dll_head;
    dll_head = dll_head->right;
    dll_head->left = NULL;
    delete(to_be_deleted);

    return dll_head;
}

/*
    Solution 2
    Same logic, using double pointer instead of reference to pointer
*/
void util_bt_to_DLL(Node *root, Node **dll) {
    if(!root) return;

    util_bt_to_DLL(root->left, dll);

    Node *next_node = newNode(root->data);
    next_node->left = *dll;
    (*dll)->right = next_node;
    *dll = next_node;

    util_bt_to_DLL(root->right, dll);
}

Node *bToDLL(Node *root)
{
    Node *dll_head = newNode(0);
    Node *dll_head_copy = dll_head;
    Node **dll_head_pointer = &dll_head_copy;

    util_bt_to_DLL(root, dll_head_pointer);
    
    Node *to_be_deleted = dll_head;
    dll_head = dll_head->right;
    dll_head->left = NULL;
    delete(to_be_deleted);

    return dll_head;
}