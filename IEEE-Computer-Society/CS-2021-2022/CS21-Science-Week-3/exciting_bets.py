'''
    Problem Link https://codeforces.com/problemset/problem/1543/A
'''

def cal(n, div_by):
    lower_by = n - (n//div_by)*div_by
    upper_by = ((n//div_by)*div_by+div_by)-n
    return min(lower_by, upper_by)

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    diff = abs(a-b)
    if (diff == 0):
        print(0, 0)
    else:
        steps = cal(b, diff)
        print(diff, steps)
