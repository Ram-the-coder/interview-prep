/*
    Solution
    TC: O(n)
    SC: O(n)
*/

void get_top(struct Node *root, int hd, int level, map<int, pair<int, int>> &umap) {
    if(!root) return;
    if(umap.find(hd) == umap.end() || umap[hd].second > level) {
        umap[hd] = {root->data, level};
    }
    if(root->left) get_top(root->left, hd-1, level+1, umap);
    if(root->right) get_top(root->right, hd+1, level+1, umap);
}
void topView(struct Node *root)
{
    map<int, pair<int, int>> umap;
    // umap[i] = pair(data, level) of the top most node 
    // which is at a horizontal distance of i from the root
    get_top(root, 0, 0, umap);
    for(auto node : umap) {
        cout << node.second.first << " ";
    }
}