
/*
    Solution 1
    Time Complexity; O(n!)
    Auxillary Space Complexity: O(n)
*/
class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> permutation(nums.size());
        vector<int> place_taken(nums.size(), 0);
        place(res, nums, permutation, place_taken, 0);
        return res;
    }

    void place(vector<vector<int>> &res, vector<int> &nums, vector<int> &permutation, vector<int> &place_taken, int i) {
        if(i == nums.size()) {
            res.push_back(permutation);
            return;
        }
        
        for(int j=0; j<nums.size(); ++j) {
            if(place_taken[j]) continue;
            permutation[j] = nums[i];
            place_taken[j] = 1;
            place(res, nums, permutation, place_taken, i+1);
            place_taken[j] = 0;
        }
        
    }
};

/*
    Solution 2
    Time Complexity; O(n!)
    Auxillary Space Complexity: O(1)
*/

class Solution {
public:  
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute_recursive(res, nums, 0);
        return res;
    }

    void permute_recursive(vector<vector<int>> &res, vector<int> &nums, int start) {
        if(start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int i=start; i<nums.size(); ++i) {
            swap(nums[i], nums[start]);
            permute_recursive(res, nums, start+1);
            swap(nums[i], nums[start]);
        }
        
    }
};