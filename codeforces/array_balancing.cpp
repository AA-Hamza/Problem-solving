/*
 * https://codeforces.com/problemset/problem/1661/A
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
        int *aArr = new int[n]();
        int *bArr = new int[n]();
        for (int i = 0; i < n; ++i) {
            cin >> aArr[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> bArr[i];
        }
        for (int i = 0; i < n; ++i) {
            int minValue = min(aArr[i], bArr[i]);
            int maxValue = max(aArr[i], bArr[i]);
            aArr[i] = minValue;
            bArr[i] = maxValue;
        }
        unsigned long long result = 0;
        for (int i = 1; i < n; ++i) {
            result += abs(aArr[i]-aArr[i-1]) + abs(bArr[i]-bArr[i-1]);
        }
        cout << result << endl;
    }
}
