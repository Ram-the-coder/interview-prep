/*
    The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

    Example:

    Input: 4

    Output: [
    [".Q..",  // Solution 1
    "...Q",
    "Q...",
    "..Q."],

    ["..Q.",  // Solution 2
    "Q...",
    "...Q",
    ".Q.."]
    ]
    
    Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

/*
    Solution
    Time Complexity: O(n!)
    Space Complexity: O(n^2)

    An optimization would be to use a boolean array to store if a column, 45deg diagonal, 135deg diagonal is occupied or not
    This would then reduce the time complexity to perform a check if a square is attacked from O(n) to O(1)
*/ 

class Solution {
public:   
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        placeQueen(res, board, 0);
        return res;
    }
    
    void placeQueen(vector<vector<string>> &res, vector<string> &board, int row) {
        if(row >= board.size()) {
            res.push_back(board);
            return;
        }
        
        for(int col=0; col < board.size(); ++col) {
            if(isSquareAttacked(board, row, col)) continue;
            board[row][col] = 'Q';
            placeQueen(res, board, row+1);
            board[row][col] = '.';
        }
    }
    
    bool isSquareAttacked(vector<string> &board, int row, int col) {
        // check the col
        for(int i=0; i<row; ++i) {
            if(board[i][col] == 'Q') return true;
        }
        
        // check upper left diagonal
        for(int i=row-1, j=col-1; i >= 0 && j >= 0; --i, --j) {
            if(board[i][j] == 'Q') return true;
        }

        // check upper right diagonal
        for(int i=row-1, j=col+1; i >= 0 && j < board.size(); --i, ++j) {
            if(board[i][j] == 'Q') return true;
        }
        
        return false;
    }
};