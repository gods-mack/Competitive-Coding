/*
Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

*/




#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void parenthesisChecker(char *s){
        
        stack<char> stack;
       // int string_size = s.length();
        int flag = 1 , i = 0;
        
        while(s[i]!='\0'){
                
                if(s[i]=='[' or s[i]=='(' or s[i]=='{' ){
                        stack.push(s[i]);
                }
                else{
                        if(!stack.empty() and (s[i]==']' and stack.top()=='[') or (s[i]==')' and stack.top()=='(' ) or (s[i]=='}' and stack.top()=='{')){
                                stack.pop();
                        }
                        else{
                                flag = 0;
                                break;
                        }
                        
                }
                i++;
        }
        
        if(flag==1 and stack.empty()){
                cout<<"balanced\n";
        }
        else{
                cout<<"not balanced\n";
                //stack.clean();
        }

        
}

int main(){
        
        int t; cin>>t; // testCase
        while(t--){
                string s;
                cin>>s;
                
                parenthesisChecker(&s[0]);
        }
        
}
