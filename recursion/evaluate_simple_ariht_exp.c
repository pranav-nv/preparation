
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define DEBUG 1
long long int
eval_exp(char *s)
{
	char *s_work = s;	
	long long int num[10];	
	char exp[10]={0};
	int i=0,j=0;
	int num_count=0;
	char *ptr;

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
#if DEBUG
	for (i=0;i<num_count;i++) {
		printf("%d : %d\n",i,num[i]);
		printf("\t%c\n",exp[i]);
	}
#endif
	long long int res = 0; 
	for (i=0;i<num_count;i++) {
		if (exp[i] && (exp[i] == '*' || exp[i] == '/')) {
				if (exp[i] && exp[i] == '*') {
					res = num[i] * num[i+1];		
				} 
				else if (exp[i] && exp[i] == '/') {
					res = num[i] / num[i+1];		
				}
				printf("%d%c%d = %d\n",num[i],exp[i],num[i+1],res);
				num[i+1] = res;
				j = i;
				while (j >= 0) {
					if (exp[j] == '*' || exp[j] == '/') {
						num[j] = res;
						j--;
					} else {
						break;
					}
				}
		}
	}
#if DEBUG
	for (i=0;i<num_count;i++) {
		printf("%d : %d\n",i,num[i]);
	}
#endif
	
	for (i=0;i<num_count;i++) {
		if (exp[i] && (exp[i] == '+' || exp[i] == '-')) {
				if (exp[i] && exp[i] == '+') {
					res = num[i] + num[i+1];		
				} else if (exp[i] && exp[i] == '+') {
					res = num[i] - num[i+1];		
				}
				printf("%d%c%d = %d\n",num[i],exp[i],num[i+1],res);
				num[i+1] = res;
				j = i;
				while (j >= 0) {
					if (exp[j] == '-' || exp[j] == '+') {
						num[j] = res;
						j--;
					} else {
						break;
					}
				}
		}
	}
#if DEBUG
	for (i=0;i<num_count;i++) {
		printf("%d : %d\n",i,num[i]);
	}
#endif
	printf("res = %d\n",res);
	return res;	
}


int 
main()
{
	long long int ret;	
	//ret = eval_exp("1*2*3+4*5");
	ret = eval_exp("1+5*2*3+4*5");
	//ret = eval_exp("123");
	printf("ret = %d\n",ret);
}
