/*
    Given an array of integers A and an integer B.

    Find the total number of subarrays (contiguous elements) having bitwise XOR of all elements equals to B.

    A = [4, 2, 2, 6, 4]
    B = 6
    Output = 4
    The subarrays having XOR of their elements as 6 are:
    [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

    A = [5, 6, 7, 8, 9]
    B = 5
    Output = 2
    The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]

    Solution: Similar to longest subarray with 0 sum problem
*/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, vector<int>> prefix_xor;
    int xor_until_now = 0, number_of_subarrays = 0;
    
    for(int i=0; i<A.size(); ++i) {
        
        
        if(A[i] == B) ++number_of_subarrays;
        
        xor_until_now ^= A[i];
        
        if(i != 0 && xor_until_now == B) number_of_subarrays++;
        
        auto itr = prefix_xor.find(xor_until_now ^ B );
        if(itr != prefix_xor.end()) {

            if(A[i] != B) number_of_subarrays += itr->second.size();
            else {
                for(int idx : itr->second) {
                    if(i - idx > 1) {
                        number_of_subarrays++;
                    }    
                }    
            }
        }
        
        if(prefix_xor.find(xor_until_now) == prefix_xor.end()) 
            prefix_xor[xor_until_now] = {i}; // Encountering the prefix first time
        else 
            prefix_xor[xor_until_now].push_back(i);
    }
    
    return number_of_subarrays;
}
