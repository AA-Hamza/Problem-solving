/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/reverse-bits/
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 31; ++i) {
            result |= n % 2;
            result = result << 1;
            n = n >> 1;
        }
        result |= n % 2;
        return result;
    }
};
