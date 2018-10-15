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
printSubsets(int *arr,int len, int j, int *s, int k)
{
	if (j >=len-1) {
		printArr(s,k);
		return;
	}
	
	printSubsets(arr,len,j+1,s,k);
	s[k] = arr[j];
	printSubsets(arr,len,j+1,s,k+1);
}


void
printSubsetsMain(int *arr, int len)
{
	int *s = malloc(sizeof(int)*len);	
	printSubsets(arr,len,0,s,0);
	free(s);
}

int 
main()
{
	int arr[]={1,2,3,4,5,6,7};
	printSubsetsMain(arr,sizeof(arr)/sizeof(int));
}


/*

																				[1 2 3 4]
[1]		| 						  [2 3 4]											|									[]  [2 3 4]
[1]		| 				[2] [3 4]        [] [3 4]									|
		|																			|
 		|  [2] 	|	[3][4]				[3][4]    [][4]								|
		| 		|
		| 		|
		| 		|
		|
		|
		|
		|
		|
		|
		|
		|












   */
