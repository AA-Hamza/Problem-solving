'''
    Problem Link https://leetcode.com/problems/4sum/submissions/
'''
def fourSum(nums, target):
    result = []
    nums.sort()
    i = 0
    while i < len(nums):

        if (i > 0 and nums[i] == nums[i-1]):
            i +=1
            continue
        j = i + 1
        while j < len(nums):
            if (j > i+1 and nums[j] == nums[j-1]):
                j +=1
                continue
            l, r = j+1, len(nums)-1
            while l < r:
                fourSum = nums[i]+nums[j]+nums[l]+nums[r]
                if fourSum > target:
                    r -= 1
                elif fourSum < target:
                    l += 1
                else:
                    result.append([nums[i], nums[j], nums[l], nums[r]])
                    l += 1
                    while nums[l] == nums[l-1] and l < r:
                        l += 1
            j += 1
        i += 1

    return result


print(fourSum([1, 0, -1, 0, -2, 2], 0))
print(fourSum([2, 2, 2, 2, 2], 8))
print(fourSum([-2,-1,-1,1,1,2,2], 0))
