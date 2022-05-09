"""
    Problem Link https://codeforces.com/problemset/problem/219/A
"""
k = int(input())
s = input()
distinct = set(s)
#if (len(distinct) > k):
#    print(-1)
#    exit(0)
myDict = {}
for char in distinct:
    if (s.count(char) % k != 0):
        print(-1)
        exit(0)
    myDict[char] = s.count(char) // k

#print(myDict)
for i in range(k):
    for j in distinct:
        print(j * myDict[j], end="", sep="")
    #print(*distinct,end="", sep="")
