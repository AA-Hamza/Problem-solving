'''
    Author: Ahmed Anwar
    Problem Link: https://codeforces.com/problemset/problem/445/A 
'''

#from collections import *
#import array

n, m = map(int, input().split())
matrix = [input() for _ in range(n)]
prev = 'B'
for i in range(n):
    for j in range(m):
        if (matrix[i][j] == '-'):
            print('-', end="")
        else:
            print(prev, end="")
        prev = 'W' if prev == 'B' else 'B'
    print("\n", end="")
    if (m % 2 == 0):
        prev = 'W' if prev == 'B' else 'B'
