
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// convert a decimal fraction number into binary string with k decimal places


void decimal2binary(double num,int k){
	int integer = num;
	float frac = num - integer;  // split integer part and fraction part
	string binary;
	
	while(integer > 0){
		int res = integer % 2;
		binary.push_back(res + '0');
		integer /= 2;
	}
	reverse(binary.begin(),binary.end()); // reverse string
	binary.push_back('.');
	
	while(k--){
		frac = frac * 2;
		int res = frac;
		if(res==1){
			binary.push_back(1 + '0');
			frac = frac - res;
		}
		else{
			binary.push_back(0 + '0');
		}
		
	}
	cout<<"binary number: "<<binary<<endl;
	
}//  end of function
	

int main(){
	double number;
	cin>>number;
	int k; cin>>k; // decimal place
	decimal2binary(number,k);
	
	
	
}










	
