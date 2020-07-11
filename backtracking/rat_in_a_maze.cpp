/*
    Consider a rat placed at (0, 0) in a square matrix of order N*N. 
    It has to reach the destination at (n-1, n-1). 
    Find all possible paths that the rat can take to reach from source to destination. 
    The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
    Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed 
    while value 1 at a cell in the matrix represents that it can be travelled through.
*/


/*
    Solution
    Time Complexity: O(2^(n*n)) - Every square can either be part of a path or not
    Space Complexity: O(n^2) - To store the matrix and also visited information
*/

void findPath(int m[MAX][MAX], int n, int i, int j, vector<string> &res, string &cur_path, vector<vector<int>> &visited) {

    if(i == n || j == n || i < 0 || j < 0 || visited[i][j] || !m[i][j]) return;

    if(i == n-1 && j == n-1) {
        res.pb(cur_path);
        return;
    }

    visited[i][j] = 1;

    cur_path += "D";
    findPath(m, n, i+1, j, res, cur_path, visited);
    cur_path[cur_path.length()-1] = 'L';
    findPath(m, n, i, j-1, res, cur_path, visited);
    cur_path[cur_path.length()-1] = 'R';
    findPath(m, n, i, j+1, res, cur_path, visited);
    cur_path[cur_path.length()-1] = 'U';
    findPath(m, n, i-1, j, res, cur_path, visited);
    cur_path.erase(cur_path.length()-1, 1);

    visited[i][j] = 0;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<string> res;
    string cur_path = "";
    vector<vector<int>> visited(n, vector<int>(n, 0));
    findPath(m, n, 0, 0, res, cur_path, visited);
    return res;
}