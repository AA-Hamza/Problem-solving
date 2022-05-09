t = int(input())

for _ in range(t):
    a = list(map(int, input().split()))
    dist = 0
    for i in a[1:]:
        dist += abs(i-a[0])
    print(dist)
