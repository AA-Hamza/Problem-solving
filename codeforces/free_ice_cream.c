/*
 * http://codeforces.com/contest/686/problem/A
*/
#include <stdio.h>

int main()
{
    long long n, x;
    scanf("%lld %lld\n", &n, &x);
    long long d;
    char buff[80];
    int distressed_childs = 0;
    for (int i = 0; i < n; ++i) {
        fgets(buff, 80, stdin);
        if (sscanf(buff, "+ %lld\n", &d)) {
            x += d;
        }
        else if (sscanf(buff, "- %lld\n", &d)) {
            if (x-d >= 0) {
                x -= d;
            }
            else {
                distressed_childs++;
            }
        }
        else {
            break;
        }
    }
    printf("%lld %d\n", x, distressed_childs);
}
