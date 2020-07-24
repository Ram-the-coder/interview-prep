/*
    Given a Matrix consisting of 0s and 1s. Find the number of islands of connected 1s present in the matrix. 
    Note: A 1 is said to be connected if it has another 1 around it (either of the 8 directions).
*/

/*
    Solution - DFS
    Time Complexity: O(n*m)
    Space Complexity: O(n*m)
*/

void dfs(vector<int> a[], int n, int m, vector<vector<int>> &visited, int i, int j) {
    visited[i][j] = 1;
    if(i > 0 && a[i-1][j] && !visited[i-1][j]) dfs(a, n, m, visited, i-1, j);
    if(i < n-1 && a[i+1][j] && !visited[i+1][j]) dfs(a, n, m, visited, i+1, j);
    if(j > 0 && a[i][j-1] && !visited[i][j-1]) dfs(a, n, m, visited, i, j-1);
    if(j < m-1 && a[i][j+1] && !visited[i][j+1]) dfs(a, n, m, visited, i, j+1);
    if(i > 0 && j > 0 && a[i-1][j-1] && !visited[i-1][j-1]) dfs(a, n, m, visited, i-1, j-1);
    if(i > 0 && j < m-1 && a[i-1][j+1] && !visited[i-1][j+1]) dfs(a, n, m, visited, i-1, j+1);
    if(i < n-1 && j > 0 && a[i+1][j-1] && !visited[i+1][j-1]) dfs(a, n, m, visited, i+1, j-1);
    if(i < n-1 && j < m-1 && a[i+1][j+1] && !visited[i+1][j+1]) dfs(a, n, m, visited, i+1, j+1);
}
int findIslands(vector<int> a[], int n, int m) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(visited[i][j] || a[i][j] == 0) continue;
            dfs(a, n, m, visited, i, j);
            ++count;
        }
    }
    return count;
}