/*
 * Problem Link https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/saving-ms-w-7b3d36df/
 */

#include <iostream>
#include <limits>

using namespace std;

typedef long long ll;
#define INF ((ll)10e16)


void print_matrix(ll n, ll **matrix) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void floyd(ll n, ll **matrix) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] > matrix[i][k]+matrix[k][j]) {
                    matrix[i][j] = matrix[i][k]+matrix[k][j];
                }
            }
        }
    }
}

int main()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a == b)
        return cout << 0, 0;

    ll **matrix = new ll*[n];
    int *c = new int[n], *h = new int[n];

    for (int i = 0; i < n; ++i) {
        matrix[i] = new ll[n];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = INF;
        }
    }

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        matrix[v][u] = matrix[u][v] = w;
    }

    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> h[i];
    }



    floyd(n, matrix);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = matrix[i][j] <= c[i]  ? h[i] : INF;
            /* This asking if I can get from i to j with i's fruit, if yes replace stamina with fruit otherwise infinity */
        }
    }
    floyd(n, matrix);
    a--, b--;
    cout << (matrix[a][b] == INF ? -1 : matrix[a][b]) << endl;
}
