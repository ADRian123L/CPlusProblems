# The pivot problem:
class Solution:
    """ This is the solution for the pivot problem."""
    def pivotIndex(self, nums: list[int]) -> int:
        """ This is the function that solves the problem."""
        # Check if the length is less than one:
        if (len(nums) < 1):
            return 0
        if (len(nums) == 1):
            return -1
        
        # Get the sum of the value:
        sum: int = 0
        for i in nums:
            sum += i

        # Check if the left sum equals the sum:
        left_sum = 0
        for u, j in enumerate(nums):
            if (left_sum == (sum - j) / 2):
                return u
            else:
                left_sum += j
            
        # If there is no pivot return -1:
        return -1 