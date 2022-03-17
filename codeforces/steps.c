/*
 * https://codeforces.com/contest/152/problem/B
 */

#include <stdio.h>
#define min(a,b) (a) < (b) ? (a) : (b)

int check_boundries(long long n, long long m, long long x, long long y) 
{
    if ((x > n || x < 1)  || (y > m || y < 1)) {
        return 0;
    }
    return 1;
}

long long solve_inequ(long long n, long long x, long long dx)
{
    long long result = 0;
    if (dx > 0) {
        result = (n-x)/dx;
    }
    else if (dx < 0){
        dx = -dx;
        result = (x-1)/dx;
    }
    else {
        result = 10e10;
    }
    return result;
}

long long cal_steps(long long n, long long m, long long x, long long y, long long dx, long long dy)
{
    long long b1 = solve_inequ(n, x, dx);
    long long b2 = solve_inequ(m, y, dy);
    long long bottle_neck = min(b1, b2);
    return bottle_neck;
}

int main()
{
    long long n, m;
    long long x, y;
    long long k;
    scanf("%lld %lld ", &n, &m);
    scanf("%lld %lld ", &x, &y);
    scanf("%lld ", &k);

    long long steps = 0;
    long long dx, dy;
    for (int i = 0; i < k; ++i) {
        scanf("%lld %lld ", &dx, &dy);
        if (check_boundries(n, m, x+dx, y+dy)) {
            steps += cal_steps(n, m, x, y, dx, dy);
            //x += dx;
            //y += dy;
            //steps++;
            //printf("%lld %lld\n", x, y);
        }
    }
    printf("%lld\n", steps);
}
