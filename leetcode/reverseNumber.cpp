

#include<bits/stdc++.h>
using namespace std;

int rev(int n){	

	int rev_num = 0;
	int prv_rev = 0;
	while(n > 0){
		int curr_digit = n%10;
		rev_num = rev_num*10  + (n%10);

		if((rev_num - curr_digit)/10 != prv_rev){ // OVEFLOW 32bit
			cout<<"rev num "<<rev_num<<endl;
			return -1;
		}
	
		prv_rev = rev_num;
		n = n / 10;	
	}
	return rev_num;
}

int reverseNumber(int n){
 
 	if(n < 0){
 		
 		int res = rev(abs(n));
 		if(res < 0){  // OVERFLOW
 			return 0;
 		}

 		return (0-res);

 	}
	else{
		int res = rev(n);
		if(res < 0){  // OVERFLOW
			return 0;
		}

		return res;
	}
}

int main(){
	int n;
	cin>>n;

	cout<<reverseNumber( n);
}