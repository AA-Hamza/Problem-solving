/*
 *
 */
#include <iostream>
#include <vector>
#include <array>

using namespace std;

unsigned long long countChange(const unsigned int N, const vector<unsigned int>& Coins) {
    long *ways = new long[N+1];  
    ways[0] = 1;  
    for (unsigned int i = 0; i < Coins.size(); i++) { 
        for (unsigned int j = 0; j < N+1; j++) {  
            if (Coins[i] <= j) { 
                ways[j] += ways[(j - Coins[i])];  
            } 
        } 
    } 
    return ways[N];  
} 

int main() {
    cout << countChange(12, {1, 5, 10}) << endl;
    cout << countChange(4, {1,2}) << endl;
    cout << countChange(10, {5,2,3}) << endl;
    cout << countChange(11, {5,7}) << endl;
}
