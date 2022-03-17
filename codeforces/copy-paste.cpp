/*
 * Problem Link https://codeforces.com/contest/1417/problem/A
 */

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, k;
    while (t--) {
        cin >> n >> k;
        int *piles = new int[n];
        int minVal = 10e4+1, minIndex;
        for (int i = 0; i < n; ++i) {
            cin >> piles[i];
            if (piles[i] < minVal) {
                minVal = piles[i];
                minIndex = i;
            }
        }

        piles[minIndex] = piles[0];
        piles[0] = minVal;

        //cout << "minVal: " << minVal << endl;
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            sum += (k-piles[i])/minVal;
        }

        cout << sum << endl;
    }
}
