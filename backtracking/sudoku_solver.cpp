/*
    Solution 1
    Time Complexity: O((9*n*n)^(n*n))
    Space Complexity: O(n) - to store the values
    Extra space: O(1)
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int row, int col) {
        if(row == board.size()) return true;
        if(col == board[0].size()) return solve(board, row+1, 0);
        if(board[row][col] != '.') return solve(board, row, col+1);
        
        for(int i=1; i<=9; ++i) {
            if(!is_valid_value(board, row, col, '0' + i)) continue;
            board[row][col] = '0' + i;
            if(solve(board, row, col+1)) return true;
        }
        board[row][col] = '.';
        return false;
    }
    
    bool is_valid_value(vector<vector<char>>& board, int row, int col, int value) {
        for(int i=0; i<board.size(); ++i) {
            if(board[i][col] == value) return false;
        }
        
        for(int i=0; i<board[0].size(); ++i) {
            if(board[row][i] == value) return false;
        }
        
        int box_row = (row / 3) * 3;
        int box_col = (col / 3) * 3;
        
        for(int i=0; i<3; ++i) {
            for(int j=0; j<3; ++j) {
                if(board[i+box_row][j+box_col] == value) return false;
            }
        }
        
        return true;
    }
};

/*
    Solution 2
    Time Complexity: O(9^(n*n))
    Space Complexity: O(n) - to store the values
    Extra space: O(n)
*/

class Solution {
public:
    vector<vector<int>> info_row, info_col, info_box; // IMPORTANT NOTE: Don't use vector<bool>, it is broken
    void solveSudoku(vector<vector<char>>& board) {
        info_row.resize(board.size(), vector<int>(9, 0));
        info_col.resize(board[0].size(), vector<int>(9, 0));
        info_box.resize(9, vector<int>(9, 0));
        for(int i=0; i<board.size(); ++i) {
            for(int j=0; j<board[i].size(); ++j)
                if(board[i][j] != '.') {
                    info_row[i][board[i][j] - '1'] = 1;
                    info_col[j][board[i][j] - '1'] = 1;
                    info_box[(i/3*3)+j/3][board[i][j] - '1'] = 1;
                }
        }
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int row, int col) {
        if(row == board.size()) return true;
        if(col == board[0].size()) return solve(board, row+1, 0);
        if(board[row][col] != '.') return solve(board, row, col+1);
        
        for(int i=0; i<9; ++i) {
            if(info_row[row][i] || info_col[col][i] || info_box[(row/3 * 3) + (col/3)][i]) 
                continue;
            board[row][col] = '1' + i;
            info_row[row][i] = info_col[col][i] = info_box[(row/3 * 3) + (col/3)][i] = 1;
            if(solve(board, row, col+1)) return true;
            info_row[row][i] = info_col[col][i] = info_box[(row/3 * 3) + (col/3)][i] = 0;
        }
        board[row][col] = '.';
        return false;
    }
};