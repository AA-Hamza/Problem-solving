/*
 * Problem Link https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
 */
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // The idea is to find parents with no incoming edges
        vector<int> indegree(n, 0);
        for (auto &edge: edges) {
            indegree[edge[1]] = 1;
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};
