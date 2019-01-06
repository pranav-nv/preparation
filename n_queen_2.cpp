#include <vector>
#include <iostream>
#include <string>
#include "string.h"
#include "stdlib.h"
#include <cmath>

using namespace std;

bool checkBoard(vector<int> &int_output, int row, int col)
{
    int i, j;

    for (i=row-1, j = 1; i>=0; i--, j++) {
        if (int_output[i]-j == col ||
            int_output[i]+j == col ||
            int_output[i] == col ) {
            return false;
        }
    }
    return true;
}

/*
 * Complete the function below.
 */
void
find_all_arrangements_worker (vector<vector<string> > &output,
                              vector<string> &cur_output,
                              vector<int> &int_output,
                              char *arr,
                              int row,
                              int n)
{
    int i;
    int col = 0;

    if (row >= n) {
        return;
    }

    for (i= col; i<n; i++) {
        if (!checkBoard(int_output,row,i)) {
            continue;
        }

        memset(arr, '-', n);
        arr[i] = 'q';
        cur_output[row] = string(arr);
        int_output[row] = i;

        find_all_arrangements_worker(output, cur_output, int_output, arr, row+1, n);

        if (row == n-1) {
            output.push_back(cur_output);
        }
    }
}


/*
 * Complete the function below.
 */
vector < vector<string> > find_all_arrangements(int n) {
    vector < vector<string> > output;
    vector<string> cur_output(n);
    vector<int> int_output(n);
    char *arr = new char[n+1];
    int row = 0;

    find_all_arrangements_worker(output, cur_output, int_output, arr, row, n);

    return output;
}

int
main (int argc, char *argv[])
{
    char *endptr;
    vector <vector<string> > a_out;
    int n = strtol(argv[1],&endptr,10);
    a_out= find_all_arrangements(n);
    for (auto i_v : a_out) {
        for (auto j_v : i_v) {
            cout << j_v << "\n";
        }
        cout << "\n";
    }
    return 0;
}

