/* 
    Given an array of integers nums and a positive integer k, 
    find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.
*/

/*
    Solution 1 - Backtracking
    Time Complexity:  O( k! * k^(N-k) )
    [Time complexity without optimizations would be k^n -> each item can go into k subsets, so k^n]
    Space Complexity: O(n)

    Detailed explanation for complexity analysis: https://efficientcodeblog.wordpress.com/2017/12/01/partition-to-k-equal-sum-subsets/
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int total_sum = accumulate(a.begin(), a.end(), 0);
        if(total_sum % k) return false;

        int sub_sum = total_sum / k;

        sort(a.begin(), a.end(), greater<int>());

        if(a[0] > sub_sum) return false;

        int start = 0;

        // If an element of value sub_sum already exists then
        // we need to only find k-1 subsets of sum sub_sum
        while(a[start] == sub_sum) {
            start++;
            k--;
        }

        // Contains the sum of each subset
        vector<int> groups(k, 0);

        return partition(a, groups, sub_sum, start, 0);
    }

    bool partition(vector<int> &a, vector<int> &groups, int sub_sum, int i, int num_filled_groups) {
        if(num_filled_groups == groups.size()) return true; 

        if(i >= a.size()) return false;

        // Put a[i] in any of the groups and move on to a[i+1]
        for(int j=0; j<groups.size(); ++j) {
            if(a[i] + groups[j] <= sub_sum) {
                groups[j] += a[i];
                if(groups[j] == sub_sum) ++num_filled_groups;
                if(partition(a, groups, sub_sum, i+1, num_filled_groups)) return true;
                if(groups[j] == sub_sum) --num_filled_groups;
                groups[j] -= a[i];
            }

            // This is an optimization with high returns
            // If groups[j] is empty and putting a[i] in this empty bucket doesn't solve the problem
            // then there is no use in trying to put it in groups[j+1] - another empty bucket
            if(groups[j] == 0) return false;
        }

        return false;
    }
};

/*
    Solution 2 - DP with bit masking
    Time Complexity: O(n * 2^n)
    Space Complexity: O(2^n)
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if(total_sum % k) return false;
        int sub_sum = total_sum / k;

        int cur_sum = 0;
        int max_addable_num = sub_sum;      

        vector<int> dp(1 << nums.size(), -1);
        dp[0] = 0;

        // dp[i] = the sum of elements chosen in the set of subsets represented by the bit mask i
        // dp[i] is only set if the elements chosen can be partitioned into subsets such that one subset will have a sum <= sub_sum and the
        // rest will have sum exacty equal to sub_sum
        // So if dp[nums.size() ^ n - 1] != -1, it means nums can be partitioned in k subsets of sum equal to sub_sum 

        // Loop over all the subsets
        // we'll fill up subset by subset
        // we'll only add an element to a subset if it doesn't take up its sum more than sub_sum
        // Initially state = 0 => no elements in subset

        for(int state=0; state < (1 << nums.size()); ++state) {

            if(dp[state] == -1) continue; // Illegal state

            for(int i=0; i<nums.size(); ++i) {

                int new_state = state | (1 << i);

                if(state == new_state || sub_sum - (dp[state] % sub_sum) < nums[i] ) continue;

                dp[new_state] = dp[state] + nums[i];
            }
        }

        return dp.back() != -1;
    }
};