/*
 * Problem Link https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/
 * So this code passes all test cases except one. I know what is going on, but don't have an idea for how to solve it.
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int *solve(int start, int n, vector<int> *adj_list) {
    queue<int> q;
    q.push(start);

    int *visited = new int[n];
    memset(visited, 0, n);
    
    visited[start] = 1;

    int *prev = new int[n];
    for (int i = 0; i < n; ++i) {
        prev[i] = -1;
    }

    while (q.empty() != 1) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < adj_list[node].size(); ++i) {
            int next = adj_list[node][i];
            if (visited[next] == 0) {
                q.push(next);
                visited[next] = 1;
                prev[next] = node;
            }
        }
    }
    free(visited);
    return prev;
}

vector<int> bfs(int start, int end, int n, vector<int> *adj_list)
{
    int *prev = solve(start, n, adj_list);
    vector<int> path;
    for (int at = end; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n, m, t, c;
    cin >> n >> m >> t >> c;
    // I don't think that t or c matters
    vector<int> adj_list[n];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        sort(adj_list[i].begin(), adj_list[i].end());
        //reverse(adj_list[i].begin(), adj_list[i].end());
    }
    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    vector<int> path = bfs(x, y, n, adj_list);
    cout << path.size() << endl;
    for (auto e : path) {
        cout << e+1 << " ";
    }
    cout << endl;
}
