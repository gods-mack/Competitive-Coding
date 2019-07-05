/*
Given a String of length S, reverse the whole string without reversing the 
individual words in it. Words are separated by dots.

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr

*/
// CODE</>

#include <bits/stdc++.h>
#include <cstring>
using namespace std;


void reverseWord(string s,int i){
	stack<char> stack;
	
	while(i!=-2){
	    if(s[i] == '.' or i==-1){   // dot comes pop entire stack string
	    	while(!stack.empty()){
	            cout<<stack.top();
	            stack.pop();
	        }
	       
	       	if(i != -1){
				cout<<".";        // print dot also, when you are not in i=0,i=-1
			}
	    }
	    else{
			stack.push(s[i]);
		}
	   // cout<<s[i]<<" i "<<i<<endl;  // debugging std:: ouput
	    i--;
	    
	}  // end while
	
} // end main operational function
	


int main(){
	
	int T; cin>>T;
	while(T--){
		string s;
		cin>>s;
		int i = s.length() -1;
		reverseWord(s,i);
	}
}
		

