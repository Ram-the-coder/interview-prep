/* 
    Solution 1
    Time Complexity: O(2^n) with optimizations
    Space Complexity: O(n)
*/
class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if(total_sum % 2) return false;
        
        // The array is sorted in descending order so as to achieve larger sum values quickly
        sort(nums.rbegin(), nums.rend());
        
        // If the largest element is greater than the half sum, its not possible to 
        // create a subset whose sum is exactly the half sum
        if(nums[0] > total_sum / 2) return false;

        return sum_exists(nums, total_sum / 2, 0);
    }
    
    bool sum_exists(vector<int> &a, int sum, int i) {
        
        if(i >= a.size()) return (sum == 0);
        
        if(sum == 0 || sum == a[i]) return true;
        
        if(sum < 0) return false;
        
        // We include the ith element first so as to achieve the sums quickly
        return sum_exists(a, sum - a[i], i+1) || sum_exists(a, sum, i+1);
    }
    
};

/*
    Solution 2
    Time complexity: O(n * HALF_SUM + n*logn)
    Space complexity: O(HALF_SUM)
*/

class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int half = total_sum / 2;
        if(total_sum % 2) return false;
        
        // dp[i][j] -> whether the subarray from index 0..i contains a subset that sums to j
        // dp[i][j] = dp[i-1][j - nums[i]] || dp[i-1][j]
        // required dp[nums.size()-1][half]
  
        // Sort so that initially the inner loops run less
        sort(nums.begin(), nums.end());
        if(nums.back() > half) return false;
        
        vector<bool> prev(half+1), cur(half+1, false);
        int sum = 0; 
        
        prev[0] = cur[0] = true;
        
        for(int i=0; i<nums.size(); ++i) {
            if(cur[half]) return true;
            prev.swap(cur);
            sum += nums[i]; // sum of all the numbers until index i
            for(int j=1; j<=half && j<=sum; ++j) {
                cur[j] = prev[j] || (j >= nums[i] && prev[j - nums[i]]);
            }
        }

        return cur[half];
    }    
};