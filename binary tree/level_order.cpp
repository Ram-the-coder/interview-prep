/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//You are required to complete this method
vector<int> levelOrder(Node* node)
{
  //Your code here
  vector<int> traversal;
  queue<Node*> q;
  q.push(node);
  while(!q.empty()) {
      Node *fr = q.front();
      q.pop();
      traversal.push_back(fr->data);
      if(fr->left) q.push(fr->left);
      if(fr->right) q.push(fr->right);
  }
  
  return traversal;
}