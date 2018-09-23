/*
		Generate All Possible Expressions That Evaluate To The Given Target Value

		Problem Statement:
		You are given a string s, containing only numerical characters ('0' - '9'). You are also given a non-negative number target.
		You have to put between each pair of numerical characters, one of ("", "*", "+") operators such that the expression you get will evaluate to the target value.

		Putting "" (an empty string) operator between two numerical characters means, that the they are joined (e.g. 1""2 = 12). Also the join can be extended further (e.g. 1""2""3 = 123).

		Precedence of the operators matters. In higher to lower precedence:
		Join ("") > Multiplication ("*") > Addition ("+")

		Input Format:
		There are two arguments.
		1) String s.
		2) Long integer target. 

		Output Format:
		Return array of strings containing ALL possible strings that evaluate to the target value. 
		You need not to worry about the order of strings in your output array. Like for s = "22" and target = 4, arrays ["2+2", "2*2"] and ["2*2", "2+2"] both will be accepted.  
		Any string in the returned array should not contain any spaces. In the above example string "2+2" is expected, other strings containing any space like " 2+2", "2 + 2", "2 +2" etc. will give wrong answer. 

		Constraints:
		1 <= |s| <= 13
		s only contains numerical characters ('0' - '9').
		0 <= target < 10^13
		You have to return ALL possible strings that evaluate to target value.


		Sample Test Cases:
		Sample Input:
		s = "222"
		target = 24

		Sample Output:
		["22+2", "2+22"]

		Explanation:
		1) 22 + 2 = 24 (Here, we put "" operator between the first two characters and then put "+" operator between the last two characters.)
		2) 2 + 22 = 24 (Here, we put "+" operator between the first two characters and then put "" operator between the last two characters.)
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char** 
generate_all_expressions_help(char* s,int len,int s_i,long long int target, int* result_size,char *exp_arr,int exp_arr_i)
{	char exp[] = " *+";
	int i;

	if (s_i >= len-1) {
		for (i=0;i<len;i++) {
			printf("%c",s[i]);
			if (i<len-1) {
				if (exp_arr[i] != ' ') {
					printf("%c",exp_arr[i]);
				}
			}
		}
		printf("\n");
		return NULL;
	}

	for (i=0;i<3;i++) {
		exp_arr[exp_arr_i] = exp[i]; 
		generate_all_expressions_help(s,len,s_i+1,target,result_size,exp_arr,exp_arr_i+1);
				
	}
	return NULL;
}	


char** 
generate_all_expressions(char* s, long long int target, int* result_size) 
{
	int len = strlen(s);
	char *exp_arr = calloc(1,len);
	int s_i=0;
	int exp_arr_i=0;
	
	generate_all_expressions_help(s,len,s_i,target,result_size,exp_arr,exp_arr_i);

	return NULL;
}

int
main ()
{
	int result_size =0;	
	char str[]="123";
	generate_all_expressions(str,12,&result_size); 

}

