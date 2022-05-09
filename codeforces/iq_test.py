"""
    https://codeforces.com/problemset/problem/287/A
"""
matrix = [input() for x in range(4)]
for i in [1, 2, 3]:
    for j in range(0, 3):
        da_case = matrix[i][j] + matrix[i-1][j] + matrix[i-1][j+1] + matrix[i][j+1]
        hash_tags = da_case.count('#')
        dots = da_case.count('.')
        if (hash_tags > 2 or dots > 2):
            print("YES")
            exit(0)
print("NO")
