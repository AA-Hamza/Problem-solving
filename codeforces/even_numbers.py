#from functools import cache
from functools import lru_cache
import sys

sys.setrecursionlimit(100000)



def calc(i, j):
    if j == 0:
        return 1
    if j <= -1 or j > i:
        return 0
    return calc(i-1, j-1)+calc(i-1, j)

t = int(input())
for _ in range(t):
    n = int(input())
    ans = 0
    for m in range(0, n//2+1):
        result = calc(n, m)
        if (result % 2 == 0):
            #print(m, result)
            ans += 1
    print(ans*2)
