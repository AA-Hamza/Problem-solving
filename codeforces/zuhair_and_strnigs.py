"""
https://codeforces.com/problemset/problem/1105/B
"""
n, k = map(int, input().split())
s = input()
distinctChars = set(s)
result = 0
for char in distinctChars:
    curr_result = 0
    curr_seq = 0
    for i in range(0, n):
        if s[i] == char:
            curr_seq += 1
        else:
            curr_seq = 0
        if curr_seq == k:
            curr_result += 1
            curr_seq = 0

    if curr_result > result:
        result = curr_result
print(result)
