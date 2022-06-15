/* Author Ahmed Anwar
 * Problem Link https://codeforces.com/contest/1692/problem/E
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;


int main()
{
    int t;// = 1;
    cin >> t;
    while (t--) {
        vector<int> queue;
        int n, s;
        cin >> n >> s;
        unsigned long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            queue.push_back(tmp);
            sum += tmp;
        }
        if (sum < s) {
            cout << -1 << endl;
            continue;
        }
        else if (sum == s) {
            cout << 0 << endl;
            continue;

        }
        int curr_sum = 0;
        int ans = -1;
        for (int r = 0, l = 0; l < n; ++l) {
            if (l > r) {
                r = l;
                curr_sum = 0;
            }
            while (r < n && curr_sum + queue[r] <= s) {
                curr_sum += queue[r];
                r++;
            }

            ans = max(r-l, ans);
            curr_sum -= queue[l];
        }
        cout << n - ans << endl;
    }
    return 0;
}

