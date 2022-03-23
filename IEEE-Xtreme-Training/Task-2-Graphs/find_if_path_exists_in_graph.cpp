/*
 *  Problem Link https://leetcode.com/problems/find-if-path-exists-in-graph/
 */
class Solution {
public:
    vector<int> *to_adj_list(vector<vector<int>> &edges, const int n) {
        vector<int> *l = new vector<int>[n];
        for (auto &e: edges) {
            l[e[0]].push_back(e[1]);
            l[e[1]].push_back(e[0]);
        }
        return l;
    }
    void dfs(vector<int> *adj_list, int at, int *visited, int target, int &found) {
        if (found == 1)
            return;
        if (visited[at] != 0)
            return;
        visited[at] = 1;
        vector<int> &neighbours = adj_list[at];
        for (auto &next : neighbours) {
            if (next == target) {
                found = 1;
                return;
            }
            dfs(adj_list, next, visited, target, found);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if (n == 1)
            return 1;

        vector<int> *adj_list = to_adj_list(edges, n);
        int *visited = new int[n];
        for (int i = 0; i < n; ++i) {
            visited[i] = 0;
        }
        int found = 0;
        dfs(adj_list, start, visited, end, found);
        return found;
    }
};
