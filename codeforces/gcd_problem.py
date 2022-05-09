"""
    https://codeforces.com/problemset/problem/1617/B
"""
from math import gcd
t = int(input())
cases = {}
for _ in range(t):
    n = int(input())
    if n in cases:
        print(*cases[n])
        continue
    a = 2
    while a < n:
        b = n - 1 - a
        if gcd(a, b) == 1:
            print(a, b, 1)
            cases[n] = (a, b, 1)
            break
        a += 1

