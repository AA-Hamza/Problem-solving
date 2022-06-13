/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/missing-number/
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size() * (nums.size()+1)/2;
        for (int i = 0; i < nums.size(); ++i) {
            result -= nums[i];
        }
        return result; 
    }
};


