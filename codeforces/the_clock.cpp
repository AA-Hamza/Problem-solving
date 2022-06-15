/* Author Ahmed Anwar
 * Problem Link https://codeforces.com/contest/1692/problem/D
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int check_palindrome(int hours, int minutes)
{
    char tmp[80];
    sprintf(tmp, "%02d:%02d", hours, minutes);
    for (int i = 0; i < 5; ++i) {
        if (tmp[i] != tmp[4-i])
            return 0;
    }
    return 1;
}

int solve(int hours, int minutes, int repeat)
{
    int curr_hours = hours, curr_minutes = minutes;
    int ans = 0;
    while (1) {
        ans += check_palindrome(curr_hours, curr_minutes);
        //cout << check_palindrome(curr_hours, curr_minutes) << endl;
        curr_minutes += repeat;
        curr_hours += curr_minutes / 60;
        curr_minutes %= 60;
        curr_hours %= 24;
        if (curr_hours == hours && curr_minutes == minutes)
            break;
        //cout << curr_hours << endl;
        //cout << curr_minutes << endl;
    }
    return ans;
}


int main()
{
    int t;// = 1;
    cin >> t;
    while (t--) {
        int hours;
        cin >> hours;
        char c;
        cin >> c;
        int minutes;
        cin >> minutes;

        int repeat;
        cin >> repeat;
        cout << solve(hours, minutes, repeat) << endl;
    }
    return 0;
}

