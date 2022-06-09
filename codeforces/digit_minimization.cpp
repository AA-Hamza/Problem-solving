/* Author Ahmed Anwar
 * Problem Link https://codeforces.com/contest/1684/problem/A
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        if (n.size() == 2) {
            cout << n[1] << endl;
        }
        else {
            auto it = min_element(n.begin(), n.end());
            cout << *it << endl;
        }
    }

    return 0;
}

