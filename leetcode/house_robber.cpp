/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/house-robber/
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

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
int rob(vector<int>& nums) {
    vector<int> dp(150, -1);
    return solve(nums, 0, dp);
}

int main()
{
    int t;// = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
    }
    return 0;
}

