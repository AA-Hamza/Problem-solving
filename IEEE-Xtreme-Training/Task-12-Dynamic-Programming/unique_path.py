'''
    Problem Link https://leetcode.com/problems/unique-paths/submissions/
'''

def uniquePaths(m, n):
    matrix = [[-1]*n for x in range(m)]
    def recursive(r, c):
        if (matrix[r][c] != -1):
            return matrix[r][c]
        moves = 0
        if (r == m-1 or c == n-1):
            if (r < m-1):
                moves += recursive(r+1, c)
            elif (c < n-1):
                moves += recursive(r, c+1)
            else:
                return 1
        else:
            moves += recursive(r+1, c)
            moves += recursive(r, c+1)
        matrix[r][c] = moves
        return moves

    return recursive(0, 0)

print(uniquePaths(3, 7))
