/* Author Ahmed Anwar
 * Problem Link https://codeforces.com/problemset/problem/821/C
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int main()
{
    int t;
    cin >> t;
    t *= 2;
    stack<int> s;
    int curr = 1;
    int result = 0;
    while (t--) {
        string op;
        cin >> op;
        if (op == "add") {
            int n;
            cin >> n;
            s.push(n);
        }
        else if (op == "remove"){
            if (!s.empty()) {
                if (s.top() != curr) { // reorder
                    while (!s.empty())
                        s.pop();
                    result++;
                }
                else {
                    s.pop();
                }
            }
            curr++;
        }
    }
    cout << result << endl;
    return 0;
}

