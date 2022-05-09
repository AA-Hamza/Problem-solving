/*
 * https://codeforces.com/problemset/problem/1660/A
 */
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (!a) {
            cout << 1 << endl;
            continue;
        }
        if (!b) {
            cout << a+1 << endl;
            continue;
        }

        cout << a+2*b+1 << endl;
    }
}
