
// large sum, where even 64bit integer type cant handle


#include<bits/stdc++.h>
using namespace std;

void largeSum(string a,string b){
	int maxlen;
	if( a.size() > b.size() ) { maxlen = a.size();  }
	else {	maxlen = b.size(); }

	int l1 = a.size();
	int l2 = b.size();
	//vector<int> num1[l1];
	//vector<int> num2[l2];
	int num1[l1];
	int num2[l2];
	int sum[maxlen+1];
	memset(sum,0,sizeof(sum));
	
	for(int i = 0; i < l1; i++){
		num1[i] = a[l1-i-1] - '0' ;
	}
	for(int i = 0; i < l2; i++){
		num2[i] = b[l2-i-1] - '0' ;
	}
	
	for(int i = 0; i < maxlen; i++ ){
		sum[i] = num1[i] + num2[i];	
		cout<<sum[i]<<endl;
		if(sum[i] > 19 or sum[i]<-19){
			sum[i] = 0;
		}
	}

	for(int i = 0; i < maxlen; i++){
		sum[i+1] += sum[i]/10;
		sum[i] = sum[i]%10;
	}

	string ans ="";
	if(sum[maxlen] == 1){  ans += to_string(1); }
	for(int i = 0; i < maxlen; i++ ){
		ans += to_string(sum[maxlen-i-1]);
	}
	cout<<ans;
	


}

int main(){
	string a; string b;
	cin>>a>>b;

	largeSum(a,b);
}