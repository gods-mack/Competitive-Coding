

#include<stdio.h>

int add(int a,int b){ return a+b; }
int mul(int a,int b){ return a*b; }

int do_oper(int (*op)(int,int), int a, int b){
	return op(a,b);
}

int main(int args, char **argv){
	int res = do_oper(add,3,4);
	printf("%d\n",res);

	int res1 = do_oper(mul,2,4);
	printf("%d\n",res1);
}