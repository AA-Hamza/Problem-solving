n, h = map(int, input().split())
frens = map(int, input().split())
result = n
for p in frens:
    if p > h:
        result += 1

print(result)
