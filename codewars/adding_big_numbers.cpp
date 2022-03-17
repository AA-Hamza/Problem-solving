/*
 * https://www.codewars.com/kata/525f4206b73515bffb000b21
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

std::string add(const std::string& a, const std::string& b) {
    int carry = 0;
    string sumation;
    int smaller = min(a.size(), b.size());

    for (int i = 0; i < smaller; ++i) {
        int digit = (int)(b.c_str()[b.size()-i-1]-'0') + (int)(a.c_str()[a.size()-i-1]-'0') + carry;
        sumation.push_back((char)digit%10+'0');
        carry = digit / 10;
    }
    const string &bigger = b.size() > a.size() ? b : a;
    for (int i = smaller; i < (int)bigger.size(); ++i) {
        int digit = (int)(bigger.c_str()[bigger.size()-i-1]-'0') + carry;
        sumation.push_back((char)digit%10+'0');
        carry = digit / 10;
    }

    if (carry != 0)
        sumation.push_back((char)carry+'0');
    reverse(sumation.begin(), sumation.end());
    return sumation;

}

int main()
{
    cout << add("123", "123") << endl;;
}
