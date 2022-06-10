/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/coin-change/
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int solve(vector<int> &coins, vector<int> &dp, int left) {
    if (dp[])
}

int coinChange(vector<int> &coins, int amount) {
    sort(coins.rend(), coins.rbegin());
    vector<int> dp(coins.size(), 1);
    return solve(coins, dp, amount);
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

