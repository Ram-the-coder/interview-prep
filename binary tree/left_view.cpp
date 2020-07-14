/*
    Solution 1 - BFS
    TC: O(n)
    SC: O(n)
*/
void leftView(Node *root)
{
    queue<Node*> q;
    if(root) q.push(root);
    q.push(NULL);
    bool left_found = false;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(!cur) {
            if(q.empty()) break;
            q.push(NULL);
            left_found = false;
            continue;
        }
        
        if(!left_found) {
            cout << cur->data << " ";
            left_found = true;
        }
        
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}

/*
    Solution 2 - DFS
    TC: O(n)
    SC: O(n)
*/

void get_left_view(Node *root, int cur_level, int &max_level_so_far) {
    if(!root) return;
    
    if(cur_level > max_level_so_far) {
        max_level_so_far = cur_level;
        cout << root->data << " ";
    }
    
    if(root->left) get_left_view(root->left, cur_level+1, max_level_so_far);
    if(root->right) get_left_view(root->right, cur_level+1, max_level_so_far);
}

void leftView(Node *root)
{
    int max_level = -1;
    get_left_view(root, 0, max_level);
}