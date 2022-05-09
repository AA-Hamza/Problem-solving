/*
 * Problem Link https://codeforces.com/problemset/problem/31/A
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> orig_forms(n);
    for (int i = 0; i < n; ++i) {
        cin >> orig_forms[i];
    }

    vector<int> forms(orig_forms);
    sort(forms.begin(), forms.end());
    reverse(forms.begin(), forms.end());

    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            // Handling weird case ¯\_(ツ)_/¯
            if (n == 3 && forms.rbegin() == forms.rend()-j-1-1) {
                if (*forms.rbegin() == forms[i]-forms[j]) {
                    auto ai = find(orig_forms.begin(), orig_forms.end(), forms[i]);
                    auto aj = find(orig_forms.begin(), orig_forms.end(), forms[j]);
                    auto ak = find(orig_forms.rbegin(), orig_forms.rend(), forms[i]-forms[j]);
                    cout << ai-orig_forms.begin()+1 << " " << aj-orig_forms.begin()+1 << " " << orig_forms.rend()-ak << endl;;
                    return 0;
                }
                else {
                    cout << -1 << endl;
                    return 0;
                }
            }
            if (binary_search(forms.rbegin(), forms.rend()-j-1-1, forms[i]-forms[j])) {
                auto ai = find(orig_forms.begin(), orig_forms.end(), forms[i]);
                auto aj = find(orig_forms.begin(), orig_forms.end(), forms[j]);
                auto ak = find(orig_forms.rbegin(), orig_forms.rend(), forms[i]-forms[j]);

                cout << ai-orig_forms.begin()+1 << " " << aj-orig_forms.begin()+1 << " " << orig_forms.rend()-ak << endl;;
                return 0;
            }
        }
    }
    cout << "-1" << endl;

    return 0;
}
