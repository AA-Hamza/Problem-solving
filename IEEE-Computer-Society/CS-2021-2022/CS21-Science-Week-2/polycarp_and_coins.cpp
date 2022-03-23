/*
 * https://codeforces.com/problemset/problem/1551/A
 *
 * Basically you have 3 cases, test for them
 * 1. C1 = C2
 * 2. C1 = C2 + 1
 * 3. C1 = C2 - 1
*/
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int checkout;
        cin >> checkout;
        int c2, c1;
        if (checkout % 3 == 0) {
            c2 = checkout/3;
            c1 = c2;
        }
        else if ((checkout-1) % 3 == 0) {
            c2 = (checkout-1)/3;
            c1 = c2+1;
        }
        else {
            c2 = (checkout+1)/3;
            c1 = c2-1;
        }
        cout << c1 << " " << c2 << endl;
    }
}
