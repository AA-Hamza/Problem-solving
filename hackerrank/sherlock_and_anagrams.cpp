#include <iostream>
#include <string>
#include <cmath>

/*
 * Problem link https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
 * I am using what is known as smartass implementation
*/

using namespace std;

/*  READY FOR SOME SHITTY BRUTE FORCE   */
int main()
{
    int n;
    cin >> n;
    string arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int t = 0; t < n; ++t) {
        int result = 0;
        for (int s = 1; s < arr[t].size(); ++s) {
            for (int i = 0; i < arr[t].size()-s; ++i) {
                int s1 = 0;
                for (int test = 0; test < s; ++test) {
                    s1 += arr[t][i+test]*arr[t][i+test]*arr[t][i+test]*arr[t][i+test];
                }
                for (int j = i+1; j < arr[t].size()-s+1; ++j) {
                    int s2 = 0;
                    for (int test = 0; test < s; ++test) {
                        s2 += arr[t][j+test]*arr[t][j+test]*arr[t][j+test]*arr[t][j+test];
                    }
                    if (s2 == s1) {
                        result++;
                    }
                }
            }
        }
        cout << result << endl;
    }

