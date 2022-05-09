#include <iostream>
#include <vector>

using namespace std;

vector<long long> store;

void generateStore(void)
{
    vector<long long> byLength[20];
    byLength[0].push_back(0);
    for(int i= 1; i<= 10; ++i)
    {
        for(int j=0; j < byLength[i-1].size(); ++j)
        {
            long long tmp;
            tmp = byLength[i-1][j];
            byLength[i].push_back(tmp*10+4);
            byLength[i].push_back(tmp*10+7);
            store.push_back(tmp*10+4); 
            store.push_back(tmp*10+7);
        }
    }
}

int main()
{
    generateStore();
    long long lower, upper,prev,next, pos, result;
    while(cin >> lower >> upper) {
        result = 0;
        prev = lower;
        while(prev <= upper)
        {
            // Get the first position of a suitable lucky Number
            pos = lower_bound(store.begin(), store.end(), prev)-store.begin();
            next = store[pos];
            int classNumbers = min(upper, next)-prev+1;
            result += classNumbers*next;
            prev = next+1;
        }
        cout << result << endl;
    }
    return 0;
}
