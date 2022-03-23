/*
 * Problem Link https://leetcode.com/problems/network-delay-time/submissions/
 * This code kinda sucks but the idea is right. also it has a flow (depth function stack-overflow), Can't tail-recursion optomize it.
 * So I will leave it like that for time being.
 */
#define _MAX 10e6
bool compare_pairs(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}
class Solution {
public:
    vector<pair<int, int>> *construct_adj_list(vector<vector<int>>& times, int n) {
        vector<pair<int, int>> *adj_list = new vector<pair<int, int>>[n];
        for (auto &e : times) {
            adj_list[e[0]-1].push_back(make_pair(e[1]-1, e[2]));
        }
        return adj_list;
    }
    
    void depth(vector<pair<int, int>> *adj_list, int k, int elapsed, int *visited) {
        if (visited[k] < elapsed)
            return;
        visited[k] = elapsed;
        
        for (auto &neighbour : adj_list[k]) {
            depth(adj_list, neighbour.first, neighbour.second+elapsed, visited);
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int *visited = new int[n];
        for (int i = 0; i < n; ++i) 
            visited[i] = _MAX;
        vector<pair<int, int>> *adj_list = construct_adj_list(times, n);
        for (int i = 0; i < n; ++i) {
            sort(adj_list[i].begin(), adj_list[i].end(), compare_pairs);
        }
        depth(adj_list, k-1, 0, visited);
        int max_time = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == _MAX) {
                return -1;
            }
            else {
                max_time = max(visited[i], max_time);
            }
        }
        return max_time;
    }
};
