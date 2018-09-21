#include "stdio.h"

typedef int bool;
#define TRUE  1
#define FALSE 0

bool check_if_sum_possible_help(int arr_size, long long int* arr, long long int k, int index, int sum_so_far, bool *done ) 
{
    printf("arr_size = %d k = %d, index = %d, sum_so_far = %d, done = %d\n",(int)arr_size,(int)k,index,(int)sum_so_far,(int)*done);
    
    if (index >= arr_size) {
        return 0;
    }
    check_if_sum_possible_help(arr_size,arr,k,index+1,sum_so_far,done); 
    sum_so_far += arr[index];
    
	if (sum_so_far == k) {
		*done=1;
        printf("done = %d\n",*done);
    }
    
    if (*done) {
        return 1;
    }
	check_if_sum_possible_help(arr_size,arr,k,index+1,sum_so_far,done);
}

bool check_if_sum_possible(int arr_size, long long int* arr, long long int k ) {
    int sum_so_far = 0; 
    int index = 0;
    bool done = 0;
    return check_if_sum_possible_help(arr_size,arr,k,index,sum_so_far,&done);
}

int main()
{
	long long int arr[] = {2, 4, 8, 20 , 20 , -28};
	int k = -1;
	bool ret = 0;
	ret = check_if_sum_possible(sizeof(arr)/sizeof(long long int),arr,k);

	printf ("ret = %d\n",ret);
}
