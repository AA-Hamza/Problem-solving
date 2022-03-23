'''
    Problem Link https://csacademy.com/ieeextreme-practice/task/09f92a575cc006d4a6a7f525f370ec30/
'''

fibonacci = [1, 1, *[0]*59]
def fill_fib():
    for i in range(2, 60 + 1):
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 10;
 
def findLastDigit(n):
    return fibonacci[n % 60];
 
fill_fib()
t = int(input())
for _ in range(t):
    m = int(input())
    print(findLastDigit(m))
