
/*
Given two numbers 'N' and 'S' , find the 
largest number that can be formed with 'N' digits and whose
 sum of digits should be equals to 'S'.

 */


#include<bits/stdc++.h>

using namespace std;

void sol(int n,int s){
    
    int sum = s;
    string res = "";
    int dig = 0;
   
    while(dig<n){
        
        for(int i =9; i>=0; i--){
            if(sum>=i){
                dig++;
                sum = sum - i;
                res += to_string(i);
                //cout<<"sum "<<sum<<endl;
                break;
            }
        }
    }
    if(sum==0 and res[0]!='0'){
        cout<<res<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

int main()
{ int t; cin>>t;
    while(t--){
   int n; int s;
   cin>>n>>s;
   
   sol(n,s);
    }
}
