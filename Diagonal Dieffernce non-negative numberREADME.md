


#include<iostream>
#include<cmath>

using namespace std;
int main()
{
  int a[3][3];
  for(int i=0;i<3;i++)
  {
	  for(int j=0;j<3;j++)
	  {
		   cin>>a[i][j];
	   }
	   
	  }
	  
	  int val1=0,val2=0,k=0,l=2;
	  for(int g=0;g<3;g++)
	  {
		   val1 += a[g][g];
	   }
	 
	   while(k<3 && l>=0)
	   {
		    
		    
		
			 val2 += a[k][l];
		 
		 k++;
		 l--;
	   }
	 
		 
			 int dif = val1-val2;
			 cout<<"final : "<<fabs(dif)<<" "<<dif;;
	}		
			 
			   
 
