'''
    Problem Link https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/gcd-on-directed-graph-1122228a/
'''

import math

n, m = map(int ,input().split())
costs = list(map(int, input().split()))
adj_list = [[] for _ in range(n)]
visited = [0]*n
min_cost = 10e10

for _ in range(m):
    v, u = map(int, input.split())
    v -= 1
    u -= 1
    adj_list[v].append(u)

def dfs(at, prev_gcd, prev_cost):
    if (visited[at]):
        return
    curr_gcd = math.gcd(prev_gcd, costs[at])
    for neighbour in adj_list[at]:
        dfs(at, prev_gcd, prev_cost)

