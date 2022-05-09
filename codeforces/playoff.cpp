/*
 * https://codeforces.com/problemset/problem/1651/A
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (int)round((powl(2, n)-1)) << endl;
    }
}
