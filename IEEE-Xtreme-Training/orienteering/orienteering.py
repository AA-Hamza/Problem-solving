import math
import sys
sys.setrecursionlimit(10000)

n, m = map(int, input().split())
p = int(input())
start_r, start_j = map(int, input().split())
control_points = [(start_r, start_j)]
for i in range(p):
    control_points.append(tuple(map(int, input().split())))

runnability_matrix = []
for i in range(n):
    runnability_matrix.append(tuple(map(float, input().split())))

elevation_matrix = []
for i in range(n):
    elevation_matrix.append(tuple(map(float, input().split())))

matrix = [[float('inf')]*m for i in range(n)]
def check_valid_dir(fr, direction, prev_point):
    global n, m
    new_r = fr[0]+direction[0]
    new_c = fr[1]+direction[1]
    if ((new_r, new_c) == prev_point):
        return False
    if (new_r < 0 or new_r >= n):
        return False
    if (new_c < 0 or new_c >= m):
        return False
    return True

def best(fr, to, prev_cost, prev_point):
    #print('--->', fr, to)
    if (fr == to):
        matrix[to[0]][to[1]] = min(matrix[to[0]][to[1]], prev_cost)
        return

    matrix[fr[0]][fr[1]] = prev_cost

    if (prev_cost > matrix[to[0]][to[1]]):
        return

    DIR = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    for direction in DIR:
        if check_valid_dir(fr, direction, prev_point):
            new_r = fr[0]+direction[0]
            new_c = fr[1]+direction[1]
            to_run = runnability_matrix[new_r][new_c]
            from_run = runnability_matrix[fr[0]][fr[1]]
            to_ele = elevation_matrix[new_r][new_c]
            from_ele = elevation_matrix[fr[0]][fr[1]]
            new_cost = ((to_run+from_run)/2) * (math.e**(3.5*abs((to_ele-from_ele)/10+0.05)))
            total_cost = new_cost+prev_cost

            if (matrix[new_r][new_c] < total_cost):
                continue
            best((new_r, new_c), to, total_cost, fr)

    return

cost = 0
#print(control_points)
for i in range(len(control_points)-1):
    fr = control_points[i]
    to = control_points[i+1]
    best(fr, to, 0, (-1, -1));
    #print("----------")
    cost += matrix[to[0]][to[1]]
    matrix = [[float('inf')]*m for i in range(n)]

print(math.ceil(cost))
