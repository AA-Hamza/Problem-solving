/*
 * https://codeforces.com/contest/1669/problem/F
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr   = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int *left  = new int[n]();
        int *right = new int[n]();
        int prevLeft = 0, prevRight = 0;
        for (int i = 0; i < n; ++i) {
            prevLeft += arr[i];
            prevRight += arr[n-1-i];
            left[i] = prevLeft;
            right[n-1-i] = prevRight;
        }
        map<int, int> solutions;
        int i = 0, j = n-1;
        while (i < j) {
            if (left[i] == right[j]) {
                solutions.insert({i, j});
                i++;
                j--;
            } 
            else if (left[i] < right[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        if (!solutions.empty()) {
            auto const last = *std::prev(solutions.end());
            cout << last.first+1 + n-last.second << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}
