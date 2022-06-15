/* Author Ahmed Anwar
 * Problem Link https://codeforces.com/contest/1692/problem/H
 */
#include <bits/stdc++.h>


using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

struct max {
    int start;
    int end;
    int val;
};

struct max maxSubArraySum(vector<int> &a, int val)
{
    int start = 0, end = 0;
    int max_so_far = 0, max_ending_here = 0;
 
    struct max best;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == val) {
            max_ending_here = max_ending_here + 1;
        }
        else {
            max_ending_here = max_ending_here - 1;
        }

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            end = i;
            best.start = start;
            best.end = i;
            best.val = max_so_far;
        }
 
        if (max_ending_here < 0) {
            start = i+1;
            end = i+1;
            max_ending_here = 0;
        }
    }
    return best;
}

bool mcompare(pair<int, int>&a, pair<int, int> &b) { 
    return (bool)a.second > b.second;
};

int main()
{
    int t;// = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        //set<int> cases;
        map<int, int> cases;
        vector<int> rounds;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            rounds.push_back(tmp);
            //cases.insert(tmp);
            cases[tmp]++;
        }

        struct max best = {0, 0, 0};
        int a = 0;
        set<pair<int, int>> cases2;
        for (auto const &kv : cases) {
            cases2.emplace(kv.second, kv.first);
        }
        for (auto it = cases2.rbegin(); it != cases2.rend(); ++it) {
            if (it->first < best.val)
                break;

            //cout << "Testing " << *it << endl;
            struct max tmp = maxSubArraySum(rounds, it->second);
            //cout << "Result " << tmp.start << " " << tmp.end << " " << tmp.val << endl;;
            if (tmp.val > best.val) {
                best = tmp;
                a = it->second;
            }
        }
        cout << a << " " << best.start+1 << " " << best.end+1 << endl;
    }
    return 0;
}

