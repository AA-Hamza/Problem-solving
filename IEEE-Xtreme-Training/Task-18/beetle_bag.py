t = int(input())


for _ in range(t):
    c, n = map(int, input().split())
    arr = [[-1]*(c+1) for i in range(n+1)]
    items = [(-1, -1)]
    for i in range(n):
        items.append(tuple(map(int, input().split())))

    def knapsack(n, c):
        if (arr[n][c] != -1):
            return arr[n][c]
        result = 0
        if (n == 0 or c == 0):
            result = 0
        elif items[n][0] > c:
            result = knapsack(n-1, c)
        else:
            tmp1 = knapsack(n-1, c)
            tmp2 = items[n][1]+knapsack(n-1, c-items[n][0])
            result = max(tmp1, tmp2)
        arr[n][c] = result
        return result

    print(knapsack(n, c))
