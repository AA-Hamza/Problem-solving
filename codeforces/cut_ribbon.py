import sys
sys.setrecursionlimit(10000)

n, a, b, c = map(int, input().split())
_p = set([a, b, c])
_ = set()
for i in _p:
    for j in _p:
        if (i == j):
            continue
        #print(i, j)
        if (i % j == 0):
            #print("BRUH")
            _.add(i)

#print(_)
#print(_p)
p = sorted(list(_p-_))
#print(p)

results = []
def solve(n, p, pieces):
    if (n == 0):
        #print(pieces)
        if (len(results) == 3):
            print(max(results))
            exit(0)

        results.append(pieces)
        return
        #exit(0)
    for i in p:
        if (n - i >= 0):
            n -= i
            #print("minused ", i)
            solve(n, p, pieces+1)
            #print("plused ", i)
            n += i
        else:
            break

solve(n, p, 0)
print(max(results))
