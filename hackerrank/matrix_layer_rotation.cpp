/*
 * https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
 */
#include <iostream>
#include <vector>

using namespace std;

void shift(vector<int> &arr, int n) {
    n = n % arr.size();
    while (n--) {
        int tmp = arr[0];
        for (int i = 0; i < arr.size()-1; ++i) {
            arr[i] = arr[i + 1];
        }
        arr[arr.size()-1] = tmp;
    }
}

void read_ring(int m, int n, int **matrix, vector<int> &array, const int &layer) {
    const int gap_between_rows = m-2*layer;             // This includes intended line
    const int gap_between_cols = n-2*layer;             // This includes intended line


    int curr_row = layer;
    int curr_col = layer;
    cout << "Reading " << layer << " " << "Ring" << endl;
    cout << curr_row << "   " << curr_col << endl;
    //Part one
    for (int c = curr_col; c < (layer+gap_between_cols); ++c) {
        cout << "reading value " << matrix[curr_row][c] << endl;
        array.push_back(matrix[curr_row][c]);
        curr_col = c;
    }

    //Part two
    for (int r = curr_row+1; r < (layer+gap_between_rows-1); ++r) {
        cout << "reading value " << matrix[r][curr_col] << endl;
        array.push_back(matrix[r][curr_col]);
        curr_row = r;
    }

    curr_row++;
    //Part three
    for (int c = curr_col; c >= layer; --c) {
        cout << "reading value " << matrix[curr_row][c] << endl;
        array.push_back(matrix[curr_row][c]);
        curr_col = c;
    }

    //Part four
    for (int r = curr_row-1; r > layer; --r) {
        cout << "reading value " << matrix[r][curr_col] << endl;
        array.push_back(matrix[r][curr_col]);
        curr_row = r;
    }
    return;
}

//template <int m, int n>
int **construct_matrix(int m, int n, vector<int> *v, int size)
{
    int **new_matrix = new int*[m];
    for (int i = 0; i < m; ++i) {
        new_matrix[i] = new int[n];
    }
    for (int layer = 0; layer < size; ++layer) {
        const int gap_between_rows = m-2*layer;             // This includes intended line
        const int gap_between_cols = n-2*layer;             // This includes intended line


        int curr_row = layer;
        int curr_col = layer;
        int index = 0;
        //Part one
        for (int c = curr_col; c < (layer+gap_between_cols); ++c) {
            new_matrix[curr_row][c] = v[layer][index++];
            curr_col = c;
        }

        //Part two
        for (int r = curr_row+1; r < (layer+gap_between_rows); ++r) {
            new_matrix[r][curr_col] = v[layer][index++];
            curr_row = r;
        }

        //Part three
        for (int c = curr_col-1; c >= layer; --c) {
            new_matrix[curr_row][c] = v[layer][index++];
            curr_col = c;
        }

        //Part four
        for (int r = curr_row-1; r > layer; --r) {
            new_matrix[r][curr_col] = v[layer][index++];
            curr_row = r;
        }
    }
    return new_matrix;
}

int main()
{
    int m, n, r;        //Very bad I know
    //int m, n, r;
    cin >> m >> n >> r;

    int num_of_arrays = (min(m, n)+1)/2;        // aka # of layers 

    //int matrix[m][n];
    int **matrix = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }
    for (int row = 0; row < m; ++row) {
        for (int column = 0; column < n; ++column) {
            cin >> matrix[row][column];
        }
    }

    vector <int> layers[num_of_arrays];
    for (int i = 0; i < num_of_arrays; ++i) {
        read_ring(m,n, matrix, layers[i], i);
        shift(layers[i], r);
    }

    int **new_matrix = construct_matrix(m,n,layers, num_of_arrays);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << new_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
