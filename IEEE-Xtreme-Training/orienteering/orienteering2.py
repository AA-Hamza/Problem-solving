import math
import sys
import heapq
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

def cal(fr, new_r, new_c):
    to_run = runnability_matrix[new_r][new_c]
    from_run = runnability_matrix[fr[0]][fr[1]]
    to_ele = elevation_matrix[new_r][new_c]
    from_ele = elevation_matrix[fr[0]][fr[1]]
    new_cost = ((to_run+from_run)/2) * (math.e**(3.5*abs((to_ele-from_ele)/10+0.05)))
    return new_cost


efforts = [[math.inf] * m for _ in range(n)]
def minimumEffortPath(at, to):
    global n, m
    efforts[at[0]][at[1]] = 0
    heap = [(0, at[0], at[1])]
    while heap:
        effort, x, y = heapq.heappop(heap)
        if (x, y) == (to[0], to[1]):
            return effort
        for r, c in (x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y):
            if n > r >= 0 <= c < m:
                next_effort = effort+cal((x, y), r, c)
                if efforts[r][c] > next_effort:
                    efforts[r][c] = next_effort
                    heapq.heappush(heap, (next_effort, r, c))
cost = 0
for i in range(len(control_points)-1):
    fr = control_points[i]
    to = control_points[i+1]
    minimumEffortPath(fr, to)
    cost += efforts[to[0]][to[1]]
    efforts = [[float('inf')]*m for i in range(n)]
print(math.ceil(cost))
