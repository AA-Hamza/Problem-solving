#include <iostream>
#include <vector>

#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zeroupper") //Enable AVX
#pragma GCC target("avx") //Enable AVX

using namespace std;

long long solutions = 0;

inline int validateBoard(vector<vector<int>> &board) 
{
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1) {
                // +
                for (int k = 0; k < n; ++k) {
                    if (k != j && board[i][k] == 1) {
                        return 0;
                    }
                    if (k != i && board[k][j] == 1) {
                        return 0;
                    }
                }

                // Diagnoal
                int k = 1;
                while (i+k < n && j+k < n) {
                    if (board[i+k][j+k] == 1)
                        return 0;
                    k++;
                }
                k = 1;
                while (i+k < n && j-k >= 0) {
                    if (board[i+k][j-k] == 1)
                        return 0;
                    k++;
                }
            }
        }
    }
    return 1;
}

void printBoard(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int col[1000] = {0};
int posDiag[1000] = {0};
int negDiag[1000] = {0};
void solve(vector<vector<int>> &board, int queenNumber, int row)
{
    int n = board.size();
    if (queenNumber == n) {
        solutions++;
        return;
    }
    for (int c = 0; c < n; ++c) {
        if (!board[row][c] && col[c] != 1 && posDiag[row+c] != 1 && negDiag[row-c+500] != 1) {
            board[row][c] = 1;
            col[c] = 1;
            posDiag[row+c] = 1;
            negDiag[(row-c)+500] = 1;
            solve(board, queenNumber+1, row+1);
            board[row][c] = 0;
            col[c] = 0;
            posDiag[row+c] = 0;
            negDiag[(row-c)+500] = 0;
        }
    }
    /*
    //for (int i = index; i < n*n; ++i) {
    int i = 0;
    while (i < n*n) {
        if (!board[i/n][i%n] && col[i%n] != 1 && posDiag[i] != 1 && negDiag[(i/n - i%n)+500] != 1) {
            board[i/n][i%n] = 1;
            col[i%n] = 1;
            posDiag[i] = 1;
            negDiag[(i/n - i%n)+500] = 1;
            //if (validateBoard(board)) {
                //printBoard(board);
                //cout << endl << endl;
                solve(board, queenNumber+1, i+(n*(i/n+1)-i));
                i += (n*(i/n+1)-i);
            //}
            board[i/n][i%n] = 0;
            col[i%n] = 0;
            posDiag[i] = 0;
            negDiag[(i/n - i%n)+500] = 0;
        }
    }
    */
}

int main()
{
    //vector<vector<int>> a = {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    //cout << validateBoard(a) << endl;;
    int caseNo = 1;
    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        vector<vector<int>> board(n);
        for (int i = 0; i < n; ++i) {
            board[i] = vector<int>(n);
        }
        for (int i = 0; i < n; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < n; ++j) {
                if (line[j] == '*')
                    board[i][j] = 2;
                else
                    board[i][j] = 0;
            }

        }
        solve(board, 0, 0);
        cout << "Case " << caseNo++ << ": " << solutions << endl;
        solutions = 0;
    }
}
