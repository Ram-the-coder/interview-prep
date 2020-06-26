/*
    Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

    To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

    Example:

    Input:
    A = [ 1, 2]
    B = [-2,-1]
    C = [-1, 2]
    D = [ 0, 2]

    Output:
    2

    Explanation:
    The two tuples are:
    1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
    2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        vector<int> v;
		//Merge A,B and store result in vector v
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                v.push_back(a[i]+b[j]);
            }
        }
        map<int,int> m;
		//Merge C,D and store count in map m
        for(int i=0;i<c.size();i++){
            for(int j=0;j<d.size();j++){
                m[c[i]+d[j]]++;
            }
        }
        //Iterate over every element in Merged vector and find the number of elements that sum up to zero
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=m[-v[i]];
        }
        return ans;  //return the final answer
    }
};