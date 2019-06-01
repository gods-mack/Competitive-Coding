

#include<iostream>
using namespace std;

int main(){
	
	int a = 10;
	int *p = &a;
	
	int **pt;
	pt = &p;
	
	int b =13;
	
	//*pt = &b;// equal => *pt = &b, but we cant change value of a
	**pt  = b; // value of a is changed by 13
	
	cout<<" *pt pt &pt "<<*pt<<" "<<p<<" "<<&pt<<endl;
	cout<<*p<<" "<<**pt<<" "<<a;
}
