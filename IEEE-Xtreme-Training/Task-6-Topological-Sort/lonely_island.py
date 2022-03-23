'''
    Problem Link https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/lonelyisland-49054110/
'''

n, m, r = map(int, input().split())
r -= 1
adj_list = [[] for _ in range(n)]
in_degree = [0]*n
nodes_depth = [-1]*n

def dfs(node_index, depth):
    nodes_depth[node_index] = depth
    if (len(adj_list[node_index]) == 0):
        in_degree[node_index] += 1
        return
    else:
        in_degree[node_index] = -1


    for to in adj_list[node_index]:
        dfs(to, depth+1)
        
for _ in range(m):
    f, t = map(int, input().split())
    f -= 1
    t -= 1
    adj_list[f].append(t)

dfs(r, 0)

result = []
for i in range(n):


'''
highest_indeg = max(in_degree)
print("highest_indeg =", highest_indeg)
highest_indegree_nodes = [i for i in range(len(in_degree)) if in_degree[i] == highest_indeg]
print("highest_indegree_nodes =", highest_indegree_nodes)
lowest_depth = nodes_depth[highest_indegree_nodes[0]]
print("lowest_depth =", lowest_depth)
for i in highest_indegree_nodes:
    lowest_depth = min(lowest_depth, nodes_depth[i])
result = [x+1 for x in highest_indegree_nodes if nodes_depth[x]==lowest_depth]
print("result =", result)
result.sort()
print(" ".join(map(str, result)))

print("97966 depth =", nodes_depth[97965])
print("97966 indeg =", in_degree[97965])
'''
