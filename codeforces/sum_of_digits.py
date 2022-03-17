'''
    http://codeforces.com/contest/102/problem/B
'''
iters   = 0
n       = int(input())

while (n > 9):
    n = sum(map(int, str(n)))
    iters += 1
print(iters)
