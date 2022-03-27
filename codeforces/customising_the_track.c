/*
 * https://codeforces.com/problemset/problem/1543/B
 */
#include <stdio.h>

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int n;
        scanf("%d\n", &n);
        int sum = 0;
        int temp;
        for (int i = 0; i < n; ++i) {
            scanf("%d ", &temp);
            sum += temp;
        }
        int l1 = (sum%n);
        int l2 = n-l1;
        printf("%d\n", l1*l2);
    }
}
