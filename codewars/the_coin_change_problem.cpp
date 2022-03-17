/*
 * https://www.codewars.com/kata/541af676b589989aed0009e7
*/
#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <cstdlib>

using namespace std;

unsigned long long countChange(const unsigned int money, const vector<unsigned int>& coins) {
    unsigned long long *arr = (unsigned long long *)malloc(sizeof(unsigned long long) * (money+1));//new unsigned long long[money+1];
    memset(arr, 0, sizeof(unsigned long long) * (money+1));
    arr[0] = 1;

    for (auto coin: coins) {
        for (unsigned int i = 0; i <= money; ++i) {
            if (coin <= i) {
                arr[i] += arr[i-coin];
            }
        }
    }
    return arr[money];
}

int main()
{
    cout << countChange(12, {1, 5, 10}) << endl;
    cout << countChange(4, {1,2}) << endl;
    cout << countChange(10, {5,2,3}) << endl;
    cout << countChange(11, {5,7}) << endl;
}
