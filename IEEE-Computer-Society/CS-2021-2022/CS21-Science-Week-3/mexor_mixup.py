'''
    Problem Link https://codeforces.com/problemset/problem/1567/B
'''

def n_xor(n):
    case = n % 4
    if case == 0:
        return n
    if case == 1:
        return 1
    if case == 2:
        return n+1
    return 0

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    a_xored = n_xor(a-1)
    if (a_xored == b):
        print(a)
        continue
    if (a_xored ^ b != a):
        print(a+1)
        continue
    print(a+2)
