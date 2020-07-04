/*
    Given a collection of candidate numbers (candidates) and a target number (target), 
    find all unique combinations in candidates where the candidate numbers sums to target.

    Each number in candidates may only be used once in the combination.

    Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
*/

#define pb push_back
class Solution {
public:
    void combinations(vector<int> &candidates, int target, int i, vector<int> &combo, vector<vector<int>> &res) {

        if(target == 0) {
            res.pb(combo);
            return;
        }
        
        if(i == candidates.size() || target < candidates[i]) return;
        
        // The candidates may contain duplicates, so if one number is not considered in the combo
        // then all instances of that number from now on should not be considered
        // so that the resultant set will not contain any duplicates
        int next_number = i+1;
        while(next_number > 0 && next_number < candidates.size() && candidates[next_number] == candidates[next_number-1]) next_number++;
        
        if(next_number < candidates.size())
            combinations(candidates, target, next_number, combo, res);
        combo.pb(candidates[i]);
        combinations(candidates, target - candidates[i], i+1, combo, res);
        combo.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sorting is done so that if target < candidates[i] then we can stop the combo search
        vector<vector<int>> res;
        vector<int> combo;
        combinations(candidates, target, 0, combo, res);
        return res;
    }
};