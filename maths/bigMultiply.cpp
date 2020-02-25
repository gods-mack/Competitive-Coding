

// large multiplication

#include<bits/stdc++.h>
using namespace std;


void largeMultiplication(string s1, string s2){

	if(s1.length() < s2.length()){
		string tmp; tmp = s1;
		s1 = s2;
		s2 = tmp;

	}

	int num1[s1.length()];
	int num2[s2.length()];
	int maxlen = s1.length() + s2.length();
	int mul[maxlen + 1];
	memset(mul,0,sizeof(mul));

	for(int i = 0; i < (int)s1.length(); i++){
		num1[i] = s1[i] - '0';
	}
	for(int i = 0; i < (int)s2.length(); i++){
		num2[i] = s2[i] - '0';
	}

	int h = 0; // horizontal gap on simple multiplication

	int indx = 0;
	for(int i=s2.length()-1; i>=0; i--){

		indx = 0; indx += h;
		for(int j=s1.length()-1; j>=0; j--){
			mul[indx] += num2[i]*num1[j];
			//cout<<mul[indx]<<" ";
			indx++;
		}
		//cout<<endl;
		h++;
	}
	cout<<endl;

	for(int i = 0; i < maxlen; i++){
		mul[i+1] += mul[i]/10;
		mul[i] = mul[i]%10;
	}
	

	int flag = 0;
	string ans = "";
	for(int i = maxlen-1; i>=0; i--){
		if(mul[i] != 0 and flag==0){ // skip left side zeros
			flag = 1;
			cout<<mul[i];
			
		}
		else if(flag){
			cout<<mul[i];
		}
	}

	cout<<ans;

}

int main(){
	string s1;
	string s2;
	cin>>s1>>s2; // two numbers 

	largeMultiplication(s1,s2);
}