def formula(line):
    _sum = 0
    for i in range(0, len(line)-1):
        _sum += line[i]*line[i+1]
    return _sum


def construct(sorted_line):
    _new = [sorted_line[0]]
    for i in range(1, len(sorted_line)-1):
        bigger = sorted_line[i]
        smaller = sorted_line[i+1]

    

t = int(input())
for _ in range(t):
    n = int(input())
    line = list(map(int, input().split()))
    sorted_line = sorted(line, reverse=True)

