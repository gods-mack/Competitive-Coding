/*

Given two strings a and b. The task is to find if a string 'a' can be
obtained by rotating another string 'b' by 2 places.

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0
*/




#include <iostream>
#include <string.h>
using namespace std;

int main() {
    
    int T;
    cin>>T;
    for(int c=0;c<T;c++)
    {
	    string a ,b;
    	cin>>a;
    	cin>>b;
    	int i =0;
	    while(i<a.size()-1) // start of the bubble sorting
	    {
	       for(int j=0;j<a.size()-1;j++)
	       {
	            char temp;
	            if(a[j]>a[j+1])
	            {
	                temp = a[j];
	                a[j]=a[j+1];
	                a[j+1]=temp;
	            }
	            if(b[j]>b[j+1])
	            {
	                temp = b[j];
	                b[j]=b[j+1];
	                b[j+1]=temp;
	            }
	       }
	       /*for(int j=0;j<a.size();j++)
	       {  cout<<a[j]; }        // for debugging std:: Outputs
	       cout<<endl;
	       for(int j=0;j<a.size();j++)
	       {  cout<<b[j]; }
	       cout<<endl; */  
	       
	       if(a[a.size()-1-i]==b[b.size()-1-i]) // checks for a match
	            i++;
	       else 
	        break; //if there are no matches in the bubble sorting step, we exit the loop
	    } //end of sorting
	    
	    if(i==a.size()-1)
	        cout<<1<<endl;
	    else 
	        cout << 0<<endl;
    }
}
