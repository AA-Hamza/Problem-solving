/*
 * https://codeforces.com/problemset/problem/1650/B
 */
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int l, r, a;
        cin >> l >> r >> a;
        int result = 0;
        for (int i = r; i >= l && i >= (r-a-1); --i) {
            result = max(result, i/a+i%a);
            if (i % a == a-1) {
                break;
            }
            i -= i % a;
        }
        cout << result << endl;
    }
}
