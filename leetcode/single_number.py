'''
    Author: Ahmed Anwar
    Problem Link: https://leetcode.com/problems/single-number/
'''

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        single = 0
        for i in nums:
            single ^= i
        return single

