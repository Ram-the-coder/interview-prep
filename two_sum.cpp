/*
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index; // index[n] contains the index of the integer n in the given array
        index.reserve(nums.size());

        for(int i=0; i<nums.size(); ++i) {
            auto itr = index.find(target - nums[i]);
            if(itr != index.end()) {
                vector<int> res;
                res.push_back(itr->second);
                res.push_back(i);
                return res;
            }
            index[nums[i]] = i;
        }
        return vector<int>();
    }
};