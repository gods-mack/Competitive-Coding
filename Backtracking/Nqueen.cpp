
// N queen problem using backtracking

#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int> > board, int row, int col, int N ){

	for(int i = col; i >= 1; i--){
		if(board[row][i] == 1){
			return false;
		}
	}

	for(int i  = row, j = col; i >= 0 and j>=0; i--, j--){   // Check upper diagonal on left side 
		if(board[i][j] == 1){
			return false;
		}
	}

	for(int i = row, j = col , j >= 0 and i < N; i++, j--){    // Check lower diagonal on left side 
		if(board[i][j] == 1){
			return false;
		}
	}

	return true;

}

void Nqueen(vector<vector<int> > board, int N,int col){

	if(col >= N){

	}

	for(int i = 1; i <=N; i++){
		if(isSafe(board,i,col)){
			board[i][col]  = 1;
			Nqueen(board, N, col+1)
		}

		else{  // backtracking
			Nqueen(board, N, col-1);
		}
	}
}

int main(){
	int N;
	cin>>N; // chess dimension

	vector<vector<int> > board(N+1);
	Nqueen(board,N);
}