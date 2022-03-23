/*
 * Problem Link http://codeforces.com/contest/263/problem/A
 * Time complexity O(1)
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for (i = 0; i < 25; ++i) {
        int in;
        scanf("%d ", &in);
        if (in == 1)
            break;
    }
    int moves = 0;
    if (i < 10)
        i += (i > 4) ? (moves++, 5) : (moves+=2, 10);
    else if (i > 14)
        i -= (i > 19) ? (moves+=2, 10) : (moves++, 5);

    moves += abs(i-12);
    printf("%d\n", moves);
    return 0;
}
