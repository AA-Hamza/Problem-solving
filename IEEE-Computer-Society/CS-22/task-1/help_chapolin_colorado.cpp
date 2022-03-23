/*
 * Problem link https://www.beecrowd.com.br/judge/en/problems/view/1917
 *
 * It is just fib sequence with X, 2*X as arguments
 */

#include <iostream>

#define MOD 1000000007
typedef unsigned long long ull;

using namespace std;

ull fib(ull a, ull b, ull limit) {
    ull c = 0;
    for (ull i = 0; i < limit; ++i) {
        c = a + b;
        c %= MOD;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ull x, mf;
    cin >> x >> mf;
    while (x != 0 and mf != 0) {
        cout << fib(x, 2*x, mf) << endl;
        cin >> x >> mf;
    }
}
