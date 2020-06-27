/*
    Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums 
    such that a + b + c + d = target? 
    
    Find all unique quadruplets in the array which gives the sum of target.

    Note: The solution set must not contain duplicate quadruplets.
*/

/*
    SOLUTION 1:
    Generalizing 3sum to ksum
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
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return k_sum(nums, 0, nums.size()-1, target, 4);
    }
    
    vector<vector<int>>k_sum(vector<int> &nums, int start, int end, int target, int k) {
        if(k == 2) return two_sum(nums, start, end, target);
        vector<vector<int>> solution_set, res;
        
        for(int i=start; i<=end; i = next_num(nums, i)) {
            res = k_sum(nums, i+1, end, target - nums[i], k-1);
            for(vector<int> set : res) {
                set.pb(nums[i]);
                solution_set.pb(set);
            }
        }
        
        return solution_set;
    }
    
    
    
    vector<vector<int>> two_sum(vector<int>& nums, int start, int end, int target) {
        vector<vector<int>> solution_set;
        
        while(start < end) {
            int sum = nums[start] + nums[end];
            if(sum > target) {
                --end;
            } else if(sum < target) {
                ++start;
            } else {
                solution_set.pb({nums[start], nums[end]});
                start = next_num(nums, start);
                end = next_smaller_num(nums, end);
            }
        }
        
        return solution_set;
    }
};



/*
    SOLUTION: 2
    Same complexity
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>path;
        DFS(res, nums, 0, target, 0, 0, path);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& nums, int pos, int target, int count, int sum, vector<int>& path){
        if(count == 4){
            if(sum == target) res.push_back(path);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            if(i != pos && nums[i] == nums[i - 1]) continue;
            if(sum + nums[i] + (3 - count) * nums[nums.size() - 1] < target) continue;
            if(sum + (4 - count)* nums[i] > target) break;
            path.push_back(nums[i]);
            DFS(res, nums, i + 1, target, count + 1, sum + nums[i], path);
            path.pop_back();
        }
    }
};