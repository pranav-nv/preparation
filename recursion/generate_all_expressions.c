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


long long int
eval_exp(char *s)
{
	char *s_work = s;	
	long long int num[10];	
	char exp[10]={0};
	int i=0;
	int num_count=0;
	char *ptr;
	long long int res = 0; 

	while (*s_work != 0) {
		num[num_count] = strtol(s_work,&ptr,10);
		exp[num_count] = *ptr;
		num_count++;
		if (*ptr == 0) {
			break;
		}
		s_work = ptr+1;
	}
	
	if (num_count == 1) {
		return num[0];
	}
	if (num_count == 0) {
		return 0;
	}
	
	for (i=0;i<num_count;i++) {
		if (exp[i] && (exp[i] == '*' || exp[i] == '/')) {
				if (exp[i] && exp[i] == '*') {
					res = num[i] * num[i+1];		
				} 
				else if (exp[i] && exp[i] == '/') {
					res = num[i] / num[i+1];		
				}
				num[i+1] = res;
				num[i] = res;
		}
	}
	
	for (i=0;i<num_count;i++) {
		if (exp[i] && (exp[i] == '+' || exp[i] == '-')) {
				if (exp[i] && exp[i] == '+') {
					res = num[i] + num[i+1];		
				} else if (exp[i] && exp[i] == '+') {
					res = num[i] - num[i+1];		
				}
				num[i+1] = res;
				num[i] = res;
		}
	}
	return res;	
}

void
generate_all_expressions_help(char* s,int len,int s_i,long long int target, int* result_size,char *exp_arr,int exp_arr_i,char exp_arr_list[][128])
{	char exp[] = " *+";
	int i;
	long long int ret;

	if (s_i >= len-1) {
		char cur_exp[128]={0};
		char *cur_exp_p = cur_exp;
		for (i=0;i<len;i++) {
			sprintf(cur_exp_p++,"%c",s[i]);
			if (i<len-1) {
				if (exp_arr[i] != ' ') {
					sprintf(cur_exp_p++,"%c",exp_arr[i]);
				}
			}
		}	
		*cur_exp_p = 0;
		//ret = eval_exp(cur_exp);
		printf ("%s = %lld\n",cur_exp,ret);
		if (ret == target) {
			strcpy(exp_arr_list[*result_size],cur_exp); 
			(*result_size)++;
		}
	}

	for (i=0;i<3;i++) {
		exp_arr[exp_arr_i] = exp[i]; 
		generate_all_expressions_help(s,len,s_i+1,target,result_size,exp_arr,exp_arr_i+1,exp_arr_list);
				
	}
}	


char exp_arr_list[128][128]={0};

char** 
generate_all_expressions(char* s, long long int target, int* result_size) 
{
	int len = strlen(s);
	char *exp_arr = calloc(1,len);
	int s_i=0;
	int exp_arr_i=0;
	int i;

	generate_all_expressions_help(s,len,s_i,target,result_size,exp_arr,exp_arr_i,exp_arr_list);
	
	printf("*result_size = %d\n",*result_size);

#if 0
	for (i=0;i<*result_size;i++) {
		printf("%s = %lld\n",exp_arr_list[i],target);
	}
#endif	
	return (char **)exp_arr_list;
}

int
main ()
{
	int result_size =0;	
	char str[]="123";
	generate_all_expressions(str,12,&result_size); 

}

