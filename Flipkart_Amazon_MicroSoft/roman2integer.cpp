/* convert a string of roman char. in integer */
// Roman Number to Integer 



#include<iostream>
#include<bits/stdc++.h>

using namespace std;




void inRoman(string s){
	
unordered_map<char,int> hashs;
hashs['I'] = 1;
hashs['V'] = 5;
hashs['X'] = 10;
hashs['L'] = 50;
hashs['C'] = 100;
hashs['D'] = 500;
hashs['M'] = 1000;
	int size = s.length();
	stack<int> stack;
	for(int i=0;i<size; i++){
	        stack.push(hashs[s[i]]);
	}
	int sum = 0;
	int prv = 0;;
	while(!stack.empty()){
		//prv  = stack.top();
		if(prv > stack.top()){
			sum = sum - stack.top();
			prv = stack.top();
			stack.pop();
		}
		else{
			sum = sum + stack.top();
			prv = stack.top();
			stack.pop();
		}
	}
	
	//cout<<"sum "<<sum;
        cout<<sum;
}
			
		
	
int main(){
	int T; cin>>T;
	while(T--){
		string s;
		cin>>s;
		inRoman(s);
		cout<<endl;
	}
}

