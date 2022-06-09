/* Author Ahmed Anwar
 * Problem Link https://codeforces.com/gym/101972/problem/E
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int main()
{
    int t;// = 1;
    cin >> t;
    while (t--) {
        ull n, m, k;
        cin >> n >> m >> k;
        ull *tests = new ull[n];
        for (ull i = 0; i < n; ++i) {
            string c;
            cin >> c;
            if (c[0] == 'S')
                tests[i] = 0;
            else if (c[0] == 'B')
                tests[i] = 1;
        }

        ull seen_til = k-1;
        ull stupid = 0;
        for (ull i = 0; i < m; ++i) {
            string c;
            cin >> c;
            if (c[0] == 'A') {
                seen_til = n;
                continue;
            }
            else if (c[0] == 'W') {
                int x;
                cin >> x;
                x--;
                if (tests[x] == 0) {
                    if (x <= seen_til)
                        stupid++;
                }
                if (seen_til < x)
                    seen_til = x;
            }
        }
        cout << stupid << endl;
        delete []tests;

    }
    return 0;
}

