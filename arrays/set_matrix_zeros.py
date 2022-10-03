class Solution:
    """
    Time: O(mn)
    Extra Space: O(m +n)
    Concept: Use 2 separate lists to indicate which rows, cols to zero
    """
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix) # rows
        n = len(matrix[0]) # cols
        
        row_has_zero = [False]*m
        col_has_zero = [False]*n
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row_has_zero[i] = True
                    col_has_zero[j] = True
                    
        for i in range(m):
            for j in range(n):
                if row_has_zero[i] or col_has_zero[j]:
                    matrix[i][j] = 0


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Time: O(mn)
        Extra Space: O(1)
        Concept: Use the matrix itself to store the values of the 2 separate lists
        """
        m = len(matrix) # rows
        n = len(matrix[0]) # cols
        
        col_with_row_info = None
        row_with_col_info = None
        is_col_with_row_info_valid = None
        is_row_with_col_info_valid = None

        def matrix_has_at_least_one_zero():
            return col_with_row_info != None

        def should_row_be_zeroed(i):
            if col_with_row_info == None:
                raise ValueError('col_with_row_info not set')
            if not is_col_with_row_info_valid:
                raise ValueError('invalid col_with_row_info')
            return matrix[i][col_with_row_info] == 0

        def should_col_be_zeroed(j):
            if row_with_col_info == None:
                raise ValueError('row_with_col_info not set')
            if not is_row_with_col_info_valid:
                raise ValueError('invalid row_with_col_info')
            return matrix[row_with_col_info][j] == 0

        def zero_the_row(i):
            matrix[i] = [0]*n
            if i == row_with_col_info:
                is_row_with_col_info_valid = False
        
        def zero_the_col(j):
            for i in range(m):
                matrix[i][j] = 0
            if j == col_with_row_info:
                is_col_with_row_info_valid = False
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    if col_with_row_info == None:
                        col_with_row_info = j
                        row_with_col_info = i
                        is_col_with_row_info_valid = True
                        is_row_with_col_info_valid = True
                    matrix[i][col_with_row_info] = 0
                    matrix[row_with_col_info][j] = 0

        if matrix_has_at_least_one_zero():            
            for i in range(m):
                if should_row_be_zeroed(i) and i != row_with_col_info:
                    zero_the_row(i)
                
            for j in range(n):
                if should_col_be_zeroed(j):
                    zero_the_col(j)
                    
            zero_the_row(row_with_col_info)
            
                    
        
                    
        