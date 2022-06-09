/* Author Ahmed Anwar
 * Problem Link 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int main()
{
    int t;// = 1;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string a, b;
        k--;
        cin >> a >> b;
        int ksubstrings[26][26] = {0};
        int appeared_before[26] = {0};

        ull results = 0;
        for (int i = 0; i < a.size()-k; ++i) {
            ksubstrings[a[i]-'a'][a[i+k]-'a'] = 1;
        }

        for (int i = 0; i < b.size(); ++i) {
            appeared_before[b[i]-'a']++;
            for (int j = 0; j < 26; ++j) {
                if (ksubstrings[j][b[i]-'a']) {
                    results += appeared_before[j];
                }
            }
        }
        cout << results << endl;
    }
    return 0;
}

