/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/subsets/
 * There is an easy solution to this problem with no recursion 
 * but I am training for back tracking 
 */


#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

class Solution {
public:
    static vector<vector<int>> solve(vector<int> &nums, vector<int> &curr, int index = 0) {
        static vector<vector<int>> result;
        if (index == nums.size())
            return result;
        // Pushing
        curr.push_back(nums[index]);
        result.push_back(curr);
        solve(nums, curr, index+1);

        curr.pop_back();
        solve(nums, curr, index+1);

        return result;
    }
    static vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        auto result = solve(nums, curr);
        result.push_back({});
        return result;
    }
};


int main()
{
    //vector<int> nums{1, 2, 3};
    vector<int> nums{0};
    //vector<int> nums{1, 2};
    vector<vector<int>> result = Solution::subsets(nums);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

