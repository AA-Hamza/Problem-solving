/*
 *  Problem link https://www.hackerrank.com/challenges/jim-and-the-skyscrapers/problem
*/

#include <iostream>
//#include <list>
#include <vector>
//#include <unistd.h>

using namespace std;
typedef long ul;


ul count_skyscrappers(ul left, ul right, ul *arr)
{
    if (right-left < 1)
        return 0;

    while (arr[left+1] > arr[left])
        left++;

    ul heighest = 0;
    ul count_appears = 0;
    vector<ul> indices;
    for (ul i = left; i <= right; ++i) {
        if (arr[i] > heighest) {
            heighest = arr[i];
            count_appears = 1;
            indices.clear();
            indices.push_back(i);
        }
        else if (arr[i] == heighest) {
            count_appears++;
            indices.push_back(i);
        }
    }

    cout << "heighest = " << heighest << endl;
    for (auto it = indices.begin(); it != indices.end(); ++it) {
        cout << '\t' << *it << endl;
    }
    //sleep(1);

    ul ways = (count_appears)*(count_appears-1);

    //adding edge cases 
    ul prev_index = left-1;
    indices.push_back(right+1);

    for (auto it = indices.begin(); it != indices.end(); ++it) {
        ways += count_skyscrappers(prev_index+1, *it-1, arr);
        prev_index = *it;
    }

    return ways;


}

int main() {
    ul n;
    cin >> n;

    ul *skyscrapers = new ul[n];
    for (ul i = 0; i < n; ++i) {
        cin >> skyscrapers[i];
    }

    cout << count_skyscrappers(0, n-1, skyscrapers) << endl;

    return 0;
    //int ways = 0;
    //for (int i = 0; i < n; ++i) {
    //    for (int j = i+1; j < n; ++j) {
    //        if (skyscrapers[j] > skyscrapers[i]) {
    //            break;
    //        }
    //        else if (skyscrapers[j] == skyscrapers[i]) {
    //            //cout << "i = " << i << " j = " << j << endl;
    //            ways++;
    //        }
    //    }
    //}
}
