/*
 * https://codeforces.com/problemset/problem/1672/A
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
        int totalChops = 0;
        for (int i = 0; i < n; ++i) {
            int chops;
            cin >> chops;
            totalChops += chops-1;
        }
        if (totalChops % 2) {
            cout << "errorgorn" << endl;
        }
        else {
            cout << "maomao90" << endl;
        }
    }
}
