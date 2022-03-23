'''
    Problem Link http://codeforces.com/contest/141/problem/B
'''
result = -1
a, x, y = map(int, input().split())

if (y % a and abs(x) < a):
    if (y < a):
        if abs(x) < a/2:
            result = 1
    else:
        y -= a
        steps = (y // a)+1
        if (steps % 2 == 0):
            if (x != 0):
                if x < 0:
                    result = steps + steps//2
                else:
                    result = steps + steps//2 + 1
        else:
            if (abs(x) < a/2):
                result = steps + steps//2+1

print(result)
