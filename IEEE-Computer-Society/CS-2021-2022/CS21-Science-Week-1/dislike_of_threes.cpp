/*
 * Problem Link http://codeforces.com/problemset/problem/1560/A
 * Time complexity O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

void generate_list(vector<int> &v) {
    int i = 1;
    while (v.size() < 1001) {
        v.push_back(i);
        i++;
        while (i % 3 == 0 || i % 10 == 3) {
            i++;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    //vector<int> test_cases;
    //test_cases.reserve(t);

    vector<int> list;
    list.reserve(1000);
    generate_list(list);

    while (t--) {
        int in;
        cin >> in;
        cout << list[in-1] << endl;
    }
}
