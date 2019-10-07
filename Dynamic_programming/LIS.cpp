
// longest increasing subsequence

#include<iostream>
#include<cstdio>
using namespace std;


int LIS(int a[], int n){

	int tmp[n];
	tmp[0] = 1;
	int ans = 1;
	for(int i = 1; i < n; i++){
		tmp[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[i] > a[j] and tmp[i] < tmp[j] + 1){
				tmp[i] = tmp[j] + 1;
				if(ans < tmp[i]){
				    ans = tmp[i];
				}
			}
		}
	}

	return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    	int n;
    	scanf("%d",&n);
    	int a[n];
    	for(int i = 0; i < n; i++){
    	    scanf("%d",&a[i]);
    	}

    	cout<<LIS(a,n)<<endl;
    }
}
