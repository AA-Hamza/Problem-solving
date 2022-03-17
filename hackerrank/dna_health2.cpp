/*
 * Problem Link https://www.hackerrank.com/challenges/determining-dna-health/problem
 * Time Compleixty O()
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

using namespace std; 


int main()
{
    int n;
    ios_base::sync_with_stdio(false); 
    cin >> n;

    string *genes = new string[n];
    int *health = new int[n];

    int maxiumim_length_of_gene = 0;
    for (int i = 0; i < n; ++i) {
        cin >> genes[i];
        if (genes[i].size() > maxiumim_length_of_gene)
            maxiumim_length_of_gene = genes[i].size();
    }

    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }

    unordered_map<string, map<int, int>> table;
    for (int i = 0; i < n; ++i) {
        table[genes[i]][i] = health[i];
    }

    /*
    for (auto it = table.begin(); it != table.end(); ++it) {
        cout << it->first << " ";
        for (auto g : it->second) {
            printf("(%d, %d) ", g.first, g.second);
        }
        cout << endl;
    }
    */

    int s;
    cin >> s;

    unsigned long long max_health = 0, min_health = -1;
    int start, end;
    string strand;
    while (s--) {
        cin >> start >> end >> strand;

        unsigned long long curr_gene_health = 0;
        for (int i = 0; i < strand.size(); ++i) {
            for (int j = 1; j <= maxiumim_length_of_gene; ++j) {
                if (i+j > strand.size())
                    break;
                //cout << strand.substr(i, j) << endl;
                auto search = table.find(strand.substr(i, j));
                if (search != table.end()) {
                    auto it = (search->second).lower_bound(start);
                    while (it != (search->second).end()) {
                        if (it->first > end)
                            break;
                        curr_gene_health += it->second;
                        ++it;
                    }
                    /*
                    for (const auto &g : *search) {
                        if (g.first >= start) {
                            //cout << "strand: " << strand << " string: " << strand.substr(i, j) << "  (" << g.first << ", " << g.second << ")" << endl;
                            if (g.first <= end)
                                curr_gene_health += g.second;
                            else 
                                break;
                        }
                    }
                    */
                }
            }
        }
        if (curr_gene_health > max_health) {
            max_health = curr_gene_health;
        }
        
        if (curr_gene_health < min_health) {
            min_health = curr_gene_health;
        }
    }
    if (min_health == -1) {
        cout << "0 " << max_health << endl;
    }
    else
        cout << min_health << " " << max_health << endl;
}
