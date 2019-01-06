#include <vector>
#include <iostream>
#include <string>
#include "string.h"
#include "stdlib.h"
#include <cmath>

using namespace std;

#if 1

bool
check_game(vector <int> int_output)
{
#if 0
    unsigned long long int check_bits = 0;
    for (auto i_v : int_output) {
        if (check_bits & (1<< i_v)) {
            return false;
        }
        check_bits |= 1<< i_v;
    }
#endif
    for (unsigned int i_v = 0 ; i_v < int_output.size(); i_v++) {
        for (unsigned int j_v = 0; j_v < i_v ; j_v++) {
            if (abs(int_output[i_v] - int_output[j_v])== abs(i_v - j_v)) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(vector<int> &int_output, int row, int col)
{
    int i, j;
#if 0
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
#endif

    j = 1;
    /* Check upper diagonal on left side */
    for (i=row-1; i>=0; i--) {
        if (int_output[i]-j == col) {
            return false;
        }
        j++;
    }

    j = 1;
    /* Check upper diagonal on right side */
    for (i=row-1; i >= 0 ; i--) {
        if (int_output[i]+j == col) {
            return false;
        }
        j++;
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
                              int n,
                              unsigned long long int &check_bits)
{
    int i;
    int col = 0;

    if (row >= n) {
        return;
    }

    for (i= col; i<n; i++) {
        if (check_bits & (1<< i) || !isSafe(int_output,row,i)) {
            continue;
        }
        check_bits |= 1<< i;

        memset(arr, '-', n);
        arr[i] = 'q';
        cur_output[row] = string(arr);
        int_output[row] = i;

        find_all_arrangements_worker(output, cur_output, int_output, arr, row+1, n, check_bits);
        check_bits &= ~(1<< i);
        if (row == n-1) {
            if (check_game(int_output)) {
                output.push_back(cur_output);
            }
        }
    }
}


vector<vector<string> > find_all_arrangements(int n)
{
    vector < vector<string> > output;
    vector<string> cur_output(n);
    vector<int> int_output(n);
    char *arr = new char[n+1];
    int row = 0;
    unsigned long long int check_bits = 0;
    find_all_arrangements_worker(output, cur_output, int_output, arr, row, n, check_bits);

    return output;
}

#endif
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
