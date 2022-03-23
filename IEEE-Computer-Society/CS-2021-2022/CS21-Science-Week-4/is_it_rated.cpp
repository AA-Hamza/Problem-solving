/*
 *  Problem Link https://www.codeforces.com/contest/807/problem/A
 *
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> participants;
    int rated = 0;
    for (int i = 0; i < n; ++i) {
        int before, after;
        cin >> before >> after;
        if (before != after) {
            rated = 1;
            break;
        }
        participants.push_back(after);
    }
    if (rated) {
        cout << "rated" << endl;
    }
    else {
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            if (prev != -1 && participants[i] > prev) {
                cout << "unrated" << endl;
                prev = -2;
                break;
            }
            prev = participants[i];
        }
        if (prev != -2) {
            cout << "maybe" << endl;
        }
    }
}
