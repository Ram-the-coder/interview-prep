int Ceil(node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1; 
  
    // We found equal key 
    if (root->key == input) 
        return root->key; 
  
    // If root's key is smaller, ceil must be in right subtree 
    if (input > root->key) 
        return Ceil(root->right, input); 
  
    // Else, either left subtree or root has the ceil value 
    int ceil_left = Ceil(root->left, input); 
    return (ceil_left >= input) ? ceil_left : root->key; 
}

int Floor(node *root, int input) {
    // Base case 
    if (root == NULL) 
        return -1; 
  
    // We found equal key 
    if (root->key == input) 
        return root->key; 

    // If root's key is greater, floor must be in left subtree 
    if (input < root->key) 
        return Floor(root->left, input); 
  
    // Else, either right subtree or root has the floor value 
    int floor_right = Ceil(root->right, input); 
    return (floor_right <= input) ? floor_right : root->key; 
}