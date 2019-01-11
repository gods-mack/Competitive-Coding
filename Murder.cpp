/* Once detective Saikat was solving a murder case. 
While going to the crime scene he took the stairs and saw that a number is written on every stair.
 He found it suspicious and decides to remember all the numbers that he has seen till now. 
While remembering the numbers he found that he can find some pattern in those numbers. 
So he decides that for each number on the stairs 
he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. 
Calculate the sum of all the numbers written on his notes diary.

input:
5
1 5 3 6 4
output:
15

*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{

int t;
cin>>t;

for(int i=0;i<t;i++)
{
 int n;
 cin>>n; long long  sum=0;

 vector<long long> a(n);
 
 for(int i=0;i<n;i++)
 { cin>>a[i]; }
  

 for(int i=0;i<n;i++)
 {
   for(int j=i;j>=0;j--)
    {
      if(a[i]>a[j])
       { sum=sum+a[j]; }
     }
  }


cout<<sum;

}


}


      










 









