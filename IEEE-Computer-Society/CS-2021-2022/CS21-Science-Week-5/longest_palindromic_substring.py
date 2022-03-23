'''
    Problem Link https://leetcode.com/problems/longest-palindromic-substring/submissions/
'''
def longestPalindrome(s):
    new_s = ''
    for i in range(len(s)):
        new_s += '$'+s[i]
    new_s += '$'
    s = new_s


    center = size = 0
    max_s = 0
    max_c = 0
    while (center < len(s)):
        l = center-1
        r = center+1
        size = 0
        while (l >= 0 and r < len(s) and s[l] == s[r]):
            size += 1
            l -=1
            r += 1
        if (size > max_s):
            max_s = size
            max_c = center
        
        center += 1
    
    ans = s[max_c]
    for i in range(1, max_s+1):
        ans = s[max_c-i]+ans
        ans = ans+s[max_c+i]
    
    ans = ans.replace('$', '')
    return ans
    
    
print(longestPalindrome('babad'))
print(longestPalindrome('cbbd'))
