/*
    Solution 1
    Time Complexity: O(m*n)
    Space Complexity: O(m*n)
*/
class Solution {
public:
    int _uniquePaths(int m, int n, vector<vector<int>> &dp) {
        if(dp[m][n] != -1) return dp[m][n];
        
        if(m <= 1 || n <= 1) {
            dp[m][n] = 1;
            return 1;
        }
        
        dp[m][n] = _uniquePaths(m-1, n, dp) + _uniquePaths(m, n-1, dp);
        return dp[m][n];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return _uniquePaths(m, n, dp);
    }
};

/*
    Solution 2
    Time Complexity: O(m*n)
    Space Complexity: O(2*n)

    We can see that at a time to calculate dp[m][n] we just need dp[m-1][n] and dp[m][n-1]
    We can easily reduce the dp to two rows - prev and cur and solve the dp in bottom up manner
    where dp[cur][i] = dp[cur][i-1] + dp[prev][i]
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 1), cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] = pre[j] + cur[j - 1];
            }
            swap(pre, cur);
        }
        return pre[n - 1];
    }
};


/*
    Solution 3
    Time Complexity: O(m*n)
    Space Complextiy: O(n)

    Notice that prev[j] is just cur[j] before the update
*/

class Solution {
public:    
    int uniquePaths(int m, int n) {
        
        vector<int> cur(n, 1);

        for(int i=1; i<m; ++i)
            for(int j=1; j<n; ++j)
                cur[j] += cur[j-1];

        return cur[n-1];
    }
};