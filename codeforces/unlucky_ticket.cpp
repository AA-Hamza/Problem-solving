/*
 * https://codeforces.com/problemset/problem/160/B
 */

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>


using namespace std;

enum class State {lessThan=0, moreThan, equals};

//int isLucky(State **arr, int index, int half, State currCase, int *taken) 
//{
//    if (index == half) {
//        return 1;
//    }
//    for (int i = 0; i < half; ++i) {
//        if (taken[i])
//            continue;
//        if (arr[index][i] == currCase) {
//            taken[i] = 1;
//            //cout << "Found one in " << index << endl;
//            if (isLucky(arr, index+1, half, currCase, taken) == 1) {
//                return 1;
//            }
//            taken[i] = 0;
//        }
//    }
//    return 0;
//}


int main()
{
    int t;
    cin >> t;
    string n_str;
    cin >> n_str;

    int full = n_str.size();
    int half = full / 2;

    std::sort(n_str.begin(), n_str.begin()+half);
    std::sort(n_str.begin()+half, n_str.end());
    
    int result = 1;
    // Less than Case
    for (int i = 0; i < half; ++i) {
        if (n_str[i] >= n_str[half+i]) {
            result -= 1;
            break;
        }
    }

    result += 1;
    // More than Case
    for (int i = 0; i < half; ++i) {
        if (n_str[i] <= n_str[half+i]) {
            result -= 1;
            break;
        }
    }

    cout << ((result) ? "YES" : "NO") << endl;
}
