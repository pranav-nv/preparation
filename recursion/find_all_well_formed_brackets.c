/*
		Find All Well Formed Brackets

		Problem Statement:
		Given positive integer n, find all well formed round brackets of length 2n.

		Input Format:
		There is only one argument denoting integer n.

		Output Format:
		Return array of strings containing all possible well formed round brackets of length 2n (Length of each string will be 2n). 

		You need not to worry about the order of strings in your array. Like for n = 2, ["(())", "()()"] or ["()()", "(())"], both will be accepted.

		Constraints:

		1 <= n <= 13
		Only use round brackets. '(' and ')'.
		Need to find ALL well formed brackets possible. 


		Sample Test Case:

		Sample Input:
		3

		Sample Output:

		[

		  "((()))",

		  "(()())",

		  "(())()",

		  "()(())",

		  "()()()"

*/

#include "stdio.h"
#include "stdlib.h"

int total_count = 0;

void
find_all_well_formed_brackets_helper(int n,char *out_str,int index,int op,int cl)
{
	if (index >= (2*n)) {
		total_count++;
		printf("\t %d==> %s\n",total_count,out_str);
		return;
	}
	 
	if (op < n)	{
		out_str[index] = '(';		
		find_all_well_formed_brackets_helper(n,out_str,index+1,op+1,cl);
	}
	
	if (op>cl) {
		out_str[index] = ')';		
		find_all_well_formed_brackets_helper(n,out_str,index+1,op,cl+1);
	}	
}

void
find_all_well_formed_brackets(int n)
{
	char *out_str=malloc((2*n) +1);
	find_all_well_formed_brackets_helper(n,out_str,0,0,0);
	free(out_str);
}


int 
main()
{
	find_all_well_formed_brackets(4);
	return 0;
}

