/*
 * Problem Link https://codeforces.com/contest/1593/problem/D1
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
int findGCD(vector<int> arr)
{
    int n = arr.size();
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}


int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        set<int> my_set;
        while (n--) {
            int e;
            cin >> e;
            my_set.insert(e);
        }

        if (my_set.size() < 2) {
            cout << -1 << endl;
            continue;
        }
        vector<int> gaps;
        auto begining = my_set.begin();
        auto it = my_set.begin();
        it++;
        while (it != my_set.end()) {
            gaps.push_back(*it-*begining);
            it++;
        }

        cout << findGCD(gaps) << endl;;
    }
}
