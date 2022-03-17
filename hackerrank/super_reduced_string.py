'''
    https://www.hackerrank.com/challenges/reduced-string/
'''
import math
import os
import random
import re
import sys

def superReducedString(s):
    def recursion_reduction(n):
        nonlocal s
        #print(n, s)
        if (len(s)==2 and s[0] == s[1]):
            s=''
            return
        
        for i in range(n, len(s)-1):
            #print(s[i], s[i+1])
            if (s[i] == s[i+1]):
                s = s[:i] + s[i+2:]
                if (i == 0):
                    return recursion_reduction(0)
                    
                return recursion_reduction(i-1)
    
    recursion_reduction(0)
    return s

if __name__ == '__main__':
    print(superReducedString(input()))
