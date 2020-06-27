/*
    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

    If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

    The replacement must be in-place and use only constant extra memory.

    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        // Find the first number from the right such that nums[i] > nums[i-1]
        for(i = nums.size()-1; i > 0; --i) {
            if(nums[i] > nums[i-1]) {
                // Find the rightmost number to the right of nums[i-1] that is just greater than a[i-1]
                int next = i;
                for(int j=i+1; j<nums.size(); ++j) {
                    if(nums[j] > nums[i-1] && nums[j] <= nums[next]) next = j;
                }
                swap(nums[next], nums[i-1]); // Swap it with nums[i-1]
                // Now we need to sort the numbers from index i to last
                // But since the numbers from index i to last are in descending order
                // (swapping doesn't make it out of order)
                // we just need to reverse them
                reverse(nums.begin()+i, nums.end());
                break;
            }
        }
        
        if(i == 0) reverse(nums.begin(), nums.end());
    }
};