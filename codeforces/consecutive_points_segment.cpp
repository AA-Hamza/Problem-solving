/*
 * https://codeforces.com/problemset/problem/1671/B
 */
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int[n]();
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        if (arr[n-1] - arr[0] - n + 1 < 3) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
