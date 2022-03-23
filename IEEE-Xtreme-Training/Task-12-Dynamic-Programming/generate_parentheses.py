'''
    Problem Link https://leetcode.com/problems/generate-parentheses/
'''

def ans(n):
    result = []
    max_opened = n
    #opened_bracket = 0
    def helper_function(curr, opened_parentheses, closed_parentheses, left):
        if (left == 0):
            result.append(curr)
            return ''
        
        left_open = opened_parentheses-closed_parentheses
        if (left_open == 0):
            helper_function(curr+'(', opened_parentheses+1, closed_parentheses, left-1)
        else:
            helper_function(curr+')', opened_parentheses, closed_parentheses+1, left-1)
            if (opened_parentheses < max_opened):
                helper_function(curr+'(', opened_parentheses+1, closed_parentheses, left-1)
        
        
    helper_function('', 0, 0, n*2)
    return result

print(ans(3))
