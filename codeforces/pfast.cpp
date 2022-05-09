#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int getAlong(const vector<string> &possible, const vector<pair<string, vector<string>>> hates)
{
    for (const string &person: possible) {
        int i;
        for (i = 0; i < hates.size(); ++i) {
            if (hates[i].first == person)
                break;
        }
        for (const string hated: hates[i].second) {
            if (find(possible.begin(), possible.end(), hated) != possible.end()) {
                return 0;
            }
        }
    }
    return 1;
}

int comp(pair<string, vector<string>> &a, pair<string, vector<string>> &b) {
    return a.second.size() < b.second.size();
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> possible(n);
    for (int i = 0; i < n; ++i) {
        cin >> possible[i];
    }

    vector<pair<string, vector<string>>> hates;
    for (int i = 0; i < n; ++i) {
        hates.push_back({possible[i], {}});
    }
    for (int i = 0; i < m; ++i) {
        string person1, person2;
        cin >> person1 >> person2;
        for (int j = 0; j < hates.size(); ++j) {
            if (hates[j].first == person1) {
                hates[j].second.push_back(person2);
            }
            if (hates[j].first == person2) {
                hates[j].second.push_back(person1);
            }
        }
    }

    sort(hates.begin(), hates.end(), [=](std::pair<string, vector<string>> &a, std::pair<string, vector<string>> &b) {
            return a.second.size() > b.second.size();       // Descending
    });

    for (int i = 0; i < n; ++i) {
        cout << '\t' << hates[i].first <<'\t' << hates[i].second.size()<< endl;
    }   
    cout << endl << endl;
    int index = 0;
    while (!getAlong(possible, hates)) {
        //auto head = hates.begin();
        possible.erase(find(possible.begin(), possible.end(), hates[index++].first));
        //hates.erase(hates.begin());
    }

    sort(possible.begin(), possible.end());
    cout << possible.size() << endl;
    for (int i = 0; i < possible.size(); ++i) {
        cout << possible[i] << endl;
    }
}
