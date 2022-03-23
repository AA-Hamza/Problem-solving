/*
 * Problem Link https://csacademy.com/ieeextreme-practice/task/e1e444f71a2a7a69baf4c61ed756aa55/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> *adj_list;
int *visited;
int  *blocked;

bool DFS(int at, int parent)
{
    visited[at] = true;
    for (int w: adj_list[at])
    {
        if (!visited[w])
        {
            if (DFS(w, at)) {
                blocked[w] = blocked[at] = blocked[w] = true;
                return true;
            }
        }
        else if (w != parent)
        {
            blocked[w] = blocked[at] = true;
            return true;
        }
    }
    return false;
}


int dfs(int at, int parent) {
    if (visited[at] == 1) {
        blocked[at] = 1;
        return at;
    }
    visited[at] = 1;
    int result = 0;
    for (auto neighbour : adj_list[at]) {
        if (neighbour != parent) {
            result = dfs(neighbour, at);
            if (result) {
                blocked[at] = 1;
                if (result == at)
                    result = 0;
            }
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj_list = new vector<int>[n+1]();
    visited = new int[n+1]();
    blocked = new int[n+1]();

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    /*
    for (int i = 1; i < n+1; ++i) {
        if (!visited[i])
            dfs(i, 0);
    }
    */
    dfs(1, 0);

    for (int i = 1; i < n+1; ++i) {
        cout << i << " " << blocked[i] <<  endl;
        /*
        if (!blocked[i])
            cout << i << endl;
            */
    }
}
