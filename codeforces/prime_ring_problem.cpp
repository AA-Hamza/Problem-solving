#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int primes[1000] = {0};
int visited[1000] = {0};

void generate_primes() {        // Should use seive but this is faster to implement, I think
    int flag = 0;
    int index = 0;
    int i = 2;
    while (index < 1000) {
        flag = 0;
        for (int j = 2; j < sqrt(i)+1; ++j) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            primes[index++] = i;
        i++;
    }
}

void solve(int n, int curr, int *arr) {
    if (curr == n && binary_search(primes, &primes[1000], arr[curr-1]+arr[0])) {
        for (int i = 0; i < n-1; ++i) {
            cout << arr[i] << " ";
        }
        cout << arr[n-1] << endl;
    }
    else {
        for (int i = 2; i <= n; ++i) {
            if (!visited[i] && binary_search(primes, &primes[1000], arr[curr-1]+i)) {
                visited[i] = 1;
                arr[curr] = i;
                solve(n, curr+1, arr);
                visited[i] = 0;

            }
        }
    }
}
int main()
{
    generate_primes();
    //for (int i = 0; i < 1000; ++i) {
    //    cout << primes[i] << endl;
    //}
    int n;
    int caseNo = 1;
    while (cin >> n) {
        if (caseNo != 1) {
            cout << endl;
        }
        cout << "Case " << caseNo++ << ":" << endl;
        int *arr = new int[n]();
        arr[0] = 1;
        visited[0] = 1;
        solve(n, 1, arr);
    }
}
