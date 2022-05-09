"""
    Problem Link https://codeforces.com/contest/221/problem/A
"""
"""
could just print n, then 1 ... n-1
"""
import sys
sys.setrecursionlimit(10000)
n = int(input())
l = [x for x in range(1, n+1)]
def recursion(a):
    if (a == 0):
        return;
    l[a], l[a-1] = l[a-1], l[a]
    #print(l)
    recursion(a-1)
recursion(n-1)
print(*l)
