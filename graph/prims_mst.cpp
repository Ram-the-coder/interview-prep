

int getNextVertex(vector<int> &mstSet, vector<int> &key, int v) {
    int minKey = -1;
    for(int i=0; i<v; ++i) {
        if(!mstSet[i] && (minKey == -1 || key[i] < key[minKey])) minKey = i;
    }
    return minKey;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
/*
    Prim's Algorithm to find Minimum Spanning Tree
    Time Complexity: 
        O(V^2) - edges in adjacency matrix representation
        O(ElogV) - edges in adjacency list representation and binary heap is used
    Space Complexity: O(V)
*/
int spanningTree(int v, int e, vector<vector<int>> &graph) {
    int sum = 0;
    vector<int> mstSet(v, 0);
    vector<int> key(v, INT_MAX);
    key[0] = 0;
    
    for(int i=0; i<v; ++i) {
        int a = getNextVertex(mstSet, key, v);
        mstSet[a] = 1;
        sum += key[a];
        for(int b=1; b<v; ++b) {
            if(!mstSet[b] && key[b] > graph[a][b]) {
                key[b] = graph[a][b];
            }
        }
    }

    return sum;
}