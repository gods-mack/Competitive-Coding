

// http://codeforces.com/contest/25/problem/D

#include<bits/stdc++.h>
using namespace std;


int parent[1010];
//int rankk[1010];

struct edge {
	int x; int y;
};

struct edge add_edge[1010],build_edge[1010];

void make_set(int v) {
	parent[v] = v;
	//rankk[v]  = 0;
}

int find_set(int v) {
	if(parent[v] == v){
		return v;
	}
	parent[v] = find_set(parent[v]);
	return parent[v];
}

void union_set(int x,int y){
	int a = find_set(x);
	int b = find_set(y);
	parent[a]  = b;
}

int main() {
	for(int i = 0; i < 1010; i++) {
		parent[i] = i;
		//rankk[i] = 0;
	}
	int n; cin>>n;
	//vector<pair<int,int>> add,build;
	int ind = 0;

	for(int nn = 0; nn < n-1; nn++) {
		int x; cin>>x;
		int y; cin>>y;
		int rx = find_set(x);
		int ry = find_set(y);

		if(rx == ry){
			add_edge[ind].x = x;
			add_edge[ind].y = y;
			ind++;

 		}
		else{
			union_set(rx, ry);
		}
	}

	
	/*cout<<"#\n";
	for(int i = 0; i < 8; i++) {
		cout<<parent[i]<<" ";
	}*/
	//cout<<endl;
	ind = 0;
	int r_1 = find_set(1);
	for(int i = 2; i < n-1; i++ ){
		if(r_1 != find_set(i)){
			//cout<<"i "<<i<<" "<<find_set(i)<<endl;
			build_edge[ind].x  = r_1;
			build_edge[ind].y  = find_set(i);
 			union_set(find_set(i),r_1);
 			ind++;
		
		}
		
	}

	//cout<<"size "<<ind<<endl;
	cout<<ind<<endl;
	for(int i = 0; i < ind; i++) {
		cout<<add_edge[i].x<<" "<<add_edge[i].y<<" "<<	build_edge[i].x<<" "<<build_edge[i].y<<endl;
	}



}