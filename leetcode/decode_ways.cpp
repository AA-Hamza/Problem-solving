/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/decode-ways/
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int n[1001];
int decode(string &s, int l) 
{
    if (n[l] != -1) {
        return n[l];
    }
    int count = 0;
    if (l == s.size()) {
        return 1;
    }
    if (l > s.size() || s[l] == '0') {
        return 0;
    }
    count += decode(s, l+1);
    if (l < s.size()-1 && (s[l] == '2' && s[l+1] <= '6') || (s[l] == '1')) {
        count += decode(s, l+2);
    }
    n[l] = count;
    return count;
}

int numDecodings(string s) {
    memset(n, -1, sizeof(n));
    return decode(s, 0);
}

int main()
{
    string s = "2611055971756562"; 
    //cin >> s;
    cout << numDecodings(s) << endl;
    return 0;
}

