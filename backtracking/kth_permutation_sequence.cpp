/*
    The set [1,2,3,...,n] contains a total of n! unique permutations.
    Given n and k, return the kth permutation sequence.

    Note:
    Given n will be between 1 and 9 inclusive.
    Given k will be between 1 and n! inclusive.
*/

/*
    Solution
    Time Complexity: O(n^2)
    Space Complexity: O(n)
*/

class Solution {
public:
    int factorial(int n) {
        int fact = 1;
        for(int i=2; i<=n; ++i) fact *= i;
        return fact;
    }

    string getPermutation(int n, int k) {

        vector<bool> rem(n, true); // numbers remaining
        // rem[i] - true if i+1 hasn't been selected yet

        int index;
        string sequence = "";

        while(n) {
            index = (k-1) / factorial(n-1);
            k -= index * factorial(n-1);
            n--;
            
            int i;
            for(i=0; i < rem.size(); ++i) {
                if(rem[i]) {
                    if(--index < 0) break;
                }
            }
            sequence += to_string(i+1);
            rem[i] = false;
        }
        return sequence;
    }
};