/*
 * Problem Link https://www.codewars.com/kata/5254ca2719453dcc0b00027d
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


unordered_set<string> possible;

void permute(string a, int l, int r)
{
    if (l == r) {
        possible.insert(a);
    }
    else {
        for (int i = l; i <= r; ++i) {
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}

vector<string> permutations(string s) {
    permute(s, 0, s.size()-1);
    vector<string> result;
    result.insert(result.end(), possible.begin(), possible.end());
    return result;
}

int main()
{
    string input;
    cin >> input;
    vector<string> test = permutations(input);
    for (auto &i : test) {
        cout << i << endl;
    }
}
