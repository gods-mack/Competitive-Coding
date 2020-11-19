
//  Find Missing And Repeating 
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
#include<bits/stdc++.h>
using namespace std;

int* sol(vector<int> &a, int n) {

	int missing,repeating;
	//int *ans = new int[2];
	//int *ans ;
	static int ans[2];


	for(int i = 0; i < n; i++) {

		if(a[a[i]-1] > 0) {
			a[a[i]-1]  *= -1;
		}
		else{
			repeating = a[i];
		}
	}



	cout<<"repeating "<<abs(repeating)<<endl;

	for(int i = 0; i < n; i++) {
		if(a[i] > 0) {
			missing = i + 1;
			cout<<"missing "<<i+1<<endl;
			break;
		}
	}
	ans[0] = abs(repeating);
	ans[1] = missing;
		


	//int *p = &ans;
	return ans;

}

int main() {
	int n; cin>>n;
	vector<int> a(n);

	for(auto &x:a) {
		cin>>x;
	}

	
	int *ans = sol(a,n);	

	cout<<ans[0] << " "<< ans[1]<<endl;


}