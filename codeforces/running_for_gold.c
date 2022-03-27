/*
 * https://codeforces.com/contest/1552/problem/B
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_bruteforce(int **athletes, int index, int n) {
    for (int k = 0; k < n; ++k) {
        if (k == index)
            continue;
        int better = 0;
        for (int j = 0; j < 5; ++j) {
            if (athletes[index][j] < athletes[k][j]) {
                better++;
            }
        }
        if (better >=3) {   /* means that athletes[i] is better than athletes[k], so athletes[k] can't be the champion */
            /* Good */
        }
        else {   /* means that athletes[k] is better than athletes[i], so athletes[i] can't be the champion */
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int n;
        scanf("%d\n", &n);
        int **athletes = malloc(sizeof(int **)*n);
        for (int i = 0; i < n; ++i) {
            athletes[i] = (int *)malloc(sizeof(int)*5);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                scanf("%d ", &athletes[i][j]);
            }
        }
        if (n == 1) {
            printf("1\n");
            continue;
        }
        int superior[] = {50001, 50001, 50001, 50001, 50001};
        int superior_index = -1;
        for (int i = 0; i < n; ++i) {
            int better = 0;
            for (int j = 0; j < 5; ++j) {
                if (athletes[i][j] < superior[j]) {
                    better++;
                }
            }
            if (better > 2) {
                memcpy(superior, athletes[i], 5*sizeof(int));
                superior_index = i;
            }
        }
        if (superior_index != -1) {
            int res = check_bruteforce(athletes, superior_index, n);
            if (res) 
                printf("%d\n", -1);
            else
                printf("%d\n", superior_index+1);
        }
        else {
            printf("%d\n", -1);
        }

    }
}
