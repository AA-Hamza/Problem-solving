def construct_term(power, multiple, negative):
    return f"{power} x {'-' if negative else ''}{multiple}"
    


def solve(m):
    negative = False
    if (m < 0):
        negative = True
        m = abs(m)
    l = []
    start = len(str(m))-1
    tens = 10**start
    while (m != 0):
        l.append((tens, m // tens))
        m %= tens
        tens //= 10
    result = []
    for power, multiple in l:
        if (multiple):
            result.append(construct_term(power, multiple, negative))
            result.append('+')
    return ' '.join(result[:-1])




t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    print(solve(a*b))
