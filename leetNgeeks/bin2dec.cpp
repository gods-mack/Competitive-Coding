


#include<bits/stdc++.h>
using namespace std;

int bin2dec(int n,int p){
//	cout<<"num "<<n<<" "<<p<<endl;

	if(n <= 0){
		return 0;
	}

	return n%10*pow(2,p) + bin2dec(n/10,p+1);	
}

int main(){ 

	int n; cin>>n;
	cout<<bin2dec(n,0);

}