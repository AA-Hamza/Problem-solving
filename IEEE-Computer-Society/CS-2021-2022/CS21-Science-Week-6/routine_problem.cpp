/*
 * https://codeforces.com/contest/337/problem/B
*/

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long gcd(long a, long b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    //Fit height
    double height_ratio = (double) b / (double) d;
    
    //Fit width
    double width_ratio = (double) a / (double) c;

    if (c*height_ratio > a) {
        height_ratio = -1;
    }

    if (d*width_ratio > b) {
        width_ratio = -1;
    }

    double height_area = 0;
    double width_area = 0;
    if (height_ratio > 0) {
        height_area = height_ratio*(c+d);
    }
    if (width_ratio > 0) {
        width_area = width_ratio*(c+d);
    }

    long numerator = 0, denominator = 0;
    if (height_area > width_area) {
        numerator = d*a-c*b;
        denominator = a*d;
    }
    else {
        numerator = b*c-d*a;
        denominator = b*c;
    }
    long _gcd = gcd(numerator, denominator);
    cout << numerator/_gcd << "/" << denominator/_gcd << endl;
}
