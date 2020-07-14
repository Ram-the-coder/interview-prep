/*
    Solution
    TC: O(n)
    SC: O(n)
*/
void get_bottom_view(Node *root, int hd, int level, map<int, pair<int, int>> &umap) {
    if(!root) return;
    if(umap.find(hd) == umap.end() || umap[hd].second <= level) {
        umap[hd] = {root->data, level};
    }
    
    if(root->left) get_bottom_view(root->left, hd-1, level+1, umap);
    if(root->right) get_bottom_view(root->right, hd+1, level+1, umap);
}

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
    vector<int> bottom_view;
    map<int, pair<int, int>> umap;
    // umap[i] = pair(data, level) of the bottom most node 
    // which is at a horizontal distance of i from the root
    get_bottom_view(root, 0, 0, umap);
    
    for(auto node : umap) {
        bottom_view.push_back(node.second.first);
    }
    
    return bottom_view;
}