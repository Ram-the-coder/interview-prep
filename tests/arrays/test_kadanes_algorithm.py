from unittest import TestCase
from arrays.kadanes_algorithm import DivideAndConquer, Solution

class TestSolution(TestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.maxSubArray = Solution().maxSubArray

    def test_returns_element_itself_when_single_element_passed_in_array(self):
        self.assertEqual(self.maxSubArray([1]), 1)
        self.assertEqual(self.maxSubArray([2]), 2)

    def test_returns_sum_of_array_when_all_are_positive(self):
        self.assertEqual(self.maxSubArray([1, 2, 3]), 6)

    def test_returns_max_sub_array_when_array_has_negatives_at_end(self):
        self.assertEqual(self.maxSubArray([1, 2, -3]), 3)

    def test_returns_max_sub_array_when_array_has_negatives_at_start(self):
        self.assertEqual(self.maxSubArray([-1, 1, 2, 3]), 6)

    def test_returns_left_msa_when_array_has_negatives_in_middle_that_sum_greater_than_left(self):
        self.assertEqual(self.maxSubArray([1, 2, 3, -4, -2, 5]), 6)

    def test_returns_element_itself_when_single_negative_element_passed(self):
        self.assertEqual(self.maxSubArray([-1]), -1)

    def test_returns_least_negative_element(self):
        self.assertEqual(self.maxSubArray([-4, -1, -2]), -1)


class TestDivideAndConquer(TestCase):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.maxSubArray = DivideAndConquer().maxSubArray

    def test_returns_element_itself_when_single_element_passed_in_array(self):
        self.assertEqual(self.maxSubArray([1]), 1)
        self.assertEqual(self.maxSubArray([2]), 2)

    def test_returns_sum_of_array_when_all_are_positive(self):
        self.assertEqual(self.maxSubArray([1, 2, 3]), 6)

    def test_returns_max_sub_array_when_array_has_negatives_at_end(self):
        self.assertEqual(self.maxSubArray([1, 2, -3]), 3)

    def test_returns_max_sub_array_when_array_has_negatives_at_start(self):
        self.assertEqual(self.maxSubArray([-1, 1, 2, 3]), 6)

    def test_returns_left_msa_when_array_has_negatives_in_middle_that_sum_greater_than_left(self):
        self.assertEqual(self.maxSubArray([1, 2, 3, -4, -2, 5]), 6)

    def test_returns_element_itself_when_single_negative_element_passed(self):
        self.assertEqual(self.maxSubArray([-1]), -1)

    def test_returns_least_negative_element(self):
        self.assertEqual(self.maxSubArray([-4, -1, -2]), -1)