/*
    Problem Link https://www.hackerrank.com/challenges/waiter/problem
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int *build_primes(int max)
{
    //max <= 1200 "constrain"
    //I know that 1200th prime is less than a 200,000
    const int sieve_max = 200000;
    int *sieve = new int[sieve_max];
    int *primes = new int[max];
    int curr_prime = 0;
    for (int i = 2; i <= sieve_max; ++i) {
        if (sieve[i] == 0) {
            if (curr_prime < max)
                primes[curr_prime++] = i;
            else
                break;
        }
    }
    delete[] sieve;
    return primes;
}

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, q;
    cin >> n >> q;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int *primes = build_primes(q);
    int curr_iteration = 0;
    
    vector<int> Aes[q];
    vector<int> Bes[q];

    //first iteration
    for (int i = n-1; i >= 0; --i) {
        if (arr[i] % primes[curr_iteration]) {
            Aes[curr_iteration].push_back(arr[i]);
        }
        else {
            Bes[curr_iteration].push_back(arr[i]);
        }
    }
    curr_iteration++;

    for (int i = curr_iteration; i < q; ++i) {
        for (int j = Aes[i-1].size()-1; j >= 0; --j) {
            if (Aes[i-1][j] % primes[curr_iteration]) {
                Aes[curr_iteration].push_back(Aes[i-1][j]);
            }
            else {
                Bes[curr_iteration].push_back(Aes[i-1][j]);
            }
        }
        curr_iteration++;
    }

    for (int i = 0; i < q; ++i) {
        for (int j = Bes[i].size()-1; j >= 0; --j) {
            cout << Bes[i][j] << endl;
        }
    }

    //for (int i = ; i < q; ++i) {
        int i = curr_iteration-1;
        for (int j = Aes[i].size()-1; j >= 0; --j) {
            cout << Aes[i][j] << endl;
        }
    //}
}
