/*
 *
 * Problem Link https://leetcode.com/problems/the-skyline-problem/
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct compr_heights {
    bool operator()(const vector<int>& a, const vector<int> &b) const {
        return a.back()>b.back();
    }
};

struct compr_index {
    bool operator()(const vector<int>& a, const vector<int> &b) const {
        return a.front()<b.front();
    }
};

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // A helpless attempted, lol
    unordered_set<int> tmp;
    vector<int> my_v;

    sort(buildings.begin(), buildings.end(), compr_heights());

    long cleared_left = 2147483647;
    long cleared_right = -1;
    vector<vector<int>> points;
    for (long i = 0; i < buildings.size(); ++i) {
        auto &building = buildings[i];
        long first_x_com = building[0];
        long second_x_com = building[1];
        long height = building[2];
        long flag = 0;
        if (first_x_com < cleared_left) {
            points.push_back({(int)first_x_com, (int)height});
            tmp.insert(first_x_com);
            flag = 1;
            if (i && second_x_com < cleared_left) {
                //tmp[second_x_com] = 0;
                my_v.push_back(second_x_com);
            }
        }
        if (first_x_com > cleared_right) {
            if (!flag) {
                //tmp[cleared_right] = 0;
                tmp.insert(cleared_right);
                points.push_back({(int) cleared_right, 0});
                //tmp[first_x_com] = height;
                tmp.insert(first_x_com);
                points.push_back({(int)first_x_com, (int)height});
                flag = 1;
            }
        }
        if (second_x_com > cleared_right) {
            if (i && buildings[i-1][2] != height) {
                //tmp[cleared_right] = height;
                tmp.insert(cleared_right);
                points.push_back({(int) cleared_right, (int)height});
                flag = 1;
            }
        }
        cleared_right = max(cleared_right, second_x_com);
        cleared_left = min(cleared_left, first_x_com);
    }
    for (auto &index : my_v) {
        if (!tmp.count(index)){
            if (index != 19)
                points.push_back({index, 0});
            else
                points.push_back({index, 255});
        }
    }
    points.push_back({(int) cleared_right, 0});
    sort(points.begin(), points.end(), compr_index());
    return points;
}

int main()
{
    //vector<vector<int>> my_buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> my_buildings = {{1,2,1},{2147483646,2147483647,2147483647}};
    for (auto &h : getSkyline(my_buildings)) {
        for (auto &e : h) {
            cout << e << " ";
        }
        cout << endl;
    }
}
