from math import log
threshold = 10e-17

n, m = map(int, input().split())
if (m == n):
    print("0")
    exit(0)

target = m / n
a = 0
while (True):
    if (target % 2 == 0):
        a+=1
        target /= 2
    elif (target % 3 == 0):
        a+=1
        target /= 3
    else:
        if (target == 1):
            print(a)
        else:
            print(-1)
        exit(0)

