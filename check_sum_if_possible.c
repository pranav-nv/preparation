/*
		Possible To Achieve Target Sum?

		Problem Statement:
		Given an array arr of size n and a target sum k. 
		You have to determine, whether there exists a group of numbers (numbers need not to be contiguous and group can not be empty) in arr such that their sum equals to k.

		Input Format:
		There are two argument. First one is arr and second one is k.

		Output Format:
		Return a boolean denoting your answer.  

		Constraints:
		1 <= n <= 18
		-10^17 <= arr[i], k <= 10^17

		Sample Test Cases:

		Sample Input 1:
		arr = [2 4 8]
		k = 6

		Sample Output 1:
		True

		Explanation 1:
		arr[0] + arr[1] = 6

		Sample Input 2:
		arr = [2 4 6]
		k = 5

		Sample Output 2:
		False

		Explanation 2:
		There does not exists any group such that its sum equals to k.
*/



#include "stdio.h"

typedef int bool;
#define TRUE  1
#define FALSE 0

bool check_if_sum_possible_help(int arr_size, long long int* arr, long long int k, int index, int sum_so_far, bool *done ) 
{
    printf("arr_size = %d k = %d, index = %d, sum_so_far = %d, done = %d\n",(int)arr_size,(int)k,index,(int)sum_so_far,(int)*done);
    
    if (index >= arr_size) {
		//CHECK HERE
        return 0;
    }
    check_if_sum_possible_help(arr_size,arr,k,index+1,sum_so_far,done); 
    sum_so_far += arr[index];
    
	if (sum_so_far == k) {
		*done=1;
        return 1;	//Because the Problem Statement expects the function just to identify if there is atleast one subset which meets the criteria, we can exit from here
					//and from all the subsequent calls.
					// if the ask was to find out all the possible combinations, then we would have checked the condition at the leaf 'CHECK HERE'. In that case '*done' 
					//would not be necessary.
					//check subset_sum_gt.c
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
