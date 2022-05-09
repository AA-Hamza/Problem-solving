/*
 * https://codeforces.com/problemset/problem/1671/A
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int aSeqLength = 0;
        int bSeqLength = 0;
        if (s[0] == 'a') {
            aSeqLength++;
        } else {
            bSeqLength++;
        }
        int flag = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == 'a') {
                if (s[i-1] == 'b') {
                    if (bSeqLength < 2) {
                        flag = 1;
                        cout << "NO" << endl;
                        break;
                    }
                    bSeqLength = 0;
                    aSeqLength = 0;
                }
                aSeqLength++;
            }
            else {
                if (s[i-1] == 'a') {
                    if (aSeqLength < 2) {
                        flag = 1;
                        cout << "NO" << endl;
                        break;
                    }
                    bSeqLength = 0;
                    aSeqLength = 0;
                }
                bSeqLength++;
            }
        }
        if (flag == 0) {
            if (bSeqLength >= 2 || aSeqLength >= 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
