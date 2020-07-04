/*
    Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
    find all unique combinations in candidates where the candidate numbers sums to target.

    The same repeated number may be chosen from candidates unlimited number of times.

    Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
*/

class Solution {
public:
    void combinations(vector<int> &candidates, int target, int i, vector<int> &combo, vector<vector<int>> &res) {

        if(target == 0) {
            res.pb(combo);
            return;
        }
        
        if(i == candidates.size() || target < candidates[i]) return;
        
        combinations(candidates, target, i+1, combo, res);
        combo.pb(candidates[i]);
        combinations(candidates, target - candidates[i], i, combo, res);
        combo.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sorting is done so that if target < candidates[i] then we can stop the combo search
        vector<vector<int>> res;
        vector<int> combo;
        combinations(candidates, target, 0, combo, res);
        return res;
    }
};