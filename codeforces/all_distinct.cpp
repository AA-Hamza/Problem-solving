/* Author Ahmed Anwar
 * Problem Link https://codeforces.com/contest/1692/problem/B
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> a;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            a.insert(tmp);
        }
        if (((n-a.size()) % 2) == 1) {
            cout << a.size()-1 << endl;
        }
        else {
            cout << a.size() << endl;
        }
    }
    return 0;
}

