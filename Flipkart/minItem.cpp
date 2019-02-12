// Given N buckets, each containing A[i] items. 
//Given K tours within which all of the items are needed to be delivered. 
//It is allowed to take items from only one bucket in 1 tour. 
//The task is to tell the minimum number of items 
//needed to be delivered per tour so that all of the 
//items can be delivered within K tours.
/*
Input : 
N = 5
A[] = { 1, 3, 5, 7, 9 }
K = 10
Output : 3
By delivering 3 items at a time, 
Number of tours required for bucket 1 = 1
Number of tours required for bucket 2 = 1
Number of tours required for bucket 3 = 2
Number of tours required for bucket 4 = 3
Number of tours required for bucket 5 = 3
Total number of tours = 10
*/

// code</> :

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getMin(int buckets,vector<int> item,int tour)
{
 int low = *min_element(item.begin(),item.end());
int high = *max_element(item.begin(),item.end());
cout<<"Low "<<low<<endl;
cout<<"High "<<high<<endl;


int minItem=0;
int tempTour=0;
for(int i=low; i<=high; i++)  
{ tempTour=0;
 
  for(int j=0;j<buckets; j++)
 {
  if(item[j]% i != 0)
  {             // Not Perfectly Divisible means required 
                // tours are Floor Division + 1 
    tempTour = tempTour + (item[j]/i) + 1;
   }
  else
  { // prefectly Division 
    tempTour = tempTour + (item[j]/i);
   }
  }
 cout<<"Temp Tour percycle "<<tempTour<<endl;
 if(tempTour <= tour) 
 { cout<<"Minimum Item to be delivered is "<<i<<endl;
   break;
  }

 }

}

int main() {

int buckets; cin>>buckets;
vector<int> item(buckets);
for (int i=0;i<buckets; i++)
 { cin>>item[i]; }

int tour; cin>>tour;

getMin(buckets, item, tour);
}










