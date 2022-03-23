/*
 * Problem link https://leetcode.com/problems/binary-watch/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string format_time(int hours, int mins)
{
    string time;
    time += to_string(hours);
    time += ":";
    if (mins < 10) {
        time += "0";
    }
    time += to_string(mins);
    return time;
}

void filler_helper(int watch[10] , vector<string> &result, int turnedOn, int start)
{
    int hours = 8*watch[0] + 4*watch[1] + 2*watch[2] + watch[3];
    int mins = 32*watch[4] + 16*watch[5] + 8*watch[6] + 4*watch[7] + 2*watch[8] + watch[9];
    if (hours > 12 || mins >= 60)
        return;
    if (turnedOn == 0) {
        if (hours || mins) {
            result.push_back(format_time(hours, mins));
        }
        return;
    }

    for (int i = start; i < 10; ++i) {
        watch[i] = 1;
        filler_helper(watch, result, turnedOn-1, i+1);
        watch[i] = 0;
    }
}

vector<string> readBinaryWatch(int turnedOn) {
    // 4 leds for hours (8, 4, 2, 1)
    // 6 leds for mintues (32, 16, 8, 4, 2, 1)
    int watch[10] = {0};
    vector<string> result;
    filler_helper(watch, result, turnedOn, 0);
    return result;
}

int main()
{
    vector<string> result = readBinaryWatch(9);
    for (auto e : result)
        cout << e << endl;
}
