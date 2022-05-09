n, m = map(int, input().split())
maze = [input() for x in range(n)]
order = input()

import itertools
dirs = ['D', 'L', 'U', 'R']
possible = list(itertools.permutations(dirs))
#print(possible)

robotLoc = tuple()
exitLoc = tuple()
for r in range(len(maze)):
    for c in range(len(maze[0])):
        if (maze[r][c] == 'S'):
            robotLoc = (r, c)
        elif (maze[r][c] == 'E'):
            exitLoc = (r, c)

#print(robotLoc)
#print(exitLoc)

def walk(curr):
    robotX = robotLoc[0]
    robotY = robotLoc[1]
    for i in range(len(order)):
        currDir = curr[int(order[i])]
        if currDir == 'D':
            robotX += 1
        elif currDir == 'U':
            robotX -= 1
        elif currDir == 'L':
            robotY -= 1
        elif currDir == 'R':
            robotY += 1
        if robotX < 0 or robotX >= n:
            return 0
        if robotY < 0 or robotY >= m:
            return 0
        if maze[robotX][robotY] == '#':
            return 0
        if robotX == exitLoc[0] and robotY == exitLoc[1]:
            return 1
    return 0

def solve():
    result = 0
    for each in possible:
        result += walk(each)
    return result

print(solve())
