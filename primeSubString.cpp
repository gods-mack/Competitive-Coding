#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;


int isPrime(int num){
    int flag=1;
   if(num!=1)
 { 
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = 0;
          break;
       }
    }
    return flag;
 }
 else
 { 
  return 0;
 }
}

int main()
{
 
 string num;
  cin>>num;

 int count=0;
 int hold;
 for(int i=0;i<(num).length();i++)
 { 
    hold = int(num[i]-'0');
   for(int j=i+1;j<(num).length();j++)
    { 
     //hold = (hold*10)+int(num[j]-'0');
      cout<<"Hold "<<hold<<endl;
       if(isPrime(hold))
       {
           count++;
          cout<<hold<<endl;
       }
        hold = (hold*10)+int(num[j]-'0');
     }
  }


cout<<" Count "<<count<<endl;


}                







      
