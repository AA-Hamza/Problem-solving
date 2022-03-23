/*
 * Problem Link http://codeforces.com/problemset/problem/1557/B
 */
#include <iostream>
#define INF (long long)(10e10)

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long num_of_seq = 1;
        long long prev = -INF;
        long long curr;
        while (n--) {
            cin >> curr;
            if (curr < prev) {
                num_of_seq += 1;
            }
            prev = curr;
        }
        if (num_of_seq <= k){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
