bool isSymmetric(struct Node* root)
{
    if(!root) return true;

    stack<Node*> ldfs, rdfs;

    ldfs.push(root);
    rdfs.push(root);

    while(!ldfs.empty() && !rdfs.empty()) {
        Node *ltop = ldfs.top(); ldfs.pop();
        Node *rtop = rdfs.top(); rdfs.pop();

        if(ltop->data != rtop->data || ((bool)ltop->left ^ (bool)rtop->right) || ((bool)ltop->right ^ (bool)rtop->left)) return false;

        if(ltop->left) {
            ldfs.push(ltop->left);
            rdfs.push(rtop->right);
        }

        if(ltop->right) {
            ldfs.push(ltop->right);
            rdfs.push(rtop->left);
        }
    }

    return (ldfs.empty() && rdfs.empty());
}