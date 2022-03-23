/*
 * Problem Link http://codeforces.com/contest/102/problem/B
 * Time complexity O(ln(n))
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *n;
    n = calloc(100002, sizeof(char));
    
    scanf("%s", n);
    unsigned long long sum = 0;
    for (int i = 0; n[i] != 0; ++i) {
        sum += (unsigned long long)(n[i]-'0');
    }

    if (strlen(n) < 2) {
        printf("0\n");
        return 0;
    }

    int steps = 1;
    while (sum > 9) {
        int new = 0;
        int tmp = sum;      //not really needed but to clear some confusion
        while (tmp != 0) {
            int digit = tmp % 10;
            tmp /= 10;
            new += digit;
        }
        sum = new;
        steps++;
    }
    printf("%d\n", steps);
}
