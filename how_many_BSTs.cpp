#include <iostream>

using namespace std;

int
build_bst_from_array(int n, int left_in, int right_in)
{
    int count = 0;
    //printf("left_in = %d right_in = %d \n",
    //        left_in, right_in);
    if (left_in >= n ||
        right_in >= n ||
        left_in > right_in) {
        return 1;
    }else if (right_in - left_in == 1) {
        return 2;
    } else if (right_in - left_in == 0) {
        return 1;
    }

    for (int i = left_in; i <= right_in; i++) {
        int count_l, count_r;
        count_l = build_bst_from_array(n,left_in,i-1);
        count_r = build_bst_from_array(n,i+1,right_in);
        count +=  (count_l * count_r);
    }
    return (count);
}



/*
 * Complete the function below.
 */
long long int how_many_BSTs(int n) {
    return build_bst_from_array(n,0,n-1);
}


int
main (int argc, char *argv[])
{
    int n  = strtol(argv[1], NULL, 10);
    int ret;
    ret = how_many_BSTs(n);
    cout << "how_many_BSTs(" << n << ") = " << ret <<  "\n";
}
