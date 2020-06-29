class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_streak = 0, cur_streak = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] == 1) max_streak = max(max_streak, ++cur_streak);
            else cur_streak = 0;
        }
        
        return max_streak;
    }
};