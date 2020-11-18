

// sumarray sun
#include<bits/stdc++.h> 
using namespace std; 


void sol( vector<int> a,int sum) {

	int n = a.size();

	for(int i = 0; i < n; i++) {
		int tmp = 0;
		for(int j = i; j < n; j++){
			tmp += a[j];
			if(tmp == sum){
				cout<<"fount "<<i<<" " <<j<<endl;
				i = n + 1;
				break;
			}
		}

	}
}



// eeficient
void sol2(vector<int> a, int sum ){

	int n = a.size();
	unordered_map<int,int> mp;

	int tmp = 0;
	for(int i = 0; i < n; i++) {
		tmp += a[i];
		mp[tmp] = i;
		//cout<<tmp <<" "<<i<<endl;
	}

	int curr_sum = 0;
	for(int i = 0; i < n; i++) {

		curr_sum += a[i];
		if(curr_sum == sum ){
			cout<<1<<"- "<<i+1<<endl;
			break;
		}

		if(mp.find((curr_sum-sum)) != mp.end()){
			cout<<mp[(curr_sum-sum)]+2<<" "<<i<<endl;
			break;
		}
	}	
}

int main() {
	
	int n; cin>>n;
	vector<int> a(n);

	for(int i = 0; i  < n; i++) {
		cin>>a[i];

	}

	int sum ; cin>>sum;


	sol2(a,sum);

}