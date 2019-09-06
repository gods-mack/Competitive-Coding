
/*
GEEDY PROBLEM:
Given N activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person,
 assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.
Example:
Input:
2
6
1 3 2 5 8 5
2 4 6 7 9 9
4
1 3 2 5
2 4 3 6

Output:
4
4

*/

#include<bits/stdc++.h>
using namespace std;

struct activity{
	int start;
	int end;
};

bool cmp(struct activity a, struct activity b){
	return a.end < b.end;
}

int getMaxActivity(struct activity arr[],int n){
	sort(arr, arr+n, cmp);

	int count = 0;
	int prvEnd ;
	for(int i = 0; i < n; i++){
		if(i == 0){
			count++;
			prvEnd = arr[i].end;
		}
		else{
			if(arr[i].start >= prvEnd){
				count++;
				prvEnd = arr[i].end;
			}
		}
	}
    
    return count;
}

int main(){
	int T; cin>>T;
	while(T--){
		int n;
		cin>>n;
		struct activity arr[n];
		for(int i = 0; i < n; i++){
			int st;
			cin>>st;
			arr[i].start = st;
		}
		for(int i = 0; i < n; i++){
			int en;
			cin>>en;
			arr[i].end = en;
		}
		cout<<getMaxActivity(arr,n)<<endl;
	}
}
