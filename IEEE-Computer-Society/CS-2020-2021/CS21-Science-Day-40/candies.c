/* Problem Link https://www.hackerrank.com/challenges/candies/problem
 * Time Complexity O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *children = (int *)malloc(sizeof(int) * n + 1);
    int *candies = (int *)malloc(sizeof(int) * n + 1);

    for (int i = 0; i < n; ++i) {
        scanf("%d", children+i);
        candies[i] = 1;
    }
    children[n] = INT_MAX;
    candies[n] = 1;

    if (n > 1) {
        if (candies[0] > candies[1])
            candies[0]++;
    }
    unsigned long long sum = 0;
    //printf("%d ", candies[0]);
    for (int i = 1; i < n; ++i) {
        if (children[i] > children[i-1]) {
            candies[i] = candies[i-1]+1;
        }
        /*
        if (children[i] > children[i+1] && candies[i] <= candies[i+1]) {
            candies[i]++;
            //printf("bruh\n");
        }
        */

        //printf("%d ", candies[i]);
    }

    sum = candies[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (children[i] > children[i+1]) {
            candies[i] += candies[i+1]+1;
        }
        sum += candies[i+1]
    }


    //putchar('\n');

    printf("%llu\n", sum);

}
