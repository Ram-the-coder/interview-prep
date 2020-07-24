/*
    Given a graph with N nodes and M directed edges. Your task is to complete the function kosaraju() 
    which returns an integer denoting the number of strongly connected components in the graph.

    A directed graph is strongly connected if there is a path between all pairs of vertices. 
    A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. 
*/

/*
    Time Complexity: O(V+E)
    Space Complexity: O(V)
*/

void dfs_util(int i, int v, vector<int> adj[], stack<int> &sequence, bool use_sequence, vector<int> &visited) {
    visited[i] = 1;
    for(int neighbor : adj[i]) {
        if(visited[neighbor]) continue;
        dfs_util(neighbor, v, adj, sequence, use_sequence, visited);
    }
    
    if(use_sequence) sequence.push(i);
}

void reverse_edges(int v, vector<int> adj[], vector<int> reverse_graph[]) {
    for(int i=0; i<v; ++i) {
        for(int neighbor : adj[i]) {
            reverse_graph[neighbor].push_back(i);
        }
    }
}

/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
int kosaraju(int v, vector<int> adj[])
{
    stack<int> sequence;
    vector<int> visited(v, 0);
    
    for(int i=0; i<v; ++i) {
        if(visited[i]) continue;
        dfs_util(i, v, adj, sequence, true, visited);
    }
    
    vector<int> reverse_graph[v];
    reverse_edges(v, adj, reverse_graph);
    visited.clear();
    visited.resize(v, 0);
    int nscc = 0;
    while(!sequence.empty()) {
        int i = sequence.top();
        if(!visited[i]) {
            dfs_util(i, v, reverse_graph, sequence, false, visited);
            ++nscc;
        }
        sequence.pop();
    }
    
    return nscc;
}