/*
 * https://codeforces.com/contest/6/problem/B
 * I wish I have read the problem before trying to implement
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    char c;
    scanf("%d %d %c\n", &n, &m, &c);

    char **buff = malloc(sizeof(char *) * n);
    int president_desk_x = -1, president_desk_y = -1;
    for (int i = 0; i < n; ++i) {
        buff[i] = malloc(sizeof(char) * m);
        for (int j = 0; j < m; ++j) {
            buff[i][j] = getchar();
            if (buff[i][j] == '\n')
                buff[i][j] = getchar();
            if (buff[i][j] == c && president_desk_x == -1) {
                president_desk_x = i;
                president_desk_y = j;
            }
        }
    }

    int adj_desks = 0;

    // X axis
    int temp = president_desk_x;
    int temp2 = president_desk_y;
    while (president_desk_y < m && buff[president_desk_x][president_desk_y] == c) {
        char last_right = -1;
        char last_left = -1;
        while (president_desk_x < n && buff[president_desk_x][president_desk_y] == c) {
            //left direction
            if (president_desk_y > 0 && buff[president_desk_x][president_desk_y-1] != c) {
                if (buff[president_desk_x][president_desk_y-1] != '.' && buff[president_desk_x][president_desk_y-1] != last_left) {
                    adj_desks++;
                    last_left = buff[president_desk_x][president_desk_y-1];
                }
            }

            //right direction
            if (president_desk_y < m-1 && buff[president_desk_x][president_desk_y+1] != c) {
                if (buff[president_desk_x][president_desk_y+1] != '.' && buff[president_desk_x][president_desk_y+1] != last_right) {
                    adj_desks++;
                    last_right = buff[president_desk_x][president_desk_y+1];
                }
            }
            president_desk_x++;
        }
        president_desk_x = temp;
        president_desk_y++;
    }
    president_desk_y = temp2;

    // Y axis
    temp = president_desk_y;
    temp2 = president_desk_x;
    while (president_desk_x < n && buff[president_desk_x][president_desk_y] == c) {
        char last_up = -1;
        char last_down = -1;
        while (president_desk_y < m && buff[president_desk_x][president_desk_y] == c) {
            //up direction
            if (president_desk_x > 0 && buff[president_desk_x-1][president_desk_y] != c) {
                if (buff[president_desk_x-1][president_desk_y] != '.' && buff[president_desk_x-1][president_desk_y] != last_up) {
                    adj_desks++;
                    last_up = buff[president_desk_x-1][president_desk_y];
                }
            }

            //down direction
            if (president_desk_x < n-1 && buff[president_desk_x+1][president_desk_y] != c) {
                if (buff[president_desk_x+1][president_desk_y] != '.' && buff[president_desk_x+1][president_desk_y] != last_down) {
                    adj_desks++;
                    last_down = buff[president_desk_x+1][president_desk_y];
                }
            }
            president_desk_y++;
        }
        president_desk_y = temp;
        president_desk_x++; 
    }
    president_desk_x = temp2; //not really needed

    printf("%d\n", adj_desks);
}
