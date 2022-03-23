'''
    Problem Link https://codeforces.com/problemset/problem/1547/C
'''

t = int(input())

for _ in range(t):
    input()
    k, n, m = map(int, input().split())
    polycarp = list(map(int, input().split()))
    monocarp = list(map(int, input().split()))
    actions = []
    a = 0
    b = 0
    flag1 = 0
    flag2 = 0
    while (a < n or b < m):
        if a < n:
            if (polycarp[a] == 0):
                actions.append(0)
                k += 1
                a += 1
                continue
            elif (polycarp[a] <= k):
                actions.append(polycarp[a])
                a += 1
                continue
            else:
                flag1 = 1
        if b < m:
            if (monocarp[b] == 0):
                actions.append(0)
                k += 1
                b += 1
                continue

            elif (monocarp[b] <= k):
                actions.append(monocarp[b])
                b += 1
                continue
            else:
                flag2 = 1

        if (flag1 and flag2 or (flag2 and a >= n) or (flag1 and b >= m)):
            actions = [-1]
            break
        else:
            flag1 = flag2 = 0

    print(" ".join(map(str, actions)))
