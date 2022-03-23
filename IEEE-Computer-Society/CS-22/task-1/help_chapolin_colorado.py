'''
    Problem Link https://www.beecrowd.com.br/judge/en/problems/view/1917
'''
def fibonacci(a, b, n):
    if n < 0:
        print("Incorrect input")
    elif n == 0:
        return a
    elif n == 1:
        return b
    else:
        for _ in range(2,n+1):
            c = a + b
            a = b
            b = c
        return b

while (True):
    try:
        x, mf = map(int, input().split())
        if x == 0 and mf == 0:
            break
        print(fibonacci(x, 2*x, mf))
    except:
        break
