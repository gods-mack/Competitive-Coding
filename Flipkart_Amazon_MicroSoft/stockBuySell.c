


#include<iostream>
using namespace std;
int main()
 {
	int t,n,i,min,max,flag;
	cin>>t;
	while(t--)
	{
	cin>>n;
	int a[n+1];
	for(i=0;i<n;i++)
	cin>>a[i];
	
	flag=0;//if solution found flag-->1
    end=1;
    start=0;
    a[n]=0;
	for(i=1;i<=n;i++)
	{
	    if(a[start]>=a[i] && start<i)
	    {
	        end=i;
	        start=i;
	    }
	    else if(a[end]<=a[i] && end<i)  
	        end = i;
	    if(a[end+1]<a[end] && start<end && a[start]< a[end]) //solution found
	        {
	            cout<<"("<<start<<" "<<end<<") ";
	            flag=1;
	            start=end+1;  //initialization to check next case
	            end++;
	        }
	}
	if(flag==0)
	    cout<<"No Profit\n";
	else
    	cout<<"\n";
	}
	return 0;
}
