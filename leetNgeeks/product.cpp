
// multiple two number without using * and  / operator
// you can use +,-,bit shifting

#include<bits/stdc++.h>
using namespace std;



int product(int smaller,int bigger) {
	if(smaller == 0) {
		return 0;
	} 
	if(smaller == 1) {
		return bigger;
	}

	int div  = smaller >> 1; // divide by 2

	if(smaller%2 == 0){
		int res = product(div,bigger);
		return res + res;

	}
	else{
		int res= product(div,bigger);
		return res+res+bigger;
	}
}

int main() {
	int a,b;
	cin>>a>>b;
	int small = a < b ? a:b;
	int big = a < b ? b:a;

	cout<<product(small,big);

}