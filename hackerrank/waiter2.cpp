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
    for (int i = 2; i <= sieve_max; ++i) {
        sieve[i] = 0;
    }

    int *primes = new int[max];
    int curr_prime = 0;
    for (int i = 2; i <= sieve_max; ++i) {
        if (sieve[i] == 0) {
            for (int j = i; j <= sieve_max; j += i) {
                sieve[j] = 1;
            }
            if (curr_prime < max)
                primes[curr_prime++] = i;
            else
                break;
        }
    }
    delete[] sieve;
    return primes;
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> A;
    vector<int> Bes[q];

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    int *primes = build_primes(q);
    for (int i = 0; i < 15; ++i) {
        cout << primes[i] << endl;
    }

    for (int i = 0; i <= q; ++i) {
        if (i % 2 == 0) {
			for (int j = A.size()-1; j >= 0; --j) {
                if (primes[i] > 0 && A[j] % primes[i] == 0) {
                    Bes[i].push_back(A[j]);
                    A.erase(A.begin()+j);
                }
			}
            /*
            for (auto it = A.rbegin(); it != A.rend(); ++it) {
                if (primes[i] > 0 && *it % primes[i] == 0) {
                    Bes[i].push_back(*it);
                    A.erase((it+1).base());
                }
            }
            */
        }
        else {
			for (int j = 0; j < A.size(); ++j) {
                if (primes[i] > 0 && A[j] % primes[i] == 0) {
                    Bes[i].push_back(A[j]);
                    A.erase(A.begin()+j);
                    j--;
                }
			}
            /*
            for (auto it = A.begin(); it != A.end(); ++it) {
                cout << "iterator: " << *it << endl;
                if (primes[i] > 0 && *it % primes[i] == 0) {
                    Bes[i].push_back(*it);
                    cout << "iterator: " << *it << endl;
                    A.erase(it);
                }
            }
            */
        }
    }

    for (int i = 0; i < q; ++i) {
        for (int j = Bes[i].size()-1; j >= 0; --j) {
            cout << Bes[i][j] << endl;
        }
    }
    
    /*
    cout << "vector ";
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    */

    if (q % 2 == 0) {
        for (int j = A.size()-1; j >= 0; --j) {
            cout << A[j] << endl;
        }
    }
    else {
        for (int j = 0; j<A.size(); ++j) {
            cout << A[j] << endl;
        }
	}
}
