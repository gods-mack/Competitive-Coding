//when Enter : 3
// 333
// 313
// 323
// 333

//when Enter : 5
// 55555
// 55155
// 55255
// 55355
// 55455
// 55555


#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int midCount=1;

for(int i=1;i<=n+1;i++)
{

    if(i==1){
        for (int j=1;j<=n;j++){
           cout<<n;
        } 
    }
  
 
    else {

          for(int k=1;k<=n;k++){ 
     
             if(k!=(n+1)/2){
                cout<<n;
             }
             else{ 
               cout<<midCount;
               midCount += 1;
     
             }
          }    
     }
 cout<<"\n";
}

} //End main
 





  
 

