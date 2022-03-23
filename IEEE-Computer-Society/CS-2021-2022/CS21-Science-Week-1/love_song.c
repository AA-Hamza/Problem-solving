/*
 * Problem Link http://codeforces.com/problemset/problem/1539/B
 * Time complexity O(my god)
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d %d ", &n, &q);
    int *song = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        char in;
        scanf("%c ", &in);
        song[i] = (int)(in-'a')+1;
    }
    unsigned long long *prefix = malloc(sizeof(unsigned long long)*(n+1));
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + song[i-1];
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%llu\n", prefix[r]-prefix[l-1]);
    }
}
