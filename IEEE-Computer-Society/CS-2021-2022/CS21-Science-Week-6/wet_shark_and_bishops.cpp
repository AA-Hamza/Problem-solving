/*
 *  Problem Link https://codeforces.com/contest/621/problem/B
 *
*/
#include <iostream>
#include <vector>

using namespace std;

long combinations(int n, int k) {
    //cout << "combinations " << n << " " << k << endl;
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    long result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

long run_positive_diagonal(int **board, int max_length) {
    long ans = 0;
    int r = 0, c = 0;
    while (c < max_length) {
        int num_of_bishops = 0;
        int curr_c = c;
        int curr_r = r;
        for (; curr_c >= 0;) {
            if (board[curr_r][curr_c]) {
                //cout << "Found at " << curr_r << " " << curr_c << endl;
                num_of_bishops++;
            }
            curr_c -= 1;
            curr_r += 1;
        }
        if (num_of_bishops)
            ans += combinations(num_of_bishops, 2);
        c += 1;
    }
    c -= 1;
    r += 1;
    //cout << c << r << " " << ans << endl;;;
    while (r < max_length) {
        int num_of_bishops = 0;
        int curr_c = c;
        int curr_r = r;
        for (; curr_r < max_length;) {
            if (board[curr_r][curr_c]) {
                //cout << "Found at " << curr_r << " " << curr_c << endl;
                num_of_bishops++;
            }
            curr_c -= 1;
            curr_r += 1;
        }
        if (num_of_bishops)
            ans += combinations(num_of_bishops, 2);
        r += 1;
    }
    return ans;
}

long run_negative_diagonal(int **board, int max_length) {
    long ans = 0;
    int r = max_length-1, c = 0;
    while (r >= 0) {
        int num_of_bishops = 0;
        int curr_c = c;
        int curr_r = r;
        for (; curr_r < max_length; ) {
            if (board[curr_r][curr_c]) {
                //cout << "Found at " << curr_r << " " << curr_c << endl;
                num_of_bishops++;
            }
            curr_c += 1;
            curr_r += 1;
        }
        if (num_of_bishops)
            ans += combinations(num_of_bishops, 2);
        r -= 1;
    }
    r = 0;
    c = 1;
    while (c < max_length) {
        int num_of_bishops = 0;
        int curr_c = c;
        int curr_r = r;
        for (; curr_c < max_length; ) {
            if (board[curr_r][curr_c]) {
                //cout << "Found at " << curr_r << " " << curr_c << endl;
                num_of_bishops++;
            }
            curr_c += 1;
            curr_r += 1;
        }
        if (num_of_bishops)
            ans += combinations(num_of_bishops, 2);
        c += 1;
    }
    return ans;
}

int main()
{
    vector<pair<int, int>> bishops;
    int n;
    cin >> n;

    int max_length = 0;

    while (n--) {
        int r, c;
        cin >> r >> c;
        bishops.push_back(make_pair(r-1, c-1));
        max_length = max(max_length, max(r, c));
    }

    int **board = new int*[max_length];
    for (int i = 0; i < max_length; ++i) {
        board[i] = new int[max_length]();
    }

    for (auto &bishop : bishops) {
        board[bishop.first][bishop.second] = 1;
    }
    
    long ans = 0;
    ans += run_positive_diagonal(board, max_length);
    ans += run_negative_diagonal(board, max_length);
    cout << ans << endl;
}
