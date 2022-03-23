t = int(input())

for i in range(t):
    m, n, k = map(int, input().rstrip().split())
    to_be_switched_off = []
    for j in range(m):
        wired_correctly = int(input().strip())
        switched_off = n-wired_correctly
        to_be_switched_off.append(switched_off)

    to_be_switched_off.sort(reverse=True)

    solution = sum(to_be_switched_off[:k])
    solution += (len(to_be_switched_off[k:]))*n - sum(to_be_switched_off[k:])
    print(solution)
