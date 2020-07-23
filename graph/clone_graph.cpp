/*
    Given a reference of a node in a connected undirected graph.

    Return a deep copy (clone) of the graph.

    Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
    Iterative DFS Solution
*/
class Solution {
public:
    Node* cloneGraph(Node* root) {
        if(!root) return NULL;
        
        unordered_map<Node*, Node*> old_to_new;
        
        Node* clone = new Node(root->val);
        old_to_new[root] = clone;
        
        stack<Node*> s;
        s.push(root);
        
        while(!s.empty()) {
            auto node = s.top();
            s.pop();
            
            auto new_node = old_to_new[node];
            
            for(Node* neighbor: node->neighbors) {
                if(old_to_new.find(neighbor) != old_to_new.end()) {
                    new_node->neighbors.push_back(old_to_new[neighbor]);    
                    continue;
                }
                
                s.push(neighbor);
                auto neighbor_clone = new Node(neighbor->val);
                old_to_new[neighbor] = neighbor_clone;
                new_node->neighbors.push_back(neighbor_clone);
            }
        }
        
        return clone;
    }
};

/*
    Recursive DFS solution
*/
class Solution {
private:
    unordered_map<Node*, Node*> clone;    
public:
    Node* cloneGraph(Node* root) {
        if(!root) return NULL;
        
        if(clone.find(root) == clone.end()) {
            Node *copy = new Node(root->val);
            clone[root] = copy;
            for(auto neighbor : root->neighbors)
                clone[root]->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return clone[root];
    }
};