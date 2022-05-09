"""
    https://codeforces.com/problemset/problem/342/A
"""

possible = [(1, 2, 4), (1, 2, 6), (1, 3, 6)]

n = int(input())
s = list(map(int, input().split()))
myDict = {}
#total = 0
for i in [1, 2, 3, 4, 6]:
    myDict[i] = s.count(i)
    #total += myDict[i]
if (sum(myDict.values()) != n):
    print(-1)
    exit(0)

result = {} 
for i in possible:
    a = min([myDict[i[0]], myDict[i[1]], myDict[i[2]]])
    result[i] = a
    myDict[i[0]] -= a
    myDict[i[1]] -= a
    myDict[i[2]] -= a

if sum(myDict.values()) != 0:
    print(-1)
else:
    for key in possible:
        if (key in result):
            for i in range(result[key]):
                print(*key)

"""
def solve():
    for i in possible:
        while (i[0] in s and i[1] in s and i[2] in s):
            result.append(i)
            s.remove(i[0])
            s.remove(i[1])
            s.remove(i[2])
solve()
if (len(s) != 0):
    print(-1)
else:
    for i in result:
        print(*i)
"""
