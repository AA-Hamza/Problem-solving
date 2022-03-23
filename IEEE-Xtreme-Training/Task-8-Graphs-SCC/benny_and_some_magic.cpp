/*
 *  Problem Link https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/benny-and-some-magic/
 *  The idea behind mn, mx arrays is how low/high can I reach the specified node that is why it is typed dfs(edge[i].to, edge[i].w) not edge[i].from
 *  Cause we can't reach the edge[i].from with that weight. It took me a while to figure that out even after opening editorial.
 */
#include <algorithm>
#include <iostream>
#include <vector>

#define INF (1<<30)

using namespace std;

typedef struct {
    int from, to, w;
} Edge;

vector<int> *adj_list;
int *visited;
int *val, *mx, *mn;
Edge *edges;

void dfs(int at, int w) {
    if (visited[at])
        return;

    val[at] = w;
    visited[at] = 1;
    for (auto &neighbour : adj_list[at]) {
        dfs(neighbour, w);
    }
}

int main()
{
    int rooms, doors;
    cin >> rooms >> doors;
    adj_list = new vector<int>[rooms]();
    visited = new int[rooms]();
    val = new int[rooms];
    mx = new int[rooms];
    mn = new int[rooms];
    edges = new Edge[doors];


    for (int i = 0; i < doors; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        adj_list[v].push_back(u);
        edges[i] = {v, u, w};
    }
    sort(edges, edges+doors, [](const Edge &a, const Edge&b) {
            return a.w < b.w;
        }
    );

    fill_n(val, rooms, INF);
    for (int i = 0; i < doors; ++i) {
        dfs(edges[i].to, edges[i].w);
    }
    copy(val, val+rooms, mn);

    fill_n(visited, rooms, 0);
    fill_n(val, rooms, -INF);
    for (int i = doors-1; i >= 0; --i) {
        dfs(edges[i].to, edges[i].w);
    }

    copy(val, val+rooms, mx);

    int result = 0;
    for (int i = 0; i < doors; ++i) {
        int curr = edges[i].from;
        if (mn[curr] != INF) {
            result = max(result, edges[i].w-mn[curr]);
        }
        if (mx[curr] != -INF) {
            result = max(result, mx[curr]- edges[i].w);
        }
    }
    cout << result << endl;
}
