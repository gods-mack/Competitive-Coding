

/*
Given three increasingly sorted arrays A, B, C of sizes N1, N2, and N3 respectively, 
you need to print all common elements in these arrays.

Note: Please avoid printing the same common element more than once.

Example:
Input:
1
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
Output:
20 80

*/

#include<bits/stdc++.h>
using namespace std;



int common_elements(std::vector<int> a, std::vector<int> b, std::vector<int> c){
	
	map<int,int> has1;
	map<int,int> has2;
	map<int, int> has3;
	for(auto x : a){
			has1[x]++;
	}
	for(auto x : b){
			has2[x]++;
	}
	for(auto x : c){
			has3[x]++;
	}
	
	int flag = -1;	
	
	
		//cout<<" first " <<endl;
		for(auto it = has1.begin(); it != has1.end(); ++it){
			if(has2.find(it->first) != has2.end() and has3.find(it->first) != has3.end() ){
				cout<<it->first<<" ";
				flag = 1;
			}
		}
	
	
	if(flag == -1){
		cout<<flag<<" ";
	}



}

int main(){
	int T; cin>>T;

	while(T--){
		int n1,n2,n3; cin>>n1>>n2>>n3;
		std::vector<int> a(n1);
		std::vector<int> b(n2);
		std::vector<int> c(n3);
		for(int i = 0; i < n1; i++){
			cin>>a[i];
		}
		for(int i = 0; i < n2; i++){
			cin>>b[i];
		}
		for(int i = 0; i < n3; i++){
			cin>>c[i];
		}

		common_elements(a,b,c);
        cout<<endl;
	}

}
