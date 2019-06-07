// implemention of atoi function
// atoi = convert sring into integer
// string may contain char,special char(=,+,&,*), integers  etc.

// eg string = "2836sm45d"  OUTPUT--> 283645

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<bits/stdc++.h>
#include<cmath>

using namespace std;


string extractString(string s){
	
	string tmp;
	
	for(int i=0;i<s.length();i++){
		if(int(s[i])>=48 and int(s[i])<=57){
			tmp =  tmp+s[i];
		}
    } 
	
	return tmp;
}
	

int makeAtoi(string s){

	int size = s.length()-1;
	int answer = 0;
	
	
	for(int i=0;i<s.lengtha;i++){
		
		answer = answer + ( (int(s[i])-48)* pow(10,size) );
		cout<<answer<<endl;
		size--;
	}
	
	return answer;
}
		


int main(){
	
	string s;
	cin>>s;
	
	int result = makeAtoi(extractString(s));
	
	cout<<"atoi string: "<<result;
	
	
	
}

