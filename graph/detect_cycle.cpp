/**************************************** Undirected Graph ****************************************/

/*
    Solution
    Time Complexity: O(V+E).
    The program does a simple DFS Traversal of the graph which is represented using adjacency list. So the time complexity is O(V+E).

    Space Complexity: O(V).
    To store the visited array O(V) space is required
*/

bool dfs_chk_loop(const vector<int> adj[], int v, int start_vertex, int prev, vector<int> &visited) {
    // if(visited[start_vertex]) return true; This is not needed as we're checking this before calling the function
    visited[start_vertex] = true;
    for(int neighbor : adj[start_vertex]) {
        if(neighbor == prev) continue;
        if(visited[neighbor]) return true;
        if(dfs_chk_loop(adj, v, neighbor, start_vertex, visited)) return true;
    }
    return false;
}

/* This function is used to detect a cycle in undirected graph

*  adj[]: array of vectors to represent graph
*  v: number of vertices
*/
bool isCyclic(vector<int> adj[], int v) {
    vector<int> visited(v, 0);
    for(int i=0; i<v; ++i) {
        if(visited[i]) continue;
        if(dfs_chk_loop(adj, v, i, -1, visited)) return true;
    }
    return false;
}

/**************************************** Directed Graph ****************************************/
/*
    Time Complexity: O(V+E).
    Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).
    
    Space Complexity: O(V).
    To store the visited and recursion stack O(V) space is needed.

    The difference from the solution to detecting cycle in undirected graph is that,
    1. We don't need to keep track of previous as we cannot travel back the same edge unlike in an undirected graph
    2. visited (cur_path_visited) needs to only contain nodes that are visited in the current path - 
        so remember to remove the node from visited when we backtrack
    3. Keep another visited array (nodes_visited) to keep track of all the visited nodes - 
        use this to skip finding its dfs if it has already been evaluated, while evaluating the dfs of some other node.
*/

bool dfs_chk_loop(const vector<int> adj[], int v, int start_vertex, vector<int> &cur_path_visited, vector<int> &nodes_visited) {
    cur_path_visited[start_vertex] = 1;
    nodes_visited[start_vertex] = 1;
    for(int neighbor : adj[start_vertex]) {
        if(cur_path_visited[neighbor]) return true;
        if(dfs_chk_loop(adj, v, neighbor, cur_path_visited, nodes_visited)) return true;
    }
    cur_path_visited[start_vertex] = 0;
    return false;
}

/*  Function to check if the given graph contains cycle
*   v: number of vertices
*   adj[]: representation of graph
*/
bool isCyclic(int v, vector<int> adj[]) {
    vector<int> nodes_visited(v, 0);
    for(int i=0; i<v; ++i) {
        if(nodes_visited[i]) continue;
        vector<int> cur_path_visited(v, 0);
        if(dfs_chk_loop(adj, v, i, cur_path_visited, nodes_visited)) return true;
    }
    return false;
}