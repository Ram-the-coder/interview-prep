/*
    Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

    Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        num_set.reserve(nums.size());

        int max_consecutive = 0;
    
        // Add all the elements to the set    
        for(int i=0; i<nums.size(); ++i) {
            num_set.insert(nums[i]);
        }      
        
        for(int i=0; i<nums.size(); ++i) {
            // If the set contains nums[i]-1 that means there is a longer sequence than the one starting with nums[i], so skip this
            if(num_set.find(nums[i]-1) != num_set.end()) continue;
            int cur = nums[i];
            int consecutiveness = 1;
            while(num_set.find(cur+1) != num_set.end()) {
                ++cur;
                ++consecutiveness;
            }
            max_consecutive = max(max_consecutive, consecutiveness);
        }      
        
        return  max_consecutive;
    }
};