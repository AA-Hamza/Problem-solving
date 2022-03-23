/*
 * Problem Link http://codeforces.com/problemset/problem/1550/B
 */
#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        char curr = 0;
        char prev = '!';
        int count = 1;
        int score1 = a*n;      // if b > 0
        int score2 = a*n;       // if b < 0
        int count_zeros = 0;
        int count_ones = 0;

        for (int i = 0; i < n; ++i) {
            scanf(" %c", &curr);
            if (curr == prev) {
                count++;
            }
            else {
                if (curr == '0') {
                    count_zeros++;
                }
                else {
                    count_ones++;
                }
                if (prev != '!') {
                    score1 += MAX(b, count*b);
                    count = 1;
                }
            }
            prev = curr;
        }
        score1 += MAX(b, count*b);
        score2 += b*(MIN(count_zeros, count_ones)+1);
        printf("%d\n", MAX(score1, score2));
    }
}
