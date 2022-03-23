'''
    https://leetcode.com/problems/maximum-subarray/
'''
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        abs_max = nums[0]
        curr_max = nums[0]

        for i in range(1, len(nums)):
            curr_max = max(nums[i], curr_max+nums[i])
            abs_max = max(abs_max, curr_max)

        return abs_max
