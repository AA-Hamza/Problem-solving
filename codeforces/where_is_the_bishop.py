'''
    Author: Ahmed Anwar
    Problem Link: https://codeforces.com/contest/1692/problem/C
'''

#from collections import *
#import array

t = int(input())

while (t > 0):
    _ = input()
    board = [input() for _ in range(8)]
    for r in range(1, 7):
        for c in range(1, 7):
            if (board[r-1][c-1] == '#'
                    and board[r-1][c+1] == '#'
                    and board[r+1][c-1] == '#'
                    and board[r+1][c+1] == '#'):
                print(r+1, c+1)
                break


    t -= 1
