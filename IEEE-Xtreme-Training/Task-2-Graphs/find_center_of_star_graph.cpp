/*
 * Problem Link https://leetcode.com/problems/find-center-of-star-graph/
 */

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto &first = edges[0];
        auto &second = edges[1];
        for (auto &a: first) {
            for (auto &b: second) {
                if (a == b) {
                    return a;
                }
            }
        }
        return 0;
    }
};
