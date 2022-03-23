'''
    Problem Link https://csacademy.com/ieeextreme-practice/task/09f92a575cc006d4a6a7f525f370ec30/
'''

#There are 2 approaches either pre-calculating the entire fib for the biggest m and then using this list to print output and that would be O(max(ms))
#The other option is to compute for every m with O(log m)

_MATRIX = [[1, 1], [1, 0]]
_IDENTITY_MATRIX = [[1, 0], [0, 1]]

def multiply(A, B):
    #2x2 x 2x2
    new_matrix = [[0, 0], [0, 0]]
    new_matrix[0][0] = A[0][0]*B[0][0]+A[0][1]*B[1][0]
    new_matrix[0][1] = A[0][0]*B[0][1]+A[0][1]*B[1][1]
    new_matrix[1][0] = A[1][0]*B[0][0]+A[1][1]*B[1][0]
    new_matrix[1][1] = A[1][0]*B[0][1]+A[1][1]*B[1][1]
    return new_matrix

def power(matrix, n):
    if (n == 0):
        return _IDENTITY_MATRIX#multiply(matrix, _IDENTITY_MATRIX)
    temp = power(matrix, n//2)
    if (n % 2 == 0):
        return multiply(temp, temp)
    else:
        return multiply(matrix, multiply(temp, temp))

def get_fib(m):
    fib_mat = power(_MATRIX, m)
    return fib_mat[0][0]

t = int(input())
fibs = []
ms = []
for _ in range(t):
    ms.append(int(input()))

max_m = max(ms)+1
curr_mat = _MATRIX
for i in range(0, max_m):
    fibs.append(curr_mat[0][0])
    curr_mat = multiply(curr_mat, _MATRIX)

#print(fibs)

for i in range(len(ms)):
    print(fibs[ms[i]-1]%10)

