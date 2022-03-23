/*
 * Problem Link https://leetcode.com/problems/all-paths-from-source-to-target/
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> curr;

void dfs(vector<vector<int>>& graph, vector<vector<int>>& list, int *visited, int start) {
    if (visited[start])
        return;
    curr.push_back(start);
    for (auto &neighbour: graph[start]) {
        dfs(graph, list, visited, neighbour);
    }
    if (start == graph.size()-1) {
        list.push_back(curr);
    }
    curr.pop_back();
}

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int *visited = new int[graph.size()]();
        vector<vector<int>> list;
        dfs(graph, list, visited, 0);
        return list;
    }
};
