/*
    Given an array having both positive and negative integers. 
    The task is to compute the length of the largest subarray (contiguous) with sum 0.
*/

int maxLen(int A[], int n)
{
    unordered_map<int, int> prefix_sum; // Maps the prefix-sum to the index of first instance of that prefix sum in the array
    prefix_sum.reserve(n);

    int max_len = 0, sum = 0;
    
    for(int i=0; i<n; ++i) {
        if(A[i] == 0) max_len = max(1, max_len); // To take care of the condition where a single 0 exists
        
        sum += A[i];
        
        if(sum == 0) {
            max_len = max(i+1, max_len); // The whole array upto index i is a subarray with sum 0
        } else {
            if(prefix_sum.find(sum) != prefix_sum.end()) max_len = max(max_len, i - prefix_sum[sum]); // A[prefix_sum[sum] + 1]....A[i] is a subarray with sum 0
            else prefix_sum[sum] = i; // First instance of the prefix sum, store it
        }
    }
    
    return max_len;
}