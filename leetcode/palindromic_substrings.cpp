/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/palindromic-substrings/
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

int get_palindromes_at(int l, int r, const std::string &str)
{
    int count = 0;
    while (1) {
        if (l < 0 || r >= str.size()) {
            break;
        }
        if (str[l] == str[r]) {
            count++;
            //cout << l << ": " << r << " --> " << str.substr(l, r-l+1) << endl;
        }
        else {
            break;
        }
        l--;
        r++;
    }
    return count;
}

int countSubstrings(string str) {
    int result = 0;
    for (int i = 0; i < str.size(); ++i) {
        // Odd substrings
        result += get_palindromes_at(i, i, str);
        // Event substrings
        result += get_palindromes_at(i, i+1, str);
    }
    return result;
}

int main()
{
    string str;
    cin >> str;
    cout << "Result = ";
    cout << countSubstrings(str) << endl;
    return 0;
}

