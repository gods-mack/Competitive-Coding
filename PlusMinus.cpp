

//#include<iostream>
//using namespace std;
#include<stdio.h>
#include<math.h>
int main()
{
   
    int n,l=0,b=0,z=0;

 //cin>>n;
 scanf("%d",&n);
    int a[n];
   for(int i=0;i<n;i++)
{
     scanf("%d",&a[i]);
}
     
       for(int j=0;j<n;j++)
	{
         	if(a[j]<0)
               {
                  l++;
                }
                 if(a[j]>0)
                 {
 			b++;
                  }
                     if(a[j]==0)
 			{
                              z++;
			}
            }

         double minus = l/n;
     double posi = b/n;
  double zero = z/n;
 printf("%.5lf\n",minus);
 printf("%.5lf\n",posi);
 printf("%.5lf\n",zero);


   //cout<<minus<<endl;
   //cout<<posi<<endl;
  // cout<<zero<<endl;
} 
