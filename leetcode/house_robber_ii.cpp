/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/house-robber-ii/
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int solve(vector<int> &nums, int index, vector<int> &dp) {
    if (index >= nums.size())
        return 0;
    if (dp[index] != -1) {
        return dp[index];
    }
    int picked = nums[index]+solve(nums, index+2, dp);
    int not_picked = solve(nums, index+1, dp);
    
    dp[index] = max(picked, not_picked);
    return dp[index];
}

int rob(const vector<int>& nums) {
    vector<int> dp1(1001, -1);
    vector<int> dp2(1001, -1);
    vector<int> first(nums.begin(), nums.end()-1);
    vector<int> end(nums.begin()+1, nums.end());
    int m1 = solve(first, 0, dp1);
    int m2 = solve(end, 0, dp2);
    return max(m1, m2);
}

int main()
{
    cout << rob(vector<int>{1, 3, 1, 3, 100}) << endl;
    return 0;
}

