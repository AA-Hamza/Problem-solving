/* Author Ahmed Anwar
 * Problem Link https://codeforces.com/contest/1692/problem/G
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int cal(int sub, int k) {
    if (sub < k)
        return 0;

    return sub-k+1;
}

int main()
{
    int t;// = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int prev;
        cin >> prev;
        int ans = 0;
        int sub = 0;
        for (int i = 1; i < n; ++i) {
            int curr;
            cin >> curr;
            if (curr*2 > prev) {
                sub++;
            }
            else {
                ans += cal(sub, k);
                sub = 0;
            }
            prev = curr;
        }
        ans += cal(sub, k);
        cout << ans << endl;
    }
    return 0;
}

