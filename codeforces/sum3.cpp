/* Author Ahmed Anwar
 * Problem Link https://codeforces.com/contest/1692/problem/F
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int sum3[9][9][9];

void precompute() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9; ++k) {
                sum3[i][j][k] = ((i+j+k) % 10) == 3;
            }
        }
    }

}

int main()
{
    int t;// = 1;
    cin >> t;
    //precompute();
    while (t--) {
        int n;
        cin >> n;
        map<int, int> permuts;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            tmp %= 10;
            permuts[tmp]++;
            if (permuts[tmp] > 3) {
                permuts[tmp] = 3;
            }
        }

        for (auto it1 = permuts.begin(); it1 != permuts.end(); ++it1) {
            it1->second--;
            for (auto it2 = it1; it2 != permuts.end(); ++it2) {
                if (it2->second == 0)
                    continue;
                it2->second--;
                for (auto it3 = it2; it3 != permuts.end(); ++it3) {
                    if (it3->second == 0)
                        continue;
                    it3->second--;
                    //cout << "Trying"  << it1->first << it2->first << it3->first << endl;
                    //if (sum3[it1->first][it2->first][it3->first] ) {
                    if ((it1->first+it2->first+it3->first)%10 == 3) {
                        cout << "YES" << endl;
                        it1 = it2 = it3 = permuts.end();
                        goto success;
                    }
                    it3->second++;
                }
                it2->second++;
            }
            it1->second++;
        }

        cout << "NO" << endl;
success:
        continue;

    }
    return 0;
}

