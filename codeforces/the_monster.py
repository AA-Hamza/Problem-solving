a, b = map(int, input().split())
c, d = map(int, input().split())
for n in range(1000):
    #m = ((d+c*n)-b)/a
    m = (b + a*n - d) / c
    if (int(m) == m and m >= 0):
        print(b + a * n)
        exit(0)
print(-1)
