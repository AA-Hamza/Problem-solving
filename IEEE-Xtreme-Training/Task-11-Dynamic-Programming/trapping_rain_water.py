'''
    Problem Link https://leetcode.com/problems/trapping-rain-water/
'''

def trap(height):
    max_left_list = [0]*len(height)
    max_right_list = [0]*len(height)
    heightest_left = 0
    heightest_right = 0
    for i in range(len(height)):
        heightest_left = max(height[i], heightest_left);
        heightest_right = max(height[len(height)-1-i], heightest_right);
        max_left_list[i] = heightest_left
        max_right_list[len(height)-1-i] = heightest_right
            
            
    trapped_water = 0
    for i in range(len(height)):
        trapped_water += min(max_left_list[i], max_right_list[i])-height[i]

    return trapped_water
        
height = [4,2,0,3,2,5]
print(trap(height))
