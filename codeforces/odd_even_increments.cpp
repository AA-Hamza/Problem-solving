/*
 * https://codeforces.com/problemset/problem/1669/C
 */
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int arr[2][2] = {{0, 0}, {0, 0}};
        int n;
        cin >> n;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            arr[i%2][tmp%2]++;
        }
        if ((arr[0][0] == 0 || arr[0][1] == 0) && (arr[1][0] == 0 || arr[1][1] == 0)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
