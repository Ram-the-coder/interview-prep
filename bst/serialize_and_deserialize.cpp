/*
    Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. 

    Now your task is to complete the function serialize which stores the tree into an array A[ ] 
    and deSerialize which deserializes the array to tree and returns it.

    Note: The structure of tree must be maintained.
*/


/*
    If the given tree is a *BST* then we can store it by either storing only preorder or postorder traversal.

    If the given tree is a *Complete Tree*, i.e. all level are completely filled except possibly the last level where all nodes are as left
    as possible, level order traversal is sufficient to store the tree. For an element i, 2*i + 1 will be left child and 2*i + 2 will be right child

    If the given tree is a full tree, i.e. all nodes have 0 or 2 children, then just store the preorder traversal along with a but with
    every node to indicated whether its a leaf node or an internal node.

    To store a general binary tree, we can store both the preorder and inorder traversal. - Requires 2*n space
    A better approach is to store the preorder traversal with a marker for NULL pointers - Requires O(n) space
    The second approach is implemented below
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

/*this  function serializes the binary tree and stores it in the vector A*/
void serialize(Node *root,vector<int> &A)
{
    if(!root) {
        A.push_back(-1); // null marker
        return;
    }
    
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}

/*this function deserializes the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
    if(!A.size() || A[0] == -1) return NULL;

    Node *root = new Node(A[0]);
    
    stack<pair<Node*, int>> stk;
    // {node, 0} indicates the left subtree of node needs to be filled
    // {node, 1} indicates the right subtree of node needs to be filled
    
    stk.push(make_pair(root, 0));
    
    for(int i=1; i<A.size(); ++i) {
        
        auto cur = stk.top();
        stk.pop();
        
        switch(cur.second) {
            case 0:
                cur.first->left = A[i] == -1 ? NULL : new Node(A[i]);
                stk.push(make_pair(cur.first, 1));
                if(A[i] != -1) stk.push(make_pair(cur.first->left, 0));
                break;
                
            case 1:
                cur.first->right = A[i] == -1 ? NULL : new Node(A[i]);
                if(A[i] != -1) stk.push(make_pair(cur.first->right, 0));
                break;
                
            default: break;
        }
    }
    
    return root;
}