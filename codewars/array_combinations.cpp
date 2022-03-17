/*
 * https://www.codewars.com/kata/59e66e48fc3c499ec5000103
*/
#include <vector>
#include <set>

int solve(const std::vector<std::vector<int>> &data)
{
    //std::vector<std::set> processed;
    //processed.reserve(data.size());

    int sum = 1;
    for (int i = 0; i < data.size(); ++i) {
        //processed[i] = set<int>(data[i].begin(), data[i].end());
        set<int> tmp (data[i].begin(), data[i].end());
        sum *= tmp.size();
    }
    return sum; // your code here
}
