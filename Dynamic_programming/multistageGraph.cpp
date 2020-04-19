
#include<bits/stdc++.h>
using namespace std;

void shortestPath(vector<int> graph[],int N){

	vector<int> cost(N);
	vector<int> nextNode(N); // for path 

	cost[N-1] = 0;
	nextNode[N-1] = N-1;

	for(int i = N-2; i>=0; i--){

		//cost[i] = INT_MAX;
		int miN = INT_MAX;
		for(int j = 0; j < N; j++){
			if(graph[i][j] > 0 && (graph[i][j]+cost[j] < miN)){
				miN = graph[i][j]+cost[j];
				cost[i] = miN;
				nextNode[i] = j;
			}
		}
	}

	cout<<"cost "<<cost[0]<<endl;
	for(int i = 0; i < N; i++){
		cout<<cost[i]<<" ";	
	}
	/*cout<<endl;
	cout<<0<<" ";
	int prev = 0;
	/*for(int i = 1; i < N; i++){
			if(cost[i] < prev){
				prev = cost[i];
				cout<<i<<" ";
			}
	}
	for(int i = 0; i < N; i++){
		//if(nextNode[i] > prev ){
			cout<<nextNode[i]<<" ";	
			//prev = nextNode[i];
		//}
	}
	cout<<endl;

	for(int i = 0; i < N; i++){
		if(nextNode[i] > prev ){
			cout<<nextNode[i]<<" ";	
			prev = nextNode[i];
		}
	}

	vector<int> path;
	*/



}

int main(){
	int N; cin>>N; //dimension or nodes
	vector<int> graph[N];

	for(int i = 0; i < N; i++){
		graph[i].resize(N);
		for(int j =0; j < N; j++){
			cin>>graph[i][j];
		}
	}
	// fill all diagonal with zero 
	// bacause they represent self loop
	for(int i = 0; i < N; i++){
		graph[i][i] = 0;
	}

	shortestPath(graph,N);
}