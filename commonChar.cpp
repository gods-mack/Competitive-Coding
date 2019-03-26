// Given two strings s1 and s2 consisting of lowercase English alphabets,
// the task is to count all the pairs of indices (i, j)
// from the given strings such that s1[i] = s2[j] and all the indices are distinct i.e. if s1[i] 
// pairs with some s2[j] then these two characters will not be paired with any other character.


// Example program
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main()
{ 
     string s1;
     string s2;
     cin>>s1; cin>>s2;
     
      set <char> str1;
      set <char> str2;
      
      set <char> :: iterator itr1,itr2;
     // set <char> :: iterator itr2;
      
      for(int i=0;i<s1.length();i++){
             str1.insert(s1[i]);
      }
     
     for(int i=0;i<s2.length();i++){
             str2.insert(s2[i]);
      }
      
     for (itr1 = str1.begin(); itr1 != str1.end(); ++itr1) 
    { 
        cout << *itr1<<" "; 
    }
    cout<<endl;
      for (itr2 = str2.begin(); itr2 != str2.end(); ++itr2) 
    { 
        cout << *itr2<<" "; 
    }
    cout<<endl;
     int count=0;
     for(itr1 = str1.begin(); itr1 != str1.end(); ++itr1)
     {
         for(itr2 = str2.begin(); itr2 != str2.end(); ++itr2){
              if( *itr1 == *itr2)
              {  cout<<*itr1<< " "<<*itr2<<endl;
                  count++; }
         }
     }
     
     cout<<endl;
     cout<<"output : "<<count;
              
     
  
}
