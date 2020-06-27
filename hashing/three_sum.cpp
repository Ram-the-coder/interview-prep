/*
    Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
    Find all unique triplets in the array which gives the sum of zero.
    Note: The solution set must not contain duplicate triplets.

    Logic:
    1. Sort the array.
    2. Iteratively fix one number a
    3. Among the rest of the numbers, find two numbers such that a + b + c = 0
    4. To find the two numbers use two pointers - one at the start and one at the end
    5. Change the pointers according to the sum they produce

*/


#define pb push_back

class Solution {
public:
    // Finds the index of next different number to the right of i
    int next_num(vector<int> &nums, int i) {
        int j;
        for(j=i+1; j < nums.size() && nums[j] == nums[i]; ++j);
        return j;
    }
    
    // Finds the index of next different number to the left of i
    int next_smaller_num(vector<int> &nums, int i) {
        int j;
        for(j=i-1; j >= 0 && nums[j] == nums[i]; --j);
        return j;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> solution_set;

        if(nums.size() < 3) return solution_set;

        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2 && nums[i] <= 0; i = next_num(nums, i)) {
            
            int start = i+1;
            int end = nums.size()-1;
            
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum > 0) {
                    --end;
                } else if(sum < 0) {
                    ++start;
                } else {
                    solution_set.pb({nums[i], nums[start], nums[end]});
                    start = next_num(nums, start);
                    end = next_smaller_num(nums, end);
                }
            }
            
        }
        
        return solution_set;
    }
};