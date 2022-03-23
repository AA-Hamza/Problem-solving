/*
 *  Problem Link https://www.hackerrank.com/challenges/coin-change/problem
 */

#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >>  m;
    long long *coins = new long long[m]();
    for (long long i = 0; i < m; ++i) {
        cin >> coins[i];
    }

    long long *ans = new long long[n+1]();
    ans[0] = 1;
    for (long long i = 0; i < m; ++i) {
        long long curr_coin = coins[i];
        for (long long j = curr_coin; j < n+1; ++j) {
            ans[j] += ans[j-curr_coin];
        }
    }
    cout << ans[n] << endl;
}
