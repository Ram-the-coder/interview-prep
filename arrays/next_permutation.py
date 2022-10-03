class Solution:
    def reverse(self, arr, start, end):
        i = start
        j = end
        while (i < j):
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
        
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n == 1:
            return

        i = n-2
        while i >= 0:
            if nums[i] < nums[i+1]:
                break
            i -= 1
        if i < 0:
            nums.reverse()
            return
        
        next_greatest_num_idx = i+1
        for j in range(i+2, n):
            if nums[j] > nums[i] and nums[j] <= nums[next_greatest_num_idx]:
                next_greatest_num_idx = j
        
        nums[i], nums[next_greatest_num_idx] = nums[next_greatest_num_idx], nums[i]
        self.reverse(nums, i+1, n-1)
        return
