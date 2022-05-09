/*
 * https://codeforces.com/problemset/problem/1642/B
 */

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> distinct;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            distinct.insert(a);
        }
        int cnt = distinct.size();
        for (int k = 1; k <= n; ++k) {
            cout << max(cnt, k) << " ";
        }
        cout << endl;
    }
}
