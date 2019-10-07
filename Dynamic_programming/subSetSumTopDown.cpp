
#include<bits/stdc++.h>
using namespace std;

bool sumSetSum(vector<int> a , int sum, int index){

	if(sum == 0){
		return true;
	}
	if(index == 0 and sum != 0){
		return false;
	}
	if(sum < a[index-1]){ // if last element is grater than sum than igonre ot
		return sumSetSum(a,sum,index-1);
	}
	
	if(sum > 0){
		return sumSetSum(a, sum, index-1) ||  sumSetSum(a, sum-a[index-1],  index-1); 
	}
	
} 

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int sum; cin>>sum;

	if(sumSetSum(a,sum,n)){
		cout<<"yes\n";
	}else{
		cout<<"NO";
	}
}