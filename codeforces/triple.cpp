#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> occurs;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            occurs[tmp] += 1;
        }
        for (auto const &pair : occurs) {
            if (pair.second >= 3) {
                cout << pair.first << endl;
                n = -1;
                break;
            }
        }
        if (n != -1) {
            cout << -1 << endl;
        }
    }
}
