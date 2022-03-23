/**
 * Use heap for pq
 *
 */


#include <iostream>
//#include <array>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
struct Edge{
    ull to;
    ull cost;
    Edge(ull to, ull cost): to{to}, cost{cost}
    {}
    friend bool operator < (Edge const &, Edge const &);
};
typedef struct Edge Edge;

bool operator < (Edge const &e1, Edge const &e2) {
    return (e1.cost < e2.cost);
}


void add_edges(vector<Edge> *adj_list, priority_queue<Edge> *pq, int *visited, ull node_index) {
    visited[node_index] = 1;
    for (Edge edge : adj_list[node_index]) {
        if (!visited[edge.to])
            pq->emplace(edge);
    }
}


pair<vector<ull>*, ull> prims(vector<Edge> *adj_list, ull n) {

    const ull m = n-1;
    ull edge_count = 0, mst_cost = 0;

    vector<ull> *mst_edges = new vector<ull>;
    priority_queue<Edge> *pq = new priority_queue<Edge>;
    ull start = 1;

    int *visited = new int[n];
    for (int i = 0; i < n; ++i)
        visited[i] = 0;

    add_edges(adj_list, pq, visited, start);
    while (!pq->empty() && edge_count != m) {
        //cout << edge_count << " " << m << endl;
        Edge edge = pq->top();
        pq->pop();
        //cout << "EDGE "<< edge.to << " " << edge.cost << endl;
        ull node_index = edge.to;

        if (visited[node_index]) {
            continue;
        }

        mst_edges->push_back(edge.cost);
        edge_count++;
        mst_cost += edge.cost;
        
        add_edges(adj_list, pq, visited, node_index);
    }

    //cout << edge_count << " " << m << endl;
    if (edge_count != m) {
        return make_pair(nullptr, -1);
    }
    return make_pair(mst_edges, mst_cost);
}

int main()
{
    ull n, m, k;
    cin >> n >> m >> k;

    vector<Edge> *adj_list = new vector<Edge>[n+1];
    for (ull i = 0; i < m; ++i) {
        ull from, to, cost;
        cin >> from >> to >> cost;
        adj_list[from].push_back(Edge(to, cost));
        adj_list[to].push_back(Edge(from, cost));
    }

    auto result = prims(adj_list, n);
    vector<ull> *edges = result.first;
    ull edges_cost = result.second;
    if (edges == nullptr) {
        if (edges_cost < k) {
            cout << "0" << endl;
        }
        else {
            cout << "-1" << endl;
        }
        return 0;
    }
    sort(edges->rbegin(), edges->rend());


    int transformed = 0;
    for (auto &e : *edges) {
        if (edges_cost < k) {
            break;
        }
        edges_cost -= e + 1;
        transformed++;
    }
    if (transformed > k)
        cout << "-1" << endl;
    else 
        cout << transformed << endl;

    /*
    for (auto &e : *edges) {
        cout << e << " ";
    }
    cout << endl;
    */

    //cout << edges_cost << endl;
}
