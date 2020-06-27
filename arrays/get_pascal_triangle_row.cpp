/* SOLUTION 1 */
#define pb push_back
class Solution {
public:
    void fillRow(vector<int> &prevRow, vector<int> &row) {        
        for(int i=0; i<=prevRow.size(); ++i) {
            if(i == 0 || i == prevRow.size()) {
                row.pb(1); continue;
            }
            row.pb(prevRow[i] + prevRow[i-1]);
        }
    }
    
    vector<int> getRow(int rowIndex) {
        vector<int> prevRow;
        vector<int> row;
        for(int i=0; i<=rowIndex; ++i) {
            row.clear();
            fillRow(prevRow, row);
            prevRow = row;
        }
        return row;
    }
};

/* SOLUTION 2 */
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> pre; // previous row
		pre.push_back(1); // pascalTriangle[0] = [[1]]

		for(int i=1 ; i<=rowIndex ; i++){

			int a = pre[0]; // a = pascalTriangle[i-1][j-1]

			for(int j=1 ; j<pre.size(); j++){
				int b = pre[j]; // b = pascalTriangle[i-1][j]
				pre[j] = a + b; // pascalTriangle[i][j] = pascalTriangle[i-1][j] + pascalTriangle[i-1][j-1]
				a = b; 
			}

			pre.push_back(1);
		}

		return pre;
	}
};