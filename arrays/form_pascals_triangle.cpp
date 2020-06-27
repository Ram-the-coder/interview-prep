#define pb push_back

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> pascalTriangle(numRows, vector<int>());

        for(int i=0; i<numRows; ++i) {
            for(int j=0; j<=i; ++j) {

                if(j == 0 || j == i) {
                    pascalTriangle[i].pb(1);
                    continue;
                }
                
                pascalTriangle[i].pb(pascalTriangle[i-1][j] + pascalTriangle[i-1][j-1]);
            }
        }
        
        return pascalTriangle;
    }
};