'''
    https://codeforces.com/problemset/problem/124/B
'''
n, k = map(int, input().split())
matrix = [input() for x in range(n)]
min_diff = 9999999999
import itertools
permuts = itertools.permutations([x for x in range(k)])
for possible in permuts:
    temp = ['' for x in range(n)]
    for c in possible:
        for r in range(n):
            temp[r] = temp[r] + matrix[r][c]
    for r in range(n):
        temp[r] = int(temp[r])
    min_diff = min(min_diff, max(temp)-min(temp))
print(min_diff)
