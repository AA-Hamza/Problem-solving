/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/longest-palindromic-substring/submissions/
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

string longestPalindrome(string s) {
    int index = 0;
    int max_size = 0;
    for (int i = 0; i < s.size(); ++i) {
        int size = 0;
        int l = i;
        int r = i;
        while (1) {
            if (l < 0 || r >= s.size())
                break;
            if (s[l] == s[r]) {
                //size++;
                size = r-l;
            }
            else {
                break;
            }
            r++;
            l--;
        }
        if (size > max_size) {
            index = l+1;
            max_size = size;
        }

        size = 0;
        l = i;
        r = i+1;
        while (1) {
            if (l < 0 || r >= s.size())
                break;
            if (s[l] == s[r]) {
                size = r-l;
            }
            else {
                break;
            }
            r++;
            l--;
        }
        if (size > max_size) {
            index = l+1;
            max_size = size;
        }
    }
    
    //cout << index << ": " << max_size+1 << endl;
    return s.substr(index, max_size+1);
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}

