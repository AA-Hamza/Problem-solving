/*
 * https://www.hackerrank.com/challenges/almost-sorted/problem
 */
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n+1];
    arr[n] = 1000001;


    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int *start = NULL;
    int *end   = NULL;
    int flag = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i-1]) {
            if (flag == 0) { //beginning
                start = &arr[i-1];  //prev
                flag = 1;
            }
            end = &arr[i];
        }
        else if (flag == 1) {
            break;
        }
    }
    //cout << *start << endl;

    if (start == NULL) {
        cout << "yes" << endl;
        return 0;
    }
    int size = (int)(end-start+1);
    //cout << "size: " << size << endl;

    if (size > 2) {     //one solution (Reversing)
        int *tmp_start = start;
        int *tmp_end   = end;
        while (tmp_start < tmp_end) {
            int tmp = *tmp_end;
            *tmp_end = *tmp_start;
            *tmp_start = tmp;
            tmp_start++;
            tmp_end--;
            //cout << "indecies " << (int)(tmp_start-arr+1) << " " << (int)(tmp_end-arr+1) << endl;
        }
    }
    else {
        if (*(end+1) < *start) {    //looking for not adjacent swaps
            int *tmp = end;
            while (++end <= &arr[n]) {
                if (*end < *tmp) {      //found a swap
                    int swap = *start;
                    *start = *end;
                    *end = swap;
                    break;
                }
            }
        }
        else {
            int swap = *end;
            *end = *start;
            *start = swap;
        }
    }


    for (int i = 1; i < n; ++i) {
        //cout << arr[i] << endl;
        if (arr[i] < arr[i-1]) {
            //cout << arr[i-1] << " " << arr[i] << endl;
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
    if (size > 2) {
        cout << "reverse " << (int)(start-arr+1) << " "
             << (int)(end-arr+1) << endl;
    }
    else {
        cout << "swap " << (int)(start-arr+1) << " " 
             << (int)(end-arr+1) << endl;
    }
}
