/*
Given an input stream of N characters consisting only of lower case alphabets. 
The task is to find the first non repeating character, each time a character is inserted to the stream.
If no non repeating element is found print -1.

Example:

Input:
2
4
a a b c
3
a a c

Output:
a -1 b b
a -1 c

*/





#include<bits/stdc++.h>
using namespace std;



void demo(vector<char> &s){
	
    list<char> lis;
	
	  unordered_map<char,list<char>::iterator> map;
	  int freq[26];
	  for(int j =0;j<26;j++){
	      freq[j] = 0;
	  }
	
	  int size = s.size();
	  for(int i = 0;i< size; i++){
		
		    if(map.find(s[i]) == map.end() ) {  //  not find in list
			
		      	if(freq[int(s[i])-int('a')] ==0){   char has freq. zero
				        lis.push_front(s[i]);
				        map[s[i]] = lis.begin();
				        freq[int(s[i])-int('a')]  = freq[int(s[i])-int('a')] + 1;  // increment freq
			      }
			      else{
				        freq[int(s[i])-int('a')]  = freq[int(s[i])-int('a')] + 1;  // increment freq
			      }
				
		    }
        
		    else{
		        if(freq[int(s[i])-int('a')] <=1){   // if repeat erase from list 
				        lis.erase(map[s[i]]);
				         map.erase(s[i]);
            }
			
		    }
        
		    if(lis.empty()){   // list empty return -1
				    cout<<-1<<" ";
			  }
			  else{
		      cout<<lis.back()<<" "; 
	      }
        
	  } // end for loop


} // end of demo func.
		
	
				
// main func			
int main(){
	
        int t; cin>>t;   // test cases
        
        while(t--){
            int n;cin>>n;
            vector<char> s(n);
            for(int i=0;i<n;i++){
				        cin>>s[i];
			      }
            
            
		        demo(s);  // call function
	          cout<<endl;
	    
        }
	    
	 
	
	
}
		
