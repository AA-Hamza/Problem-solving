'''
    Problem Link https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/practice-problems/algorithm/the-rise-of-the-weird-things-1/
'''

n = int(input())
zombies = []
vampires = []
creatures = map(int, input().split())
zombies_powers_sum = 0
vampires_powers_sum = 0
for c in creatures:
    if (c % 2 == 0):
        zombies.append(c)
        zombies_powers_sum += c
    else:
        vampires.append(c)
        vampires_powers_sum += c

zombies.sort()
vampires.sort()
print(" ".join(map(str, zombies)), zombies_powers_sum, " ".join(map(str, vampires)), vampires_powers_sum)
