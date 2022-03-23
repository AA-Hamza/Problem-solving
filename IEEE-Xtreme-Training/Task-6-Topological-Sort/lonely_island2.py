'''
    Problem Link https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/lonelyisland-49054110/
    This code fails many cases, don't copy. the topics are covered, I am too tired to fix this code errors
'''

n, m, r = map(int, input().split())
r -= 1
adj_list = [[] for _ in range(n)]
nodes_probs = [0]*n
terminal_nodes = [0]*n

def dfs(node_index, probability):
    nodes_probs[node_index] += probability
    out_arrows = len(adj_list[node_index])
    if (out_arrows == 0):
        terminal_nodes[node_index] = 1
    for to in adj_list[node_index]:
        dfs(to, (probability/out_arrows)*nodes_probs[node_index])
        
for _ in range(m):
    f, t = map(int, input().split())
    f -= 1
    t -= 1
    adj_list[f].append(t)

def main():
    dfs(r, 1)
    result = []

    max_prob = 0
    for i in range(n):
        if (terminal_nodes[i]):
            max_prob = max(nodes_probs[i], max_prob)
    for i in range(n):
        if (terminal_nodes[i]):
            if abs(nodes_probs[i]-max_prob) <= 10e-9:
                result.append(i+1)
    result.sort()
    print(" ".join(map(str, result)))

main()
