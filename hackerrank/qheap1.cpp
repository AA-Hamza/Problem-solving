/*
 * https://www.hackerrank.com/challenges/qheap1/problem
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q;
    cin >> q;
    vector<int> heap;
    while (q--) {
        int query;
        cin >> query;
        if (query == 1) {
            int val;
            cin >> val;
            heap.push_back(val);
        }
        else if (query == 2) {
            int val;
            cin >> val;
            auto it = heap.begin();
            while (it != heap.end()) {
                if (*it == val)
                    break;
                ++it;
            }
            heap.erase(it);
        }
        else {
            auto it = heap.begin();
            int min = *it;
            while (it != heap.end()) {
                if (*it < min)
                    min = *it;
                ++it;
            }
            cout << min << endl;
        }
    }
    return 0;
}

