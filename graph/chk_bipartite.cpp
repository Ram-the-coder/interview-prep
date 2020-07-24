/*
    Given an adjacency matrix representation of a graph g having 0 based index 
    your task is to complete the function isBipartite which returns true if the graph is a bipartite graph else returns false.
*/

/*
    Solution
    Time Complexity: O(V^2), if edges are depicted using adjacency list then O(V + E)
    Space Complexity: O(V)

    Logic:
    Checking if a graph is bipartite is a graph coloring problem with 2 colors.
    If there exists a combination in which all nodes can be colored such the adjacent nodes
    don't have the same color then the graph is bipartite.
*/

bool dfs(int i, int v, int g[][MAX], vector<int> &visited, vector<int> &color, int prev) {
    if(visited[i]) return prev != color[i];
    visited[i] = 1;    
    for(int c=0; c<2; ++c) {
        if(c == prev) continue;
        bool ok = true;
        color[i] = c;
        for(int neighbor=0; neighbor<v; ++neighbor) {
            if(!g[i][neighbor]) continue;
            if(!dfs(neighbor, v, g, visited, color, c)) {
                ok = false;
                break;
            }
        }
        
        if(ok) return true;
    }   
    
    visited[i] = 0;    
    color[i] = -1;
    return false;
}

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

bool isBipartite(int g[][MAX], int v)
{
    vector<int> color(v, -1);
    vector<int> visited(v, 0);
    
    for(int i=0; i<v; ++i) {
        if(visited[i]) continue;
        if(!dfs(i, v, g, visited, color, -1)) return false;
    }
    
    return true;
}