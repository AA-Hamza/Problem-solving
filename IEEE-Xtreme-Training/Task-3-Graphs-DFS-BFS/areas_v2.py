'''
    Problem Link https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/areas-0475fb6e/
'''
def get_area(matrix, r, c):
    if (matrix[r][c] == 'v'):
        return 0
    columns = len(matrix[0])
    rows = len(matrix)
    area = 0
    if (matrix[r][c] == '.'):
        area = 1
        matrix[r][c] = 'v'
        if (r < rows-1):
            area += get_area(matrix, r+1, c)
        if (c < columns-1):
            area += get_area(matrix, r, c+1)
    return area

t = int(input())
for _ in range(t):
    rows, columns = map(int, input().split())
    matrix = []
    for i in range(rows):
        matrix.append(list(input()))
    result = []
    for r in range(rows):
        for c in range(columns):
            if (matrix[r][c] == '.'):
                result.append(get_area(matrix, r, c))

    print(len(result))
    print(' '.join(map(str, result)))

