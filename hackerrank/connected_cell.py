'''
    https://www.hackerrank.com/challenges/connected-cell-in-a-grid/
'''
def update_computed(computed, i, j):
    print("computed updated");
    computed[i][j] = 1

def count_region(matrix, computed, i, j):
    if (i == len(matrix) or i < 0):
        return 0
    if (j == len(matrix[0]) or j < 0):
        return 0
    if (matrix[i][j] == 0):
        return 0
    if (computed[i][j]):
        return 0
    
    count = 1
    computed[i][j] = 1
    #update_computed(computed, i, j);
    count += count_region(matrix, computed, i+1, j)
    count += count_region(matrix, computed, i, j+1)

    count += count_region(matrix, computed, i+1, j+1)
    count += count_region(matrix, computed, i+1, j-1)
    count += count_region(matrix, computed, i-1, j+1)
    return count
    
def connectedCell(matrix):
    n = len(matrix)
    m = len(matrix[0])
    computed = [ [0 for c in range(m)] for r in range(n)]
    max_area = 0
    print("before execution", computed)
    for i in range(0, n):
        for j in range(0, m):
            if (matrix[i][j] == 1 and computed[i][j] == 0):
                print(computed)
                region = count_region(matrix, computed, i, j)
                if (region > max_area):
                    max_area = region
             
    print("after execution", computed)
    return max_area

n = int(input())
m = int(input())
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().split())))

print(connectedCell(matrix))
