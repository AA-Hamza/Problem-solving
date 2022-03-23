/* 
 * Problem Link http://codeforces.com/contest/732/problem/A
 * Time Complexity O(n)
 */
#include <stdio.h>

int main()
{
    int price, change;
    scanf("%d %d", &price, &change);
    price = price % 10;
    int shovels = 1;
    while (1) {
        int tmp = price * shovels;
        if (tmp % 10 == change || tmp % 10 == 0)
            break;
        shovels++;
    }
    printf("%d\n", shovels);
}
