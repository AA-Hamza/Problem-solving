'''
    Problem Link http://codeforces.com/contest/427/problem/B
'''
n, t, c = map(int, input().split())
prisoners = list(map(int, input().split()))

start = 0
end = 0
result = 0
for end in range(len(prisoners)):
    if (prisoners[end] > t):
        length = end-start

        if (length >= c):
            result += length-c+1

        start = end+1

if ((end-start+1) >= c):
    result += end-start-c+2
print(result)
