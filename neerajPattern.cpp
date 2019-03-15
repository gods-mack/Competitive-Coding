// when Enter : 7   AMCAT
// 11111112
// 32222222
// 33333334
// 54444444
// 55555556
// 76666666
// 77777778

// when Enter : 2
// 112
// 322

#include<iostream>
#include<cmath>
using namespace std;

int main(){
 int n;
 cin>>n;

int count=1;
int next;
for(int i=1;i<=n;i++){    // run (i) untill n+1
  
  
   
    if(i%2==0){     // on even postion of (i) pattern skewed towards left
     cout<<next+1;
      for(int j=1;j<=n;j++){
        cout<<next; 
         }
    count=next+1;
    }
   else{
     for(int j=1;j<=n;j++){
       cout<<count; 
     }
     next=count+1;
     cout<<next;
    }
  
cout<<"\n";
}

}
     






   
