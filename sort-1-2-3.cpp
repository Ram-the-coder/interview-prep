class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void sortColors(vector<int>& nums) {
        int lastZero = -1;
        int lastTwo = nums.size();
        
        for(int i=0; i<lastTwo; ++i) {
            if(nums[i] == 0) {
                swap(nums, ++lastZero, i);
            } else if(nums[i] == 2) {
                swap(nums, --lastTwo, i--);
            }
        }
    }
};