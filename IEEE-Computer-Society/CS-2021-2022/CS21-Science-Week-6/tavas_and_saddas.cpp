/*
 * Problem Link https://codeforces.com/contest/535/problem/B
 *
*/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> lucky_numbers;

void generate(int layers, string curr)
{
    if (layers == 0) {
        lucky_numbers.push_back(stoi(curr));
        return;
    }
    generate(layers-1, curr+'4');
    generate(layers-1, curr+'7');
}

int main()
{
    int n;
    cin >> n;
    string n_str = to_string(n);
    int prev = n_str.length();
    prev = ((int)pow(2, prev))-2;
    generate(n_str.length(), "");

    auto location = lower_bound(lucky_numbers.begin(), lucky_numbers.end(), n);
    cout << location-lucky_numbers.begin()+1+prev << endl;

}
