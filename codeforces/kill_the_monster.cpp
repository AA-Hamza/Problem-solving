/*
 * https://codeforces.com/problemset/problem/1633/C
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long hc, dc, hm, dm;
        cin >> hc >> dc >> hm >> dm;
        long long k, w, a;
        cin >> k >> w >> a;
        for (long long i = 0; i <= k; ++i) {
            long long newhc = hc + i * a;
            long long newdc = dc + (k - i) * w;
            if ((long long)(hm+newdc-1)/newdc <= (long long)(newhc+dm-1)/dm) {
                cout << "YES" << endl;
                k = -1;
                break;
            }
        }
        if (k != -1)
            cout << "NO" << endl;
    }
}
