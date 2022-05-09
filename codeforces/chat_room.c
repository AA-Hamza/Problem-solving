/*
 * https://codeforces.com/contest/58/problem/A
 */
#include <stdio.h>
 
int main()
{
    char hello[] = "hello";
    
    char buffer[101];
    scanf("%s", buffer);
    
    int current;
    int it = 0;
    for (current = 0; buffer[current] != 0; ++current){
        if (buffer[current] == hello[it])
            it++;
    }
    if (it == 5)
        puts("YES");
    else
        puts("NO");
 
}
