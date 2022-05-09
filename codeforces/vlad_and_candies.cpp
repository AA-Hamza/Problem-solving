/*
 * https://codeforces.com/problemset/problem/1660/B
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        int maxmax = 0;
        int secmax = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] > maxmax) {
                secmax = maxmax;
                maxmax = arr[i];
            }
            else if (arr[i] >= secmax) {
                secmax = arr[i];
            }
        }
        if (maxmax - secmax > 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
