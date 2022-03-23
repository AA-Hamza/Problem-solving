'''
    Problem Link http://codeforces.com/problemset/problem/1559/B
'''

def opposite(e):
    if (e == 'R'):
        return 'B'
    return 'R'

t = int(input())
for _ in range(t):
    n = int(input())
    word = list(input())
    empty_places = 0
    for c in word:
        if (c == '?'):
            empty_places += 1

    if (empty_places == n):
        prev = 'B'
        for i in range(n):
            word[i] = prev
            prev = opposite(prev)
    elif empty_places > 0:
        while (empty_places != 0):
            for i in range(0, n):
                if word[i] == '?':
                    if (i > 0) :
                        if (word[i-1] != '?'):
                            word[i] = opposite(word[i-1])
                            empty_places -= 1
                            continue

                    if (i < n-1):
                        if (word[i+1] != '?'):
                            word[i] = opposite(word[i+1])
                            empty_places -= 1
                            continue
    print(''.join(word))
