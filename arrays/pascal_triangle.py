'''
Given an integer numRows, return the first numRows of Pascal's triangle.
'''
class Solution:
    '''
    Time Complexity: n(n+1)/2 = O(n^2)
    Space Complexity: n(n+1)/2 = O(n^2)
    '''
    def nextRow(self, prevRow):
        if not prevRow:
            return [1]
        if len(prevRow) == 1:
            return [1, 1]
        
        new_row = []
        cur = 0
        for e in prevRow:
            new_row.append(e + cur)
            cur = e
        new_row.append(1)
        return new_row

    def generate(self, numRows: int) -> List[List[int]]:
        all_rows = []
        prev_row = None
        for _ in range(numRows):
            new_row = self.nextRow(prev_row)
            all_rows.append(new_row)
            prev_row = new_row
        return all_rows