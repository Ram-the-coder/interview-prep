from typing import *


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = nums[0]
        cur_sum = 0
        n = len(nums)
        if_negative_reset_to_zero = lambda x: 0 if x < 0 else x
        for i in range(n):
            cur_sum += nums[i]
            max_sum = max(cur_sum, max_sum)
            cur_sum = if_negative_reset_to_zero(cur_sum)
        return max_sum


class DivideAndConquer:
    def maxSubArray(self, nums: List[int]) -> int:
        self.nums = nums
        return self._getMaxSubArray(0, len(nums) - 1)

    def _getMaxSubArray(self, start, end) -> int:
        if start == end:
            return self.nums[start]

        mid = (start + end) // 2

        lstart = start
        lend = mid
        rstart = mid + 1
        rend = end

        return max(
            self._getMaxSubArray(lstart, lend),
            self._getMaxSubArray(rstart, rend),
            self._find_max_sum_overlapping_left_and_right_subarrays(
                lstart, lend, rstart, rend
            ),
        )
    
    def _find_max_sum_overlapping_left_and_right_subarrays(
        self,
        lstart,
        lend,
        rstart,
        rend,
    ):
        return self._get_max_subarray_sum_with_subarray_ending_at_last_element_of_array(
            lstart, lend
        ) + self._get_max_subarray_sum_with_subarray_starting_at_first_element_of_array(
            rstart, rend
        )

    def _get_max_subarray_sum_with_subarray_ending_at_last_element_of_array(
        self, start, end
    ):
        max_sum = self.nums[end]
        cur_sum = 0
        for i in range(end, start - 1, -1):
            cur_sum += self.nums[i]
            max_sum = max(cur_sum, max_sum)
        return max_sum

    def _get_max_subarray_sum_with_subarray_starting_at_first_element_of_array(
        self, start, end
    ):
        max_sum = self.nums[start]
        cur_sum = 0
        for i in range(start, end + 1):
            cur_sum += self.nums[i]
            max_sum = max(cur_sum, max_sum)
        return max_sum
