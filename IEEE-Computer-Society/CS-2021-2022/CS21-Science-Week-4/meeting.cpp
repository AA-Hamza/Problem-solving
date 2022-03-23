/*
 * http://codeforces.com/contest/144/problem/B
 *
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int *generals;
int x1, x2, y1, y2;

int get_general_index(int x, int y) {
    if (y == y1) {
        return x-x1;
    }
    else if (x == x2) {
        return abs(x2-x1)+(y-y1);
    }
    else if (y == y2) {
        return abs(x2-x1)+abs(y2-y1)+(x2-x);
    }
    return 2*abs(x2-x1)+abs(y2-y1)+(y2-y);
}

bool in_circle(int r_x, int r_y, int r, int x, int y)
{
    return (r*r) >= (r_x-x)*(r_x-x)+(r_y-y)*(r_y-y) ? 1 : 0; 
}

void check(int r_x, int r_y, int r) {
    for (int x = x1; x < x2; ++x) {
        //point (x, y1)
        if (in_circle(r_x, r_y, r, x, y1)) {
            generals[get_general_index(x, y1)] = 1;
        }
    }
    for (int y = y1; y < y2; ++y) {
        //point(x2, y)
        if (in_circle(r_x, r_y, r, x2, y)) {
            generals[get_general_index(x2, y)] = 1;
        }
    }
    for (int x = x2; x > x1; --x) {
        //point(x, y2)
        if (in_circle(r_x, r_y, r, x, y2)) {
            generals[get_general_index(x, y2)] = 1;
        }
    }
    for (int y = y2; y > y1; --y) {
        //point(x1, y)
        if (in_circle(r_x, r_y, r, x1, y)) {
            generals[get_general_index(x1, y)] = 1;
        }
    }
}



int main()
{
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) {
        int tmp = x1;
        x1 = x2;
        x2 = tmp;
    }
    if (y1 > y2) {
        int tmp = y1;
        y1 = y2;
        y2 = tmp;
    }
    int width = abs(x1-x2);
    int length = abs(y1-y2);
    int generals_num = (width+length)*2;
    generals = new int[generals_num]();

    int n;
    cin >> n;
    while (n--) {
        int r_x, r_y, r;
        cin >> r_x >> r_y >> r;
        check(r_x, r_y, r);
    }
    int ans = 0;
    for (int i = 0; i < generals_num; ++i) {
        if (generals[i] != 1)
            ans++;
    }
    cout << ans << endl;
}
