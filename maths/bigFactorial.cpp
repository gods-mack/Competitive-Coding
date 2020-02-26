// https://www.hackerrank.com/challenges/extra-long-factorials/problem?h_r=internal-search
// big number factorial 

#include<bits/stdc++.h>
#define MAX 10000
using namespace std;


void bigFactorial(int n){
	
	int a[MAX];
	int q = 2;
	int x = 0;
	int num = 0;
	int len = 1;
	a[0] = 1;
	while(q<=n){

		x  = 0;
		num = 0;
		while(x<len){
			a[x] = a[x]*q;
			a[x] = a[x] + num;
			num  = a[x]/10;
			a[x] = a[x]%10;
			x++;
		}
		while(num!=0){
			a[len] = num%10;
			num = num/10;
			len++;
		}

		q++;
	}
	len  = len-1;
	//cout<<len;
	while(len>=0){
		cout<<a[len];
		len--;
	}

}

int main(){
	int n;
	cin>>n;

	bigFactorial(n);
}