
// questoin 1
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


string sol(vector<int> a, int n, int index,int ones){

	int i = index ;
	int j ;
	int count = 0;
	if(ones == 1){
		return "YES";
	}
	if(ones != 1 and n < 6){
		return "NO";
	}
	while( i < n){

		j = i + 1;
		while(a[j] != 1 && j < n){
			count++;
			j++;
		}
		//cout<<"count "<<count<<endl;
		if(count < 5 and a[j] == 1){
			//cout<<"this\n";
			return "NO";
		}
		i += count+1;
		count = 0;
		if(i == n-1){
			break;
		}
	}

	return "YES";

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin>>t;

	while(t--){
		int n; cin>>n;
		vector<int> a(n);
		int  f = 0, index;
		int ones = 0;
		for(int i = 0; i < n; i++){
			int x; cin>>x;
			if( x == 1 && f==0){
				f = 1;
				index = i;
				ones++;
			}
			else if(x==1){
				ones++;
			}
			a[i] = x;
		}
		//cout<<"called\n";
		cout<<sol(a,n,index,ones)<<endl;
	}

}