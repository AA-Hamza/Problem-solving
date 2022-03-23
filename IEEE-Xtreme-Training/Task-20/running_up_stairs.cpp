/*
 *  Problem Link https://csacademy.com/ieeextreme-practice/task/96c8b1313edd72abf600facb0a14dbab/
 */

#include <iostream>
#include <map>

using namespace std;

map<unsigned long long, unsigned long long> dp;

unsigned long long steps(unsigned long long left) 
{
    if (left < 2) {
        return 1;
    }
    if (dp.find(left) != dp.end()) {
        return dp[left];
    }
    unsigned long long ways = 0;
    ways += steps(left-2);
    ways += steps(left-1);
    dp.insert(make_pair(left, ways));
    return ways;
}

int main()
{
    unsigned long long t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        cout << steps(n) << endl;
    }
}
