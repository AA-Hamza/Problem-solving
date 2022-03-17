/*
 * https://www.hackerrank.com/challenges/lilys-homework/problem
*/
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}
void swap(vector<int> arr, int n1, int n2)
{
    int tmp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = tmp;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> sorted(n) = arr;
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n; ++i) {
        binarySearch(sorted, 0, n, arr[i]);
    }
}
