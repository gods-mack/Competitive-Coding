/*
Given an array arr[] of size N. The task is
 to find the first repeating element in an array of 
 integers, i.e., an element that occurs more than
 once and whose index of first occurrence is smallest.

 */




#include<bits/stdc++.h>
using namespace std;

void sol(vector<int> &a){
	set<int> s;
	int miN = INT_MAX; 
    int flag = 1;

    for(int i = a.size()-1; i >= 0; i--){

    	if(s.find(a[i]) != s,end() ){
    		min = i + 1;
    		flag = 0;
    	}
    	else{
    		s.insert(a[i]);
    	}
    }
    if(flag){
    	cout<<-1<<endl; // no elemnt is repeated
    }
    else{
    	cout<<miN<<endl;
    }
          
}

int main(){
    int t; cin>>t;
    
    while(t--){
    
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        
        sol(a);
    }
    
    
    
}