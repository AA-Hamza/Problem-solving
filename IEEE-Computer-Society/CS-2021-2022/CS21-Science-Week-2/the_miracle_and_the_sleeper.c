/*
 * Problem Link http://codeforces.com/problemset/problem/1562/A
 * Time complexity O(1)
 */
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int t;
    scanf("%d", &t);

    while (t--) {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        long long case1 = 0, case2 = 0;
        if (((r+1) / 2) >= l)  {
            if (r % 2 == 0)
                case1 = r - ((r+1)/2)-1;
            else 
                case1 = r - ((r+1)/2);
        }
        case2 = r % l;

        printf("%lld\n", MAX(case1, case2));
    }
}
