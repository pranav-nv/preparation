#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void 
printArr(int *s,int k)
{
	int i;
	for (i=0;i<k;i++) {
		fprintf(stderr,"%d ",s[i]);
	}
	fprintf(stderr,"\n");
}

void
printSubsets(int *arr,int len, int j, int *s, int k,int req_sum,int sum_so_far)
{
	if (j >=len-1) {
		if (req_sum < sum_so_far) {	
			printArr(s,k);
		}
		return;
	}
	
	printSubsets(arr,len,j+1,s,k,req_sum,sum_so_far);
	s[k] = arr[j];
	sum_so_far += s[k];
	printSubsets(arr,len,j+1,s,k+1,req_sum,sum_so_far);
}


void
printSubsetsMain(int *arr, int len,int req_sum)
{
	int sum_so_far = 0;
	int *s = malloc(sizeof(int)*len);	
	printSubsets(arr,len,0,s,0,req_sum,sum_so_far);
	free(s);
}

int 
main()
{
	int req_sum = 1;
	int arr[]={1,2,3,4};
	printSubsetsMain(arr,sizeof(arr)/sizeof(int),req_sum);
}


