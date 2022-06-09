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

        size_t results = 0;
        set<pair<int, int>> cache;
        //map<int, int> cache;
        for (int i = 0; i < a.size()-k; ++i) {
            char start = a[i];
            char end = a[i+k];
            //if (cache.find(a.substr(i, k+1)) == cache.end()) {
                int j = 0;
                while (j < b.size()) {
                    if (b[j] == start) { // 
                        int s = j;
                        while (s < b.size()) {
                            if (b[s] == end) {
                                if (cache.find(make_pair(j, s)) == cache.end()) {
                                    results++;
                                    cache.insert(make_pair(j, s));
                                }
                            }
                            s++;
                        }
                    }
                    j++;
                }
            //}
        }
        cout << results << endl;
    }
    return 0;
}

