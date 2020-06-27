/*
    PROBLEM STATEMENT:
    Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
    Do it in constant space.
*/

/* SOLUTION 1 */
/*
    The logic is based on having two separate vectors that contain information about which rows
    need to be zeroed and which cols need to zeroed. Instead of creating new vectors, we'll just
    use a col and a row from the matrix itself.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix[0].size(), n = matrix.size();
        int rowInfo = -1; // The column index in which to store row info (which rows need to be zero-ed)
        int colInfo = -1; // The row index in which to store col info (which colsn need to be zero-ed)

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {

                if(matrix[i][j] == 0) {

                    if(rowInfo == -1) { // If rowInfo and colInfo have not yet been defined
                        // Since matrix[i][j] == 0
                        // we'll finally be zeroing the row i and col j
                        // we might as well use it to store the rowInfo and colInfo
                        rowInfo = j;
                        colInfo = i;
                    }
                    
                    matrix[i][rowInfo] = 0; // Implies that the ith row need to be zeroed
                    matrix[colInfo][j] = 0; // Implies that the jth col need to be zeroed
                }
            }
        }

        
        if(rowInfo != -1) { // If there exists at least one zero

            // Use the colInfo to zero the cols
            for(int j=0; j<m; ++j) {
                if(j == rowInfo) continue; // Don't change the rowInfo
                if(matrix[colInfo][j] == 0) {
                    for(int i=0; i<n; ++i) matrix[i][j] = 0;
                }
            }

            // Use the rowInfo to zero the rows
            for(int i=0; i<n; ++i) {
                if(i == colInfo) continue; // Don't change the colInfo
                if(matrix[i][rowInfo] == 0) {
                    for(int j=0; j<m; ++j) matrix[i][j] = 0;
                }
            }

            // Zero the rowInfo col
            for(int i=0; i<n; ++i) {
                matrix[i][rowInfo] = 0;
            }

            // Zero the colInfo row
            for(int j=0; j<m; ++j) {
                matrix[colInfo][j] = 0;
            }    
        }
        
    }
    
};



/* SOLUTION 2 */
/* 
    The logic used here is that if matrix[i][j] == 0 then we set 
    matrix[0][j] = matrix[i][0] = 0
    to denote that the jth row and the ith col need to be zeroed

    Setting matrix[0][j] = matrix[i][0] = 0 won't affect the value in those cells as they've already been processed
    before processing matrix[i][j]

    The only problem with this approach is that when the first row need to be zeroed, it sets matrix[0][0] = 0
    and when the first col need to be be zeroed, it also sets matrix[0][0] = 0
    To differentiate this, we'll have a flag that'll be set to true if the first column need to be zeroed
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), n = matrix.size();
        bool firstColZero = false;
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(matrix[i][j] == 0) {
                    if(j == 0) {
                        firstColZero = true;
                        if(i != 0) continue; // If i == 0 then we need set matrix[0][0] to 0
                    }
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        // Check which rows need to be zeroed and zero them
        // Omit the first row as it contains the information about which cols need to be zeroed
        for(int i=1; i<n; ++i) {
            if(matrix[i][0] != 0) continue;
            for(int j=1; j<m; ++j) matrix[i][j] = 0;
        }
        
        // Check which cols need to be zeroed and zero them
        // Omit the first col as it contains the information about which rows need to be zeroed
        for(int j=1; j<m; ++j) {
            if(matrix[0][j] != 0) continue;
            for(int i=1; i<n; ++i) matrix[i][j] = 0;
        }
        
        // Check if the first row needs to be zeroed
        if(matrix[0][0] == 0) {
            for(int j=0; j<m; ++j) matrix[0][j] = 0;
        }
        
        // Check if the first col needs to be zeroed
        if(firstColZero) {
            for(int i=0; i<n; ++i) matrix[i][0] = 0;
        }
    }
    
};