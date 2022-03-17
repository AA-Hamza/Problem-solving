/*
 * https://www.hackerrank.com/challenges/larrys-array/problem
 */
#include <iostream>
#include <vector>

using namespace std;

void shift_3(vector<int> &arr, int middle) {
    //cout << "woah edges pro" << endl;
    if (middle == arr.size()-1) {     //aka last element
        int tmp = arr[middle];
        arr[middle] = arr[middle-2];
        arr[middle-2] = arr[middle-1];
        arr[middle-1] = tmp;
    }
    else if (middle == 0) {           //aka first element
        int tmp = arr[middle];
        arr[middle] = arr[middle+1];
        arr[middle+1] = arr[middle+2];
        arr[middle+2] = tmp;
    }
    else {
        int tmp = arr[middle];
        arr[middle] = arr[middle+1];
        arr[middle+1] = arr[middle-1];
        arr[middle-1] = tmp;
    }
}

int swap(vector<int> &arr, int should_be_here, int where_it_is)
{
    int gap = where_it_is-should_be_here;
    if (gap < 0) {
        return 0;
    }
    while (gap) {
        shift_3(arr, should_be_here+gap);
        gap--;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;

    vector<int> cases[t];
    for (int i = 0; i < t; ++i) {
        int n = 0;
        cin >> n;
        cases[i].reserve(n);
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            cases[i].push_back(tmp);
        }
    }

    for (int i = 0; i < t; ++i) {
        vector<int> &arr = cases[i];
        //Handling edge cases starting by 1
        for (int j = 0; arr[j] != 1; ++j) {

        }

        int flag = 0;
        for (int j = 1; j < arr.size()+1; ++j) {
            for (int k = 0; k < arr.size(); ++k) {
                if (arr[k] == j && (k+1) != j) {
                    //cout << "woah" << endl;
                    if (swap(arr, j-1, k) == 0) {
                        cout << "NO" << endl;
                        j = arr.size()+1;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (!flag) {
            cout << "YES" << endl;
        }

        //for (int j = 0; j < arr.size(); ++j) {
        //    cout << arr[j] << " ";
        //}
        cout << endl;
    }
}
