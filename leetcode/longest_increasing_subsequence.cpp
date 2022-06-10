/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/longest-increasing-subsequence/
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int solve(const vector<int> &nums, vector<int> &dp) {
    int result = 0;
    for (int j = 0; j < nums.size(); ++j) {
        int maxV = 0;
        for (int i = 0; i < j; ++i) {
            if (nums[i] < nums[j]) {
                maxV = max(dp[i], maxV);
            }
        }
        dp[j] = 1 + maxV;
        result = max(result, dp[j]);
    }
    return result;
}

int lengthOfLIS(const vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return solve(nums, dp);
}


int main()
{
    cout << lengthOfLIS({1,3,6,7,9,4,10,5,6}) << endl;
    return 0;
}

