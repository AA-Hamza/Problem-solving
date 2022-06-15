/* Author Ahmed Anwar
 * Problem Link https://leetcode.com/problems/sum-of-two-integers/
 */
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long sll;

class Solution {
public:
    int getSum(unsigned int a, unsigned int b) {
        vector<int> result(32);
        //int result = 0;
        int index = 31;
        int carry = 0;
        for (int i = 0; i < 32; ++i) {
            int a_last_bit = a % 2;
            int b_last_bit = b % 2;
            //cout << a_last_bit << " " << b_last_bit << " " << carry << endl;
            if (carry) {
                if (a_last_bit & b_last_bit) {
                    // Leave carry set to 1 and put one into result
                    result[index--] = 1;
                }
                else if (a_last_bit | b_last_bit) {
                    // Leave carry set to 1 and put zero into result
                    result[index--] = 0;
                }
                else {
                    result[index--] = 1;
                    carry = 0;
                }
            }
            else {
                if (a_last_bit & b_last_bit) {
                    // set carry to 1
                    carry = 1;
                    result[index--] = 0;
                }
                else {
                    result[index--] = a_last_bit | b_last_bit;
                }
            }
            
            a >>=1;
            b >>=1;
        }
        unsigned num_result = 0;
        for (int i = 0; i < 31; ++i) {
            num_result |= result[i];
            num_result <<= 1;
        }
        num_result |= result[31];
        return num_result;
    }
};


int main()
{
    int a, b;
    cin >> a >> b;
    Solution n;
    cout << n.getSum(a, b) << endl;
    return 0;
}

