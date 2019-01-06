#include <iostream>


int
build_bst_from_array(int array[], int len, int root_in, int left_in, int right_in)
{
    int left_count = 0;
    int right_count = 0;

    if (root_in == left_in ||
        root_in == right_in) {
        return 0;
    }
    if (right_in - left_in == 1) {
        return 2
    }

    for (int i = left_in; i < root_inWQ; i++) {
        left_count += build_bst_from_array(array,len,i, left_in, root_i -1);
    }

    for (int i = root_i + 1 ; i <= right_in ; i++) {
        right_count += build_bst_from_array(array,len,i, left_in, root_i -1);
    }

    return (left_count + right_count);
}


/*
 * Complete the function below.
 */
long long int how_many_BSTs(int n) {
    int *array = malloc(sizeof(int)*n);

    for (int i=0;i<n;i++) {
        array[i] = i;
    }

    return build_bst_from_array(array,n,0,0,n-1);
}


int
main (int argc, char *argv[])
{
    int n  = 3;
    int ret;
    ret = how_many_BSTs();
    cout << "how_many_BSTs(" << n << ") = " << ret <<  "\n";
}
