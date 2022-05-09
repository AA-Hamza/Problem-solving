#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(string &num, string tmp, int index) {
    if (tmp.size() > 0) {
        int test;
        sscanf(tmp.c_str(), "%d", &test);
        if (test % 8 == 0) {
            return test;
        }
        if (tmp.size() == 3) {
            return -1;
        }
    }

    int result;
    for (int i = index; i < num.size(); ++i) {
        tmp.push_back(num[i]);
        if ((result = solve(num, tmp, i+1)) != -1) {
            return result;
        }
        tmp.pop_back();
    }
    return -1;
}

int main()
{
    string number;
    cin >> number;
    string tmp;
    int result = solve(number, tmp, 0);
    if (result == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << result << endl;
    }
}
