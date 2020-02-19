
// // 17A- noldbach problem [codeforeces]
#include<bits/stdc++.h>
using namespace std;




string sol(int n, int k){

	if(k == 0){	return "YES";	}

	bool primeTable[n+1];
	memset(primeTable,true,sizeof(primeTable));
	primeTable[0] = primeTable[1] = false;

	for(int i = 2; i*i<=n; i++){
		if(primeTable[i] == true){
			for(int j = i*i; j <= n; j+=i){
				primeTable[j] = false;
			}
		}
	}

	vector<int> table;
	for(int p = 2; p <=n; p++){
		if(primeTable[p]){
			table.push_back(p);
		}
	}

	//for(auto x:table){ cout<<x<<" "; } cout<<endl;
	
	int counter = 0;
	int flag = 1;
		
	for(int i = 0; i < table.size()-1; i++){
		int x = table[i];
		int y = table[i+1];
		int num = x+y+1;
		if(primeTable[x] and primeTable[y]){
			if(num<=n && primeTable[num]){
				//cout<<x<< " "<<y<<endl;
				counter++;
			}
			if(counter >= k){
				return "YES";
			}
		}
						

	}
	
	return "NO";
}

int main(){
	int n; int k;
	cin>>n>>k;

	cout<<sol(n,k);

}