/*
    Solution 1
    Time Complexity: O(V + E + V*logV) = O(V*logV + E)
    Space Complexity: O(V)

    Logic: If we do a dfs and calculate the max length of the chain starting from a node.
    then the topological sorted order is nothing but the ordering of nodes in descending order of chain length
*/
int get_chain_len(int v, vector<int> adj[], vector<pair<int, int>> &chain_len) {
    if(chain_len[v].first != -1) return chain_len[v].first;
    
    chain_len[v].first = 1;
    for(int neighbor : adj[v]) {
        chain_len[v].first = max(chain_len[v].first, get_chain_len(neighbor, adj, chain_len) + 1);
    }
    return chain_len[v].first;
}

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
vector<int> topoSort(int v, vector<int> adj[]) {
    
    vector<pair<int, int>> chain_len(v);
    for(int i=0; i<v; ++i) {
        chain_len[i] = {-1, i};
    }
    
    for(int i=0; i<v; ++i) {
        if(chain_len[i].first != -1) continue;
        get_chain_len(i, adj, chain_len);
    }
    
    sort(chain_len.begin(), chain_len.end(), greater<pair<int,int>>());
    
    vector<int> res(v);
    for(int i=0; i<v; ++i) {
        res[i] = chain_len[i].second;
    }
    
    return res;
}

/*
    Solution 2
    Time Complexity: O(V + E)
    Space Complexity: O(V)

    In this method, we've removed the overhead of sorting by using a stack and 
    pushing a node to the stack only when all its children have been pushed - this means that 
    we're pushing all the nodes that come after a node into the stack before it is pushed.
*/

void util_topo_sort(int start_vertex, int v, vector<int> adj[], stack<int> &s, vector<int> &visited) {
    visited[start_vertex] = 1;
    for(int neighbor : adj[start_vertex]) {
        if(visited[neighbor]) continue;
        util_topo_sort(neighbor, v, adj, s, visited);
    }
    s.push(start_vertex);
}

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
vector<int> topoSort(int v, vector<int> adj[]) {
    stack<int> s;
    vector<int> visited(v, 0);
    for(int i=0; i<v; ++i) {
        if(visited[i]) continue;
        util_topo_sort(i, v, adj, s, visited);
    }
    
    vector<int> res;
    while(!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    
    return res;
}
