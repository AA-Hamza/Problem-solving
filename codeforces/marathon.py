'''
    Author: Ahmed Anwar
    Problem Link: https://codeforces.com/contest/1692/problem/A
'''

t = int(input())
while t:
    l = list(map(int, input().split()))
    ans = 0
    for i in range(1, len(l)):
        if (l[i] > l[0]):
            ans+=1
    print(ans)
    t-=1

