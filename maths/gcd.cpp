
#include<bits/stdc++.h>
using namespace std;

int gcd_recursion(int a,int b){
	if(a==0){
		return b;
	}
	gcd_recursion(b%a,a);
}

int GCD_division(int a, int b){ //  Great Common Divisor function with division.
    
    int t;
    while( b != 0 ){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
    
}

int GCD_substitution(int a, int b){ //  Great Common Divisor function with substitution.
    
    while(a != b){
        if(a > b){
            a = a-b;
        }else{
            b = b-a;
        }
    }
    return a;
    
}

int LCM(int a,int b){
	return abs(a*b)/gcd_recursion(a,b);
}

int main(){
	int a,b;
	cin>>a>>b;

	cout<<gcd_recursion(a,b)<<endl;
	cout<<LCM(a,b);
}