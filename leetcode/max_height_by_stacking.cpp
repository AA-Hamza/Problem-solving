/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

bool check_stackable(const vector<int> &base, const vector<int> &cube)
{
    if (cube[0] <= base[0] && cube[1] <= base[1] && cube[2] <= base[2]) {
        return true;
    }
    return false;
}

int maxHeight(vector<vector<int>>& cuboids) {
    for (int i = 0; i < cuboids.size(); ++i) {
        sort(cuboids[i].begin(), cuboids[i].end());
    }
    sort(cuboids.begin(), cuboids.end(), 
            [](vector<int> &a, vector<int> &b) -> bool {
                if(a[0] == b[0]){
                    if(a[1] == b[1])
                        return a[2] < b[2];
                    return a[1] < b[1];
                }
                return a[0] < b[0];
            }
    );
    vector<int> dp(cuboids.size(), -1);
    dp[0] = cuboids[0][2];
    int result = dp[0];
    for (int i = 1; i < cuboids.size(); ++i) {
        const vector<int> &base = cuboids[i];
        int max_stackable = 0;
        for (int j = 0; j < i; ++j) {
            if (check_stackable(base, cuboids[j])) {
                max_stackable = max(max_stackable, dp[j]);
            }
        }
        dp[i] = base[2] + max_stackable;
        result = max(result, dp[i]);
    }
    return result;
}

int main()
{
    //vector<vector<int>> cuboids = {{37, 53, 95},{20, 45, 50},{12, 23, 45}};
    //vector<vector<int>> cuboids = {{38,25,45},{76,35,3}};
    vector<vector<int>> cuboids = {{92,47,83},{75,20,87},{68,12,83},{12,85,15},{16,24,47},{69,65,35},{96,56,93},{89,93,11},{86,20,41},{69,77,12},{83,80,97},{90,22,36}};
    reverse(cuboids.begin(), cuboids.end());
    cout << maxHeight(cuboids) << endl;
    return 0;
}

