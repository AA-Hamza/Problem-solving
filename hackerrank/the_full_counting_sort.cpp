/*
 * https://www.hackerrank.com/challenges/countingsort4/problem
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> keys[100];
    int n;
    cin >> n;

    int x;
    string s;
    int half = n/2;
    for (int i = 0; i < half; ++i) {
        cin >> x;
        cin >> s;
        keys[x].push_back("-");
    }
    for (int i = 0; i < n-half; ++i) {
        cin >> x;
        cin >> s;
        keys[x].push_back(s);
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < keys[i].size(); ++j) {
            cout << keys[i][j] << " ";
        }
    }
    cout << endl;
}
