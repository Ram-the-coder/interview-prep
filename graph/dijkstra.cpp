// returns a vertex that has the minimum distance from source among all the vertices not in shortest_path_set 
int get_next_vertex(vector<int> &shortest_path_set, vector<int> &min_dist_from_src) {
    int next_vertex = -1;
    for(int i=0; i<shortest_path_set.size(); ++i) {
        if(shortest_path_set[i]) continue;
        if(next_vertex == -1 || min_dist_from_src[i] < min_dist_from_src[next_vertex]) 
            next_vertex = i;
    }
    return next_vertex;
}

/*
    Time Complexity: 
        O(V^2) - if edges are represented using adjacency matrix
        O(ElogV) - if edges are represented using adjacency list and binary heap is used
    Space Complexity: O(V)
*/
vector<int> dijkstra(int source, vector<vector<int>> &adj) {
    int num_vertices = weight.size();

    vector<int> shortest_path_set(num_vertices, 0);
    vector<int> min_dist_from_src(num_vertices, INT_MAX);
    min_dist_from_src[source] = 0;
    
    

    for(int i=0; i<num_vertices; ++i) {
        int u = get_next_vertex(shortest_path_set, min_dist_from_src);
        shortest_path_set[u] = 1;
        for(int v=0; v<num_vertices; ++v) {
            if(!shortest_path_set[v] && adj[u][v] && min_dist_from_src[u] != INT_MAX) 
                min_dist_from_src[v] = min(min_dist_from_src[v], min_dist_from_src[u] + adj[u][v]);
        }
    }

    return shortest_path_set;
}